#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read()
{
    int n, i;
    List p, q, L, temp;
    scanf("%d", &n);
    p = (List)malloc(sizeof(struct Node));
    p->Next = NULL;
    L = p;
    while (n--)
    {
        q = (List)malloc(sizeof(struct Node));
        scanf("%d", &i);
        q->Data = i;
        q->Next = NULL;
        p->Next = q;
        p = q;
    }
    temp = L;
    L = L->Next;
    free(temp);
    return L;
}
void Print(List L)
{
    int flag = 0;
    while (L)
    {
        if (!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d", L->Data);
        L = L->Next;   
    }
    printf("\n");
}

List Reverse(List L){
    List p, q, temp,f;
    p = (List)malloc(sizeof(struct Node));
    p->Next = NULL;
    f = L;
    while(f){
        q = (List)malloc(sizeof(struct Node));
        q->Data = f->Data;
        q->Next = p->Next;
        p->Next = q;
        f = f->Next;
    }
    L->Next = NULL;
    temp = p;
    p = p->Next;
    free(temp);
    return p;
}

int main()
{
    List L1,L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}
