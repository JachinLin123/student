#include <stdio.h>

void Print_Factorial ( const int N )
{
    long long sum = 1;
    if(N >=0 && N <= 12)
    {
        for (int i = 0; i < N; i++)
        {
            sum *= i + 1;
        }
        printf("%ld\n", sum);
    }
    else if (N > 12 && N <= 1000) {
        int Num[3000] = { 0 };  //确保保存最终运算结果的数组足够大：1-9相乘最多有9位，10-99相乘最多有2*90=180位，100-999相乘最多有3*900=2700位，1000是4*1=4位，总计2893，最好数组取大一下
        int i, j, k, n;
        k = 1;  //位数
        n = 0;  //进位
        Num[0] = 1;   //将结果先初始化为1
        int temp;  //阶乘的任一元素与临时结果的某位的乘积结果
 
        for (i = 2; i <= N; i++)  //开始阶乘，阶乘元素从2开始
        {  //和平时乘法方法相同，将临时结果的每位与阶乘元素相乘
 
            for (j = 0; j < k; j++)
            {
                temp = Num[j] * i + n;  //相应阶乘中的一项与当前所得临时结果的某位相乘（加上进位）
                Num[j] = temp % 10;  //更新临时结果的位上信息
                n = temp / 10;   //看是否有进位
            }
 
            while (n != 0)
            {  //如果有进位
                Num[k] = n % 10;  //新加一位，添加信息。位数增1
                k++;
                n = n / 10;   //看还能不能进位
            }
        }
 
        for (i = k - 1; i >= 0; i--)
        {
            printf("%d", Num[i]);  
        }
        printf("\n");
    }
    else{
        printf("Invalid input\n");
    }
}

int main()
{
    int N;
	
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}
