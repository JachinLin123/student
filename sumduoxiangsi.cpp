/*#include <stdio.h>
#include <stdlib.h>
#define N 10000
int main()
{
    int a[N] = {0};
    int b[N] = {0};
    int c[N] = {0}; //求积
    int d[N] = {0}; //求和
    int i, j;
    int x, z; //系数  指数
    int cnt = 0;

    scanf("%d", &i); //读入第一个单项式
    while (i--)
    {
        scanf("%d %d", &x, &z);
        a[z] += x; //指数为z的系数放在z位置上
    }

    scanf("%d", &i); //读入第二个单项式
    while (i--)
    {
        scanf("%d %d", &x, &z);
        b[z] += x;
    }

    //多项式乘法
    for (i = N - 1; i >= 0; i--)
    {

        if (a[i])
        {
            for (j = 0; j < N; j++)
            {
                if (b[j])
                {
                    c[i + j] += a[i] * b[j];
                }
            }
        }
    }

    //输出多项式乘法结果
    for (i = N - 1; i >= 0; i--)
    {

        if (c[i])
        {
            if (cnt)
            {
                //处理结尾不能有多余空格
                printf(" ");
            }
            printf("%d %d", c[i], i);
            cnt++;
        }
    }
    if (!cnt)
    {
        printf("0 0");
    }
    printf("\n");

    //多项式加法
    for (i = N - 1; i >= 0; i--)
    {
        if (a[i])
        {
            d[i] += a[i];
        }
    }
    for (j = N - 1; j >= 0; j--)
    {
        if (b[j])
        {
            d[j] += b[j];
        }
    }

    //输出多项式加法结果
    cnt = 0;
    for (i = N - 1; i >= 0; i--)
    {
        if (d[i])
        {
            if (cnt)
            {
                printf(" ");
            }
            printf("%d %d", d[i], i);
            cnt++;
        }
    }
    if (!cnt)
    {
        printf("0 0");
    }

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PolyNode
{
    int coef;
    int expon;
    struct PolyNode *link;
} PolyNode;

typedef PolyNode *Polynomial;

Polynomial P1, P2;

void Attach(int c, int e, Polynomial *pRear)
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;
}

Polynomial ReadPoly()
{
    Polynomial P, Rear, t;
    int c, e, N;
    scanf("%d", &N);
    P = (Polynomial)malloc(sizeof(PolyNode));
    P->link = NULL;
    Rear = P;
    while (N--)
    {
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear);
    }
    t = P;
    P = P->link;
    free(t);
    return P;
}

int Compare(int a, int b)
{
    int i;
    if (a > b)
        i = 1;
    else if (a < b)
        i = -1;
    else
        i = 0;
    return i;
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
    Polynomial temp, rear, front;
    int sum;
    rear = (Polynomial)malloc(sizeof(PolyNode));
    front = rear;
    while (P1 && P2)
    {
        switch (Compare(P1->expon, P2->expon))
        {
        case 1:
            Attach(P1->coef, P1->expon, &rear);
            P1 = P1->link;
            break;
        case -1:
            Attach(P2->coef, P2->expon, &rear);
            P2 = P2->link;
            break;
        case 0:
            sum = P1->coef + P2->coef;
            if (sum)
                Attach(sum, P1->expon, &rear);
            P1 = P1->link;
            P2 = P2->link;
            break;
        }
    }
    for (; P1; P1 = P1->link)
        Attach(P1->coef, P1->expon, &rear);
    for (; P2; P2 = P2->link)
        Attach(P2->coef, P2->expon, &rear);
    rear->link = NULL;
    temp = front;
    front = front->link;
    free(temp);
    return front;
}
Polynomial PolyMul(Polynomial P1, Polynomial P2)
{
    Polynomial P, Rear, t1, t2, t;
    int c, e;

    if (!P1 || !P2)
        return NULL;
    t1 = P1;
    t2 = P2;
    P = (Polynomial)malloc(sizeof(PolyNode));
    Rear = P;
    while (t2)
    {
        Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while (t1)
    {
        t2 = P2, Rear = P;
        while (t2)
        {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while (Rear->link && Rear->link->expon > e)
            {
                Rear = Rear->link;
            }
            if (Rear->link && Rear->link->expon == e)
            {
                if (Rear->link->coef + c)
                    Rear->link->coef += c;
                else
                {
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            }
            else
            {
                t = (Polynomial)malloc(sizeof(PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = P;
    P = P->link;
    free(t2);
    return P;
}

void print(Polynomial P)
{
    int flag = 0;
    if (!P)
    {
        printf("0 0\n");
        return;
    }
    while (P)
    {
        if (!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}

int main()
{
    Polynomial p1, p2, sum,mul;
    p1 = ReadPoly();
    p2 = ReadPoly();
    mul = PolyMul(p1, p2);
    print(mul);
    sum = PolyAdd(p1, p2);
    print(sum);
    system("pause");
    return 0;
}
