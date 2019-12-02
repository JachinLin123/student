#include"graph.h"
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
 
 
 
//初始化无向图
void Creat_graph(graph *g)
{
	//输入顶点信息
	char temp_char;
	for (int i = 0; i < N; ++i)
	{
		cout<<"输入一个顶点： ";
		cin>>temp_char;
		g->vexs[i] = temp_char;		
	}
 
	//初始化邻接矩阵
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			g->adjs[i][j] = 0;
		}
	}
 
	//写入邻接矩阵
	int vex1,vex2;//边的顶点
	float w;//权值
	for (int k = 0; k < E; ++k)
	{
		cout<<"输入每个边的两个顶点序号(注意顶点的序号从0开始)和权值:示例：1，2，5;表示第二和第三个顶点之间的是否相连以及权值"<<endl;
		scanf("%d%d%f",&vex1,&vex2,&w);//格式化输入，很方便
		g->adjs[vex1][vex2] = w;
		g->adjs[vex2][vex1] = w;
		//若建立有向图，则将最后一赋值语句去掉即可，可以将w的值设为1，变成无向图
	}	
}
