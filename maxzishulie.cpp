#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num[10240];

int main()
{
    int N,i,l=0,r=0,s=0;

    int log = 1;

    scanf("%d", &N);

    int j = N;

    for ( i = 1;i <= N;i++){

        scanf("%d", &num[i]);
    }
    int ans = num[1];

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

    return 0;
}