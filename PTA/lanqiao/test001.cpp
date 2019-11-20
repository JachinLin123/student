#include<iostream> 
using namespace std;
int m,n,A[50005];
int ans[2000000]={0};
int sum = 0;
int main()
{
	cin>>n>>m;//输入学生数和画数 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int temp;
			cin>>temp;
			A[i] =(A[i]<<1)+temp;//2进制保存 
		}
		ans[A[i]]++;//获得每个答案的人数 
	} 
	int max = (1<<m)-1;
	for(int i=0;i<n;i++)
	{ 
		int temp = A[i]^max;//按位取反 
		sum += ans[temp] ;
	}
	cout<<sum/2<<endl;
	return 0;
} 
