/*It_mumu*/
#include <stdio.h>
#define NUM 100  //物品的数量上限
#define CAP 100  //背包容量上限
int V[NUM][CAP]; //用于递归的数组
int x[NUM];      //存放那些装入，那些未装入的信息

/**
 * 求最大值函数
 * */
int max(int a, int b)
{
    int c = a;
    if (a >= b)
        c = a;
    else
        c = b;
    return c;
}

void KnapSack(int n, int w[], int v[], int x[], int C)
{
    int i, j;
    for (i = 0; i <= n; i++) //初始化列
        V[i][0] = 0;
    for (j = 0; j <= C; j++) //初始化行
        V[0][j] = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= C; j++)
        {
            if (j < w[i])
            {
                V[i][j] = V[i - 1][j];
            }
            else
            {
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    j = C;
    for (i = n; i >= 1; i--)
    {
        if (V[i][j] > V[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        else
        {
            x[i] = 0;
        }
    }
    printf("I have choosed the something are:");
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            printf("{");
        }
        printf("%d", x[i]);
        if(i!=n){
            printf(",");
        }
        if (i == n)
        {
            printf("}");
        }
    }
    printf("\n");
}

int main()
{
    int n = 4;
    int w[] = {0, 5, 3, 4, 7};
    int v[] = {0, 1, 9, 10, 6};
    int C = 10;
    KnapSack(n, w, v, x, C);
    printf("求解的过程如下:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= C; j++)
        {
            printf("%4d ", V[i][j]);
            if (j % 10 == 0)
                printf("\n");
        }
    return 0;
}