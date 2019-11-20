#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LNode *List;
struct LNode
{
    int data;
    List next;
};

void Init(List *L)
{
    (*L) = (List)malloc(sizeof(struct LNode));
    (*L)->next = NULL;
}

void Attach(int e, List *Rear)
{
    List P;
    P = (List)malloc(sizeof(struct LNode));
    P->data = e;
    P->next = NULL;
    (*Rear)->next = P;
    *Rear = P;
}
List ReadBase()
{
    List L1, p;
    int n, N = 5;
    Init(&L1);
    p = L1;
    while (N--)
    {
        scanf("%d", &n);
        Attach(n, &p);
    }
    return L1;
}

List ReadBase1()
{
    List L1, p;
    int n, N = 3;
    Init(&L1);
    p = L1;
    while (N--)
    {
        scanf("%d", &n);
        Attach(n, &p);
    }
    return L1;
}

List Sum(List L1, List L2)
{
    int flag = 0, f;
    List Head, p;
    Init(&Head);
    p = Head;
    while (L1->next && L2->next)
    {
        if (L1->next->data + L2->next->data >= 10)
        {
            f = (L1->next->data + L2->next->data + flag) / 10;
            flag = f;
            f = (L1->next->data + L2->next->data) % 10;
            Attach(f, &Head);
        }
        else
        {
            f = (L1->next->data + L2->next->data);
            Attach(f, &Head);
        }
        L1->next = L1->next->next;
        L2->next = L2->next->next;
    }
    if (!(L1->next || L2->next))
        Attach(flag, &Head);
    else
    {
        for (; L1->next; L1->next = L1->next->next)
            if (flag + L1->next->data < 10)
            {
                Attach(L1->next->data + flag, &Head);
                flag = 0;
            }
            else
            {
                Attach((L1->next->data + flag) % 10, &Head);
                Attach((L1->next->data + flag) / 10, &Head);
            }
        for (; L2->next; L2->next = L2->next->next)
            if (flag + L2->next->data < 10)
            {
                Attach(L2->next->data + flag, &Head);
                flag = 0;
            }
            else
            {
                Attach((L2->next->data + flag) % 10, &Head);
                Attach((L2->next->data + flag) / 10, &Head);
            }
    }
    Head->next = NULL;
    return p;
}

void print(List L)
{
    List p;
    p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main()
{
    List L1 = ReadBase();
    List L2 = ReadBase1();
    print(L1);
    printf("\n");
    print(L2);
    List result = Sum(L1, L2);
    printf("\n");
    print(result);
    return 0;
}