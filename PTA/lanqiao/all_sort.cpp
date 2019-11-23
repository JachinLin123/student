#include<iostream>
#include <cstdio>
#include<algorithm>
using namespace std;

bool complare(int a,int b)
{
    return a>b;
}
//冒泡排序
void BubbleSort(int a[], int len)
{
    bool flag;
    for (int i = 1; i < len; i++)
    {
        flag = false;
        for (int  j = 0; j < len-i; j++)
        {
            if (a[j] > a[j + 1])
            {
                 swap(a[j], a[j + 1]);   //相邻的进行比较，并调整
                 flag = true;
            }
        }
        if(!flag)
        {
            break;
        }  
    }
}
//选择排序
void SelectionSort(int* h, int len)
{
    if(h==NULL) return;
    if(len<=1) return;
    int minindex,i,j;
    //i是次数，也即排好的个数;j是继续排
    for(i=0;i<len-1;++i)
    {
        minindex=i;
        for(j=i+1;j<len;++j)
        {
            if(h[j]<h[minindex]) minindex=j;
        }
        swap(h[i],h[minindex]); 
    }
    return; 
}



//插入排序
void insertSelectionSort(int arr[], int len)  //这种排序不需要用swap交换语句，只需要复制即可
{
    for (int i = 1; i < len; i++)     //插入排序在进行时不需要考虑第一个数的情况，一个数，必然有序
    {
        int key = arr[i];   //取出待排序的数
        int j;
        for (j = i; j > 0 && arr[j - 1] > key; j--)//有两个限制条件，第二个限制条件使得插入排序比选择排序高效
        {
            arr[j] = arr[j - 1];
        }     
        arr[j] = key;
    }
}

void quickSort(int left, int right, int arr[])  //快速排序
{
    if(left >= right)
        return;
    int i, j, base;
    i = left, j = right;
    base = arr[left];  //取最左边的数为基准数
    while (i < j)
    {
        while (arr[j] >= base && i < j)
            j--;
        while (arr[i] <= base && i < j)
            i++;
        if(i < j)
            swap(arr[i], arr[j]);
    }

     //基准数归位
    arr[left] = arr[i];
    arr[i] = base;
    //一轮基本探测已结束
    quickSort(left, i - 1, arr);    //递归左边
    quickSort(i + 1, right, arr);   //递归右边
}

void AdjustHeap(int* h, int node, int len)  //----node为需要调整的结点编号，从0开始编号;len为堆长度 
{
     int index=node;
     int child=2*index+1; //左孩子，第一个节点编号为0 
     while(child<len)
     {
         //右子树 
         if(child+1<len && h[child]<h[child+1])
         {
             child++;
         }
         if(h[index]>=h[child]) break;
         swap(h[index],h[child]);
         index=child;
         child=2*index+1;
     }
}


int quick_select(int a[], int l, int r, int k) {
	int p = rand() % (r - l + 1) + l;
	int x = a[p];
	{int t = a[p]; a[p] = a[r]; a[r] = t;}
	int i = l, j = r;
	while(i < j) {
		while(i < j && a[i] < x) i++;
		if(i < j) {
			a[j] = a[i];
			j--;
		}
		while(i < j && a[j] > x) j--;
		if(i < j) {
			a[i] = a[j];
			i++;
		}
	}
	a[i] = x;
	p = i;
	if(i - l + 1 == k) return a[i];
	if(i - l + 1 < k) return quick_select(a, i+1, r, k - (i-l+1)); //填空
	else return quick_select(a, l, i - 1, k);
}
 

//====建堆=====
void MakeHeap(int* h, int len)
{
    for(int i=len/2;i>=0;--i)
    {
        AdjustHeap(h, i, len);
    }
}
 
 //====排序=====
void HeapSort(int* h, int len)
{
    MakeHeap(h, len);
    for(int i=len-1;i>=0;--i)
    {
        swap(h[i],h[0]);
        AdjustHeap(h, 0, i);
     }
}

const int Dgap = 2;
void shellSort(int arr[], int len)  //希尔排序
{
    int insertNumber = 0;
    int gap = len / Dgap;    //必须保证此时gap不小于1，否则无法进入while循环
    while (gap >= 1)
    {
        for (int i = gap; i < len; i++)
        {
            insertNumber = arr[i];
            int j = i;
            while (j >= gap && insertNumber < arr[j - gap])
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = insertNumber;
        }
        gap /= Dgap;
    }
}
void bucket_sort(int a[], int len)  //桶排序
{
    int bucket[10001]={0}, max = 0;
    for (int i = 0; i < len; i++)
     {
         max = (a[i] > max ? a[i] : max);    //找到最大的元素
     }
 
     for (int i = 0; i < len; i++)
    {
         bucket[a[i]]++;     //统计各个桶的情况
    }
 
    for (int i = 1; i <= max; i++)
    {
        if (bucket[i] == 0)
            continue;
        else
        {
            for (int j = 0; j < bucket[i]; j++)
                cout << i << ' ';   //输出最后的数列
        }
         
    }
}


int main()
{
    int a[10]={9,6,3,8,5,2,7,4,1,0};
    //sort(a,a+10,complare);//在这里就不需要对complare函数传入参数了，
    //这是规则
    //BubbleSort(a, 10);
    //insertSelectionSort(a, 10);
    //quickSort(0, 9, a);
    //shellSort(a, 10);
    //bucket_sort(a, 10);
    //SelectionSort(a, 10);
    //HeapSort(a, 10);
    //printf("%d\n", quick_select(a, 0, 9, 2));
    //cout << quick_select(a, 0, 9, 2);
    sort(a, a + 10);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << endl;
    }
    
    return 0;
}