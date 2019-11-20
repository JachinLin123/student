#include <stdio.h>

int Count_Digit(const int N, const int D)
{
	int n = 0, k = 0, p[10] = {10};
	for (int j = 0; j < 10; j++)
	{
		p[j] = 10;
	}
	int m = 0;
	if(N < 0)
	{
		m = -N;
	}
	else
	{
		m = N;
	}
	if(m >= 10){
	while (m)
	{
		while (m != 0)
		{
			p[k] = m % 10;
			m = m / 10;
			k++;
		}
		for (int i = 0; i < k; i++)
		{
			if (p[i] == D)
			{
				n++;
			}
		}
	}
	}else{
		if(m==D)
			n++;
	}
	return n;
}

int main()
{
	int N, D;

	scanf("%d %d", &N, &D);
	printf("%d\n", Count_Digit(N, D));
	//system("pause");
	return 0;
}