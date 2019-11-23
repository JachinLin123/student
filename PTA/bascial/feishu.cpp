#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;

int a[9];

int main()
{
    for(int i=0;i<9;i++)
        a[i]=i+1;///数字1-9
    int n,x,b,c,ans=0;
    scanf("%d",&n);
    do
    {
        x=0;
        for(int i=0;i<6;i++)/// n<= 1000000
        {
            x=x*10+a[i];
            if(x<n)
            {
                int idx=(8-i)/2;///对x后面的数位折半 确保b>c
                while((i+idx)<8)
                {
                    b=0;c=0;
                    int j;
                    for(j=i+1;j<=(i+idx);j++)
                        b=b*10+a[j];
                    for(;j<9;j++)
                        c=c*10+a[j];
                    if(b%c==0 && b>c && n==(x+b/c) )
                        ans++;
                    idx++;
                }
            }
        }
    }while(next_permutation(a,a+9));///对数组a里下标为0到下标为8这九个数全排列
    printf("%d\n",ans);
    return 0;
}