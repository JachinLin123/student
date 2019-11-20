#include<stdio.h>
#include<string.h>

int main()
{
	int N,n = 0;
	scanf("%d", &N); getchar();
    int result[N];
    for (int i = 0; i < N; i++) 
	{
		char str[16];
		gets(str);
		for (int j = 2; j < strlen(str); j += 4)
			if (str[j] == 'T')
            {
                result[n] = str[j - 2] - 'A' + 1;
                n++;
            }
	}
    for (size_t i = 0; i < N; i++)
    {
        printf("%d", result[i]);
    }
    

	return 0;
}