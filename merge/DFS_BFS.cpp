#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 图的邻接矩阵表示法 */
#define MaxVertexNum 100 /* 最大顶点数设为100 */
#define ERROR -1
#define Maxsize 100
#define ElementType int
#define INFINITY 65535  /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;     /* 用顶点下标表示顶点,为整型 */
typedef int WeightType; /* 边的权值设为整型 */
typedef char DataType;  /* 顶点存储的数据类型设为字符型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;     // 有向边<V1, V2>
    WeightType Weight; // 权重
};
typedef PtrToENode Edge;

//图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;                                   // 顶点数
    int Ne;                                   // 边数
    WeightType G[MaxVertexNum][MaxVertexNum]; //邻接矩阵
    DataType Data[MaxVertexNum];              //存顶点的数据
    // 注意：很多情况下，顶点无数据，此时Data[]可以不用出现
};
typedef PtrToGNode MGraph; //以邻接矩阵存储的图类型

//循环队列的基本操作
typedef int Position;
struct QNode
{
    ElementType *Data;    /* 存储元素的数组 */
    Position Front, Rear; /* 队列的头、尾指针 */
    int MaxSize;          /* 队列最大容量 */
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
//普通队列的基本操作
/*typedef struct Node *PtrToNode;
struct Node
{ // 队列中的结点 
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode
{
    Position Front, Rear; // 队列的头、尾指针 
    int MaxSize;          // 队列最大容量 
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
        printf("队列空");
        return ERROR;
    }
    else
    {
        FrontCell = Q->Front;
        if (Q->Front == Q->Rear)       // 若队列只有一个元素 
            Q->Front = Q->Rear = NULL; // 删除后队列置为空 
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;

        free(FrontCell); // 释放被删除结点空间  
        return FrontElem;
    }
}*/

//下面是图的基本操作,广度加深度优先.

MGraph CreateGraph(int VertexNum)
{ // 初始化一个有VertexNum个顶点但没有边的图
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode)); // 建立图
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    // 初始化邻接矩阵
    // 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1)
    for (V = 0; V < Graph->Nv; V++)
        for (W = 0; W < Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    // 插入边 <V1, V2>
    Graph->G[E->V1][E->V2] = E->Weight;
    // 若是无向图，还要插入边<V2, V1>
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    //Vertex V;//如果顶点有数据的话，取消注释
    int Nv, i;

    scanf("%d", &Nv);        // 读入顶点个数
    Graph = CreateGraph(Nv); // 初始化有Nv个顶点但没有边的图

    scanf("%d", &(Graph->Ne)); // 读入边数
    if (Graph->Ne != 0)
    {                                           // 如果有边
        E = (Edge)malloc(sizeof(struct ENode)); // 建立边结点
        // 读入边，格式为"起点 终点 权重"，插入邻接矩阵
        for (i = 0; i < Graph->Ne; i++)
        {
            E->Weight = 0;
            scanf("%d %d", &E->V1, &E->V2);
            //注意：如果权重不是整型，Weight的读入格式要改
            InsertEdge(Graph, E);
        }
    }

    // 如果顶点有数据的话，读入数据
    //for (V = 0; V < Graph->Nv; V++)
    //   scanf(" %c", &(Graph->Data[V]));

    return Graph;
}

/* 邻接矩阵存储的图 - BFS */
/* IsEdge(Graph, V, W)检查<V, W>是否图Graph中的一条边，即W是否V的邻接点。  
 此函数根据图的不同类型要做不同的实现，关键取决于对不存在的边的表示方法。
 例如对有权图, 如果不存在的边被初始化为INFINITY, 则函数实现如下:         */
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
    return Graph->G[V][W] < INFINITY ? true : false;
}

void Visit(Vertex V)
{
    printf(" %d", V);
}
//Visited[]为全局变量，已经初始化为false
int Visited[100] = {0};

void DFS(MGraph Graph, Vertex S, void (*Visit)(Vertex))
{ // 以S为出发点对邻接表存储的图Graph进行DFS搜索
    Vertex W;
    Visit(S);                                       //访问第S个顶点
    Visited[S] = true;                              // 标记S已访问
    for (W = 0; W < Graph->Nv; W++)
    {
        if (!Visited[W] && IsEdge(Graph, S, W))
        {
            DFS(Graph,W,Visit);
        }
    }
}

//对于不连通图
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
{ // 以S为出发点对邻接矩阵存储的图Graph进行BFS搜索
    Queue Q;
    Vertex V, W;

    Q = CreateQueue(Maxsize); // 创建空队列, MaxSize为外部定义的常数
    // 访问顶点S：此处可根据具体访问需要改写
    Visit(S);
    Visited[S] = true; // 标记S已访问
    AddQ(Q, S);        // S入队列

    while (!IsEmpty(Q))
    {
        V = DeleteQ(Q);                 // 弹出V
        for (W = 0; W < Graph->Nv; W++) // 对图中的每个顶点W
            // 若W是V的邻接点并且未访问过
            if (!Visited[W] && IsEdge(Graph, V, W))
            {
                // 访问顶点W
                Visit(W);
                Visited[W] = true; // 标记W已访问
                AddQ(Q, W);        // W入队列
            }
    } // while结束
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
