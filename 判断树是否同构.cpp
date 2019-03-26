#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
} T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
    int N, i;
    char cl, cr;
    int check[MaxTree];
    scanf("%d\n", &N);
    Tree Root = Null;
    if (N)
    {
        for (i = 0; i < N; i++)
            check[i] = 0;
        for (i = 0; i < N; i++)
        {
            scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
            if (cl != '-')
            {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            }
            else
            {
                T[i].Left = Null;
            }
            if (cr != '-')
            {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else
            {
                T[i].Right = Null;
            }
        }

        for (i = 0; i < N; i++)
            if (!check[i])
                break;
        Root = i;
    }
    return Root;
}

int Isomorphic(Tree R1, Tree R2)
{
    if ((R1 == Null) && (R2 == Null))
        return 1;
    if ((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null))
        return 0;
    if (T1[R1].Element != T2[R2].Element)
        return 0;
    if ((T1[R1].Left == Null) && (T2[R2].Left == Null))
        return (Isomorphic(T1[R1].Right, T2[R2].Right));
    if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) && ((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
        return ((Isomorphic(T1[R1].Left, T2[R2].Left)) && (Isomorphic(T1[R1].Right, T2[R2].Right)));
    else
        return ((Isomorphic(T1[R1].Right, T2[R2].Left)) && (Isomorphic(T1[R1].Left, T2[R2].Right)));
}

int main()
{
    Tree R1, R2;
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if (Isomorphic(R1, R2))
        printf("Yes\n");
    else
        printf("No\n");

    system("pause");
    return 0;
}
/*#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<string.h>
#include<string>
#include<vector>
#define MAX 100
#define  NULL -1//这里的空为-1，因为数组的下标为0也是有效区域
using namespace std;
struct node
{
	char data;
	int lchild;
	int rchild;
}Tree1[MAX], Tree2[MAX];
int Create(struct node tree[])
{
	int i,n,root=NULL;//这里一定要赋值为-1,因为树可能为空
	cin >> n;
	int *chick = new int[n + 1];
	fill(chick, chick + n, 0);
	char c,ch1,ch2;
	for (i = 0; i < n; i++)
	{
		cin >> c >> ch1>>ch2;
		tree[i].data = c;
		if (ch1 == '-')		tree[i].lchild = NULL;//如果遇到 - ，则赋值为空，这里为-1
		else
		{
			tree[i].lchild = ch1 - '0';
			chick[tree[i].lchild] = 1;
		}
		if (ch2 == '-')		tree[i].rchild = NULL;
		else
		{
			tree[i].rchild = ch2 - '0';
			chick[tree[i].rchild] = 1;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (!chick[i])
		{
			root = i;
			break;
		}
	}
	delete[] chick;
	return root;
}
 
bool isomorphis( int r1, int r2)
{
	if (r1 == NULL && r2 == NULL)	return true;
 
	if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)) return false;
 
	if (Tree1[r1].data != Tree2[r2].data) return false;
 
	if( Tree1[r1].lchild == NULL && Tree2[r2].lchild == NULL)
		return isomorphis(Tree1[r1].lchild,Tree2[r2].lchild)&&
		isomorphis(Tree1[r1].rchild, Tree2[r2].rchild);
 
	if(Tree1[Tree1[r1].lchild].data == Tree2[Tree2[r2].lchild].data )
		return isomorphis(Tree1[r1].rchild, Tree2[r2].rchild);
 
	else return isomorphis(Tree1[r1].lchild, Tree2[r2].rchild) && isomorphis(Tree1[r1].rchild, Tree2[r2].lchild);
}
 

int main()
{
	int r1 = Create(Tree1);
	int r2 = Create(Tree2);
	if (isomorphis(r1, r2)) cout << "Yes" << endl;
	else cout << "No" << endl;
    system("pause");
    return 0;
}*/
