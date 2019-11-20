#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 100

int c[num][num];
int b[num][num];

int max(int a, int b)
{
    int c;
    if (a > b)
        c = a;
    else
        c = b;
    return c;
}

int LCSLength(char x[], char y[], int i, int j) // 求最长公共子系列的长度递归算法
{
    if (i == 0 || j == 0)
        return 0;
    if (x[i] == x[j])
        return LCSLength(x, y, i - 1, j - 1) + 1;
    else
        return max(LCSLength(x, y, i - 1, j), LCSLength(x, y, i, j - 1));
}

void LCSLength(int m, int n, char x[], char y[])
{ //求公共子系列长度的动态化算法
    int i, j;
    for (i = 1; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        c[0][i] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i] == y[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
    }
}
void LCS(int i, int j, char X[])//因为X才是从下往上的，所以传入的是X的数组获取最长公共子系列
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (b[i][j] == 1)
    {
        LCS(i - 1, j - 1, X);
        printf("%c ", X[i]);
    }
    else if (b[i][j] == 2)
        LCS(i - 1, j, X);
    else
        LCS(i, j - 1, X);
}

int main()
{
    int i, j;
    char x[] = {'0', 'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char y[] = {'0', 'B', 'D', 'C', 'A', 'B', 'A'};
    LCSLength(7, 6, x, y);
    for (i = 1; i <= 7; i++)
        for (j = 1; j <= 6; j++)
        {
            printf("%d", b[i][j]);
            if (j % 6 == 0)
                printf("\n");
        }
    LCS(7, 6, x);
    return 0;
}