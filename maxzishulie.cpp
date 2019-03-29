#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num[10240],sum[16834];

int sum_1(int N){
    int ThisSum,MaxSum=0;
    sum[0] = 0;
    for (int i = 1; i <= N;i++)
        sum[i] = num[i] + sum[i - 1];
    MaxSum = num[1];
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j++)
        {
            ThisSum = sum[j] - sum[i - 1];
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    if (MaxSum < 0)
        MaxSum = 0;
    return MaxSum;
}

int sum_2(int N)//动态规划
{
    int ThisSum=num[1];
        for (int j = 1; j <= N; j++)
        {if(num[j-1]>0)
          num[j]+= num[j-1];
          else
              num[j] += 0;

            if (ThisSum < num[j])
             ThisSum=num[j];
             }
    if (ThisSum < 0)
        ThisSum = 0;
    return ThisSum;
}

int main()
{
    int N,i,l=0,r=0,s=0;

    int log = 1;

    scanf("%d", &N);

    int j = N;

    num[0] = 0;

    for ( i = 1;i <= N;i++){

        scanf("%d", &num[i]);
    }
    printf("%d",sum_2(N));

    /*int ans = num[1];

    for (i = 1; i <= N;i++){
        s += num[i];
        if(ans<s){
            ans = s;
            l = log;
            r = i;
        }
        if(s<0){
            s = 0;
            log = i + 1;
            j--;
        }
    }
    if(ans==0){
        if(j==0){
            printf("0 %d %d\n", num[1], num[N]);
        }
        else{
            printf("0 0 0\n");
        }
    }
    else{
        printf("%d %d %d\n", ans, num[l], num[r]);
    }
   
    system ("pause");

    return 0;*/
}