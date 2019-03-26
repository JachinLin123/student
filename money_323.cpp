#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float max, min;

float fmax, fmin;

float a[100];

void maxmin1(float a[], int n)
{
    max = a[1];
    min = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (max < a[i])
            max = a[i];
        else if (min > a[i])
            min = a[i];
    }
}

void maxmin2(int i, int j, float &fmax, float &fmin)
{
    int mid;
    float lmax, lmin, rmin, rmax;
    if (i == j)
    {
        fmax = a[i];
        fmin = a[i];
    }
    else if (i == j - 1)
    {
        if (a[i] < a[j])
        {
            fmax = a[j];
            fmin = a[i];
        }
        else
        {
            fmax = a[i];
            fmin = a[j];
        }
    }
    else
    {
        mid = (i + j) / 2;
        maxmin2(i, mid, lmax, lmin);
        maxmin2(mid + 1, j, rmax, rmin);
        if (lmax > rmax)
            fmax = lmax;
        else
            fmax = rmax;
        if (lmin > rmin)
            fmin = rmin;
        else
            fmin = lmin;
    }
}

int main()
{
    int i, j, n;
    printf("请输入金块的根数:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &j);
        a[i] = j;
    }
    maxmin1(a, n);
    printf("the max is %f,the min is %f\n", max, min);
    maxmin2(1, n, fmax, fmin);
    printf("the fmax is %f,the fmin is %f\n", fmax, fmin);
    return 0;
}
