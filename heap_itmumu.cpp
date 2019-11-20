/**
 * 5 3
 * 
 * 46 23 26 24 10
 *
 * 5 4 3
 * 
 * 
 * 24 23 10
 * 46 23 10
 * 26 10
 *
 */

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ElementType int
#define MAXN 1001
#define MINH -10001

int H[MAXN], size;

//堆的基本算法
typedef struct HeapStruct *MaxHeap;
struct HeapStruct
{
    ElementType *Elements;
    int size;
    int capacity;
};
MaxHeap Creat(int MaxSize)//相当于初始化
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Elements =(ElementType*)malloc((MaxSize+1)*sizeof(ElementType));
    H->size = 0;
    H->capacity = MaxSize;
    H->Elements[0] = MINH;
    return H;
}
int IsEmpty(MaxHeap H)
{
    int i;
    if (H->size == 0)
        i = 0;
    else
        i = 1;
    return i;
}
int IsFull(MaxHeap H)
{
    int i;
    if (H->size == MAXN)
        i = 0;
    else
        i = 1;
    return i;
}

void Insert(MaxHeap H,ElementType item){
    int i;
    if(IsFull(H)){
        printf("最大堆已经满了!");
        return;
    }
    i = ++H->size;
    for (; H->Elements[i / 2] < item;i/=2){
        H->Elements[i] = H->Elements[i / 2];
        H->Elements[i] = item;

    }
}

ElementType DeleteMax(MaxHeap H){
    int Parent, Child;
    ElementType MaxItem, temp;
    if(IsEmpty(H)){
        printf("最大堆已空!");
        return -1;
    }
    MaxItem = H->Elements[1];
    temp = H->Elements[H->size--];
    for (Parent = 1; Parent * 2 <= H->size;Parent=Child){
        Child = Parent * 2;
        if((Child!=H->size)&&(H->Elements[Child]<H->Elements[Child+1])){
            Child++;
        }
        if(temp>H->Elements[Child]){
            break;
        }
        else
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = temp;
    return MaxItem;
}

void Create()
{
    size = 0;
    /**
     * 设置岗哨
     * */
    H[0] = MINH;
}

void Insert(int X)
{
    int i;
    for (i = ++size; H[i / 2] > X; i /= 2)
        H[i] = H[i / 2];
    H[i] = X;
}

int main()
{
    int n, m, i, j, x;
    scanf("%d %d", &n, &m);
    Create();
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        Insert(x);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &j);
        printf("%d", H[j]);
        while (j > 1)
        {
            printf(" ");
            j /= 2;
            printf("%d", H[j]);
        }
        printf("\n");
    }
    return 0;
}