#ifndef DS_GRAPH_GRAPH_H
#define DS_GRAPH_GRAPH_H
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
 
#define E 4 //图的边数
#define N 4//图的顶点数
 
typedef char vextype;  //顶点的数据类型
typedef float adjtype; //边的权值数据类型
 
//图的结构体定义
typedef struct  
{
	vextype vexs[N];     //顶点信息
	adjtype adjs[N][N];  //领接矩阵
} graph;
 
//初始化无向图
void Creat_graph(graph *g);
 
#endif DS_GRAPH_GRAPH_H
