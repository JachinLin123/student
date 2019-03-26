#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
float a[100];

void Input()
{
  int i;
  printf("请输入金块的根数:\n");
  scanf("%d\n", &N);
  while (N--)
  {
    scanf("%d\n", &i);
    for (int j = 1; j <= N; j++)
      a[j] = i;
  }
}

float max, min;

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

/*void maxmin2(int i, int j, float &fmax, float &fmin) {
  int mid;
  float lmax, lmin, rmin, rmax;
  if (i == j) {
    fmax = a[i];
    fmin = a[i];
  } else if (i == j - 1)
    if (a[i] < a[j]) {
      fmax = a[j];
      fmin = a[i];
    } else {
      fmax = a[i];
      fmin = a[j];
    }
  else {
    mid = (i + j) / 2;
    maxmin2(i, mid, lmax, lmin);
    if (lmax > rmax) {
      fmax = lmax;
      maxmin2(mid + 1, j, rmax, rmin);
    } else
      fmax = rmax;
    if (lmin > rmin)
      fmin = rmin;
    else
      fmin = lmin;
  }
}*/

int main()
{
  Input();
  maxmin1(a, N);
  printf("The max is %f,the min is %f \n", max, min);
  /* float *fmax, *fmin;
  maxmin2(1, N, &fmax, &fmin);
  printf("The max is %f,the min is %f \n", fmax, fmin);*/
  system("pause");
  return 0;
}