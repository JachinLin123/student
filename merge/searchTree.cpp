/**
 * 
 给定一个插入序列就可以唯一确定一棵二叉搜索树。
 然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。
例如分别按照序列{2, 1, 3} 和{2, 3, 1} 插入初始为空的二叉搜索树，都得到一样的结果。
于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。
 
 输入格式 : 输入包含若干组测试数据。每组数据的第1行给出两个正整数N(≤10) 和L，
 分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。
 最后L行，每行给出N个插入的元素，属于L个需要检查的序列。 简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，
这组数据不要处理。
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
 输出格式 : 对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。
*/
/**
 * 分析：
 * a:先获得数据，用函数实现
 * 
 * b:利用这些数据构造二叉搜索树
 * 
 * c:比较这构造的树是否是通一颗二叉搜索树
 * 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define ElementType int

int N, L,pos,judgement[100];

struct Node
{
    ElementType data;
    struct Node *Left, *Right;
} T[10];

typedef struct Node *BinTree, *Position,Node;

Position Find(ElementType X, BinTree BST)
{
    if (!BST)
        return NULL; //查找失败
    if (X > BST->data)
        return Find(X, BST->Right); //在右子树中查找
    else if (X < BST->data)
    {
        return Find(X, BST->Left); //在左子树中查找
    }
    else
        return BST; //相等的情况
}

Position FindMin(BinTree BST)
{
    if (!BST)
        return NULL;
    else if (!BST->Left)
        return BST;
    else
        return FindMin(BST->Left);
}

Position FIndMax(BinTree BST)
{
    if (BST)
        while (BST->Right)
            BST = BST->Right;
    return BST;
}

BinTree Insert(ElementType X, BinTree &BST)//引用
{
    if (!BST) //如果树为空，直接构建一个节点返回
    {
        BST = (BinTree)malloc(sizeof(struct Node));
        BST->data = X;
        BST->Left = BST->Right = NULL;
    }
    else if (X < BST->data)
        BST->Left = Insert(X, BST->Left);
    else if (X > BST->data)
        BST->Right = Insert(X, BST->Right);
    return BST;
}

void PreOrderTraverse(BinTree T)
{
    if (T)
    {
        judgement[pos++] = T->data;
        PreOrderTraverse(T->Left);
        PreOrderTraverse(T->Right);
    }
}

bool PreOrderTraverse_test(BinTree T)
{
    if (T)
    {

        if (judgement[pos++] != T->data)
            return false;
        if (!PreOrderTraverse_test(T->Left))
            return false;
        if (!PreOrderTraverse_test(T->Right))
            return false;
    }

    return true;
}

BinTree Delete(ElementType X, BinTree BST)
{
    Position Tmp;
    if (!BST)
        printf("要删除的元素未找到!\n");
    else if (X < BST->data)
        BST->Left = Delete(X, BST->Left);
    else if (X > BST->data)
        BST->Right = Delete(X, BST->Right);
    else
    {
        if (BST->Left && BST->Right)
        {
            Tmp = FindMin(BST->Right);
            BST->data = Tmp->data;
            BST->Right = Delete(BST->data, BST->Right);
        }
        else
        {
            Tmp = BST;
            if (!BST->Left)
                BST = BST->Right;
            else if (!BST->Right)
                BST = BST->Left;
            free(Tmp);
        }
    }
    return BST;
}
int f = 1;
void check(BinTree T1, BinTree T2) //传入标准树和判断树的地址
{
    if (T1 != NULL && T2 != NULL) //如果两个地址都不为空，即此节点两棵树都有值，只需判断值是否相同
    {
        check(T1->Left, T2->Left); //中序遍历
        if (T2->data != T1->data)  //判断此节点的值是否和标准树一致
            f = false;
        check(T1->Right, T2->Right);
    }
    else if (T1 != NULL || T2 != NULL) //如果两颗树中，只有一棵树在这个节点有值，那么这两棵树肯定不一致
        f = false;
}

int main()
{

    while (scanf("%d", &N) != 0)
    {
        if (N)
            scanf("%d", &L);
        else
            break;
        pos = 0;
        BinTree  T=NULL;
        for (int i = 0; i < N; i++)//构建初始的一棵树.
        {
            int t;
            scanf("%d", &t);
            Insert(t, T);
        }
        PreOrderTraverse(T);//将初始树的值存入数组中.
        bool flag = true;
        for (int i = 0; i < L; i++)//比较的序列数。比较一次之后重置，继续输下一个系列
        {
            flag = true;
            BinTree Test=NULL ;
            pos = 0;
            for (int j = 0; j < N; j++)
            {
                int t;
                scanf("%d", &t);
                Insert(t, Test);
            }
            if (!PreOrderTraverse_test(Test))
                flag = false;
            if (flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}

/*#include <bits/stdc++.h>

using namespace std;
int N, L, pos, samejudgement[100];

typedef struct node
{
    node(int a, node *b, node *c)
    {
        data = a;
        l = b;
        r = c;
    }
    int data;
    struct node *l;
    struct node *r;
} * BST;

void PreOrderTraverse(BST T)
{
    if (T)
    {
        samejudgement[pos++] = T->data;
        PreOrderTraverse(T->l);
        PreOrderTraverse(T->r);
    }
}

bool PreOrderTraverse_test(BST T)
{
    if (T)
    {

        if (samejudgement[pos++] != T->data)
            return false;
        if (!PreOrderTraverse_test(T->l))
            return false;
        if (!PreOrderTraverse_test(T->r))
            return false;
    }

    return true;
}

void Inset_BST(BST &T, int data)
{
    if (T == NULL)
    {
        T = new node(data, NULL, NULL);
    }
    else if (T->data > data)
    {
        Inset_BST(T->l, data);
    }
    else
        Inset_BST(T->r, data);
}

int main()
{

    while (scanf("%d", &N) != EOF)
    {
        if (N)
            scanf("%d", &L);
        else
            break;

        pos = 0;
        memset(samejudgement, 0, sizeof(samejudgement));
        BST tree = NULL;
        for (int i = 0; i < N; i++)
        {
            int t;
            scanf("%d", &t);
            Inset_BST(tree, t);
        }

        PreOrderTraverse(tree);

        bool flag = true;
        for (int i = 0; i < L; i++)
        {
            flag = true;
            BST test_tree = NULL;
            pos = 0;
            for (int j = 0; j < N; j++)
            {
                int t;
                scanf("%d", &t);
                Inset_BST(test_tree, t);
            }
            if (!PreOrderTraverse_test(test_tree))
                flag = false;
            if (flag)
                printf("Yes\n");
            else
                printf("No\n");
        }

    }

    return 0;
}*/