#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ͼ���ڽӾ����ʾ�� */
#define MaxVertexNum 100 /* ��󶥵�����Ϊ100 */
#define ERROR -1
#define Maxsize 100
#define ElementType int
#define INFINITY 65535  /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;     /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType; /* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType;  /* ����洢������������Ϊ�ַ��� */

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;     // �����<V1, V2>
    WeightType Weight; // Ȩ��
};
typedef PtrToENode Edge;

//ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;                                   // ������
    int Ne;                                   // ����
    WeightType G[MaxVertexNum][MaxVertexNum]; //�ڽӾ���
    DataType Data[MaxVertexNum];              //�涥�������
    // ע�⣺�ܶ�����£����������ݣ���ʱData[]���Բ��ó���
};
typedef PtrToGNode MGraph; //���ڽӾ���洢��ͼ����

//ѭ�����еĻ�������
typedef int Position;
struct QNode
{
    ElementType *Data;    /* �洢Ԫ�ص����� */
    Position Front, Rear; /* ���е�ͷ��βָ�� */
    int MaxSize;          /* ����������� */
};
typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool IsFull(Queue Q)
{
    return ((Q->Rear + 1) % Q->MaxSize == Q->Front);
}

bool AddQ(Queue Q, ElementType X)
{
    if (IsFull(Q))
    {
        printf("full");
        return false;
    }
    else
    {
        Q->Rear = (Q->Rear + 1) % Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}

bool IsEmpty(Queue Q)
{
    return (Q->Front == Q->Rear);
}

ElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("empty");
        return ERROR;
    }
    else
    {
        Q->Front = (Q->Front + 1) % Q->MaxSize;
        return Q->Data[Q->Front];
    }
}
//��ͨ���еĻ�������
/*typedef struct Node *PtrToNode;
struct Node
{ // �����еĽ�� 
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode
{
    Position Front, Rear; // ���е�ͷ��βָ�� 
    int MaxSize;          // ����������� 
};
typedef struct QNode *Queue;

bool IsEmpty(Queue Q)
{
    return (Q->Front == NULL);
}

ElementType DeleteQ(Queue Q)
{
    Position FrontCell;
    ElementType FrontElem;

    if (IsEmpty(Q))
    {
        printf("���п�");
        return ERROR;
    }
    else
    {
        FrontCell = Q->Front;
        if (Q->Front == Q->Rear)       // ������ֻ��һ��Ԫ�� 
            Q->Front = Q->Rear = NULL; // ɾ���������Ϊ�� 
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;

        free(FrontCell); // �ͷű�ɾ�����ռ�  
        return FrontElem;
    }
}*/

//������ͼ�Ļ�������,��ȼ��������.

MGraph CreateGraph(int VertexNum)
{ // ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode)); // ����ͼ
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    // ��ʼ���ڽӾ���
    // ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1)
    for (V = 0; V < Graph->Nv; V++)
        for (W = 0; W < Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    // ����� <V1, V2>
    Graph->G[E->V1][E->V2] = E->Weight;
    // ��������ͼ����Ҫ�����<V2, V1>
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    //Vertex V;//������������ݵĻ���ȡ��ע��
    int Nv, i;

    scanf("%d", &Nv);        // ���붥�����
    Graph = CreateGraph(Nv); // ��ʼ����Nv�����㵫û�бߵ�ͼ

    scanf("%d", &(Graph->Ne)); // �������
    if (Graph->Ne != 0)
    {                                           // ����б�
        E = (Edge)malloc(sizeof(struct ENode)); // �����߽��
        // ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ���
        for (i = 0; i < Graph->Ne; i++)
        {
            E->Weight = 0;
            scanf("%d %d", &E->V1, &E->V2);
            //ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ��
            InsertEdge(Graph, E);
        }
    }

    // ������������ݵĻ�����������
    //for (V = 0; V < Graph->Nv; V++)
    //   scanf(" %c", &(Graph->Data[V]));

    return Graph;
}

/* �ڽӾ���洢��ͼ - BFS */
/* IsEdge(Graph, V, W)���<V, W>�Ƿ�ͼGraph�е�һ���ߣ���W�Ƿ�V���ڽӵ㡣  
 �˺�������ͼ�Ĳ�ͬ����Ҫ����ͬ��ʵ�֣��ؼ�ȡ���ڶԲ����ڵıߵı�ʾ������
 �������Ȩͼ, ��������ڵı߱���ʼ��ΪINFINITY, ����ʵ������:         */
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
    return Graph->G[V][W] < INFINITY ? true : false;
}

void Visit(Vertex V)
{
    printf(" %d", V);
}
//Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse
int Visited[100] = {0};

void DFS(MGraph Graph, Vertex S, void (*Visit)(Vertex))
{ // ��SΪ��������ڽӱ�洢��ͼGraph����DFS����
    Vertex W;
    Visit(S);                                       //���ʵ�S������
    Visited[S] = true;                              // ���S�ѷ���
    for (W = 0; W < Graph->Nv; W++)
    {
        if (!Visited[W] && IsEdge(Graph, S, W))
        {
            DFS(Graph,W,Visit);
        }
    }
}

//���ڲ���ͨͼ
void ListCompoents(MGraph G)
{
    for (int V = 0; V < G->Nv; V++)
    {
        if (!Visited[V])
        {
            printf("{");
            DFS(G, V, Visit);
            printf(" }\n");
        }
    }
}

void BFS(MGraph Graph, Vertex S, void (*Visit)(Vertex))
{ // ��SΪ��������ڽӾ���洢��ͼGraph����BFS����
    Queue Q;
    Vertex V, W;

    Q = CreateQueue(Maxsize); // �����ն���, MaxSizeΪ�ⲿ����ĳ���
    // ���ʶ���S���˴��ɸ��ݾ��������Ҫ��д
    Visit(S);
    Visited[S] = true; // ���S�ѷ���
    AddQ(Q, S);        // S�����

    while (!IsEmpty(Q))
    {
        V = DeleteQ(Q);                 // ����V
        for (W = 0; W < Graph->Nv; W++) // ��ͼ�е�ÿ������W
            // ��W��V���ڽӵ㲢��δ���ʹ�
            if (!Visited[W] && IsEdge(Graph, V, W))
            {
                // ���ʶ���W
                Visit(W);
                Visited[W] = true; // ���W�ѷ���
                AddQ(Q, W);        // W�����
            }
    } // while����
}

void ListCompoents2(MGraph Graph)
{
    for (int V = 0; V < Graph->Nv; V++)
    {
        if (!Visited[V])
        {
            printf("{");
            BFS(Graph, V, Visit);
            printf(" }\n");
        }
    }
}

int main()
{
    MGraph M;
    M = BuildGraph();
    ListCompoents(M);
    memset(Visited, 0, sizeof(Visited));
    ListCompoents2(M);
}
