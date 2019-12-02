#include "graph.h"
#include "queue"
 
#include <iostream>
using namespace std;
 
//需要定义为全局变量
graph *g = new graph;
int visit[N];          //辅助数组，标记点是否已经被访问
 
void DFSA(int i)
{
	cout<<"访问出发顶点序号: "<<i<<endl;
	visit[i] = 1;
	cout<<g->vexs[i]<<" "<<endl;
	for (int j = 0; j < N; ++j)//依次遍历i顶点的邻接点
	{
		if ((g->adjs[i][j]==1) && (visit[j]==0))//与i相连且未被访问过
		{
			DFSA(j);
		}
	}
}
 
void BFSA(int k)
{
	queue<int> Q;
	int i,j;
	cout<<"访问出发顶点序号: "<<k<<endl;
	visit[k] = 1;
	Q.push(k);
	while (!empty(Q))
	{
        i = Q.front();
        Q.pop();
		for (j = 0; j < N; ++j)
		{
			if ((g->adjs[i][j]==1) && (visit[j]==0))//与i相连且未被访问过
			{
				cout<<"访问i的领接点j";
				visit[j] = 1;
				Q.push(j);
			}
		}
	}
 
}
 
int main(int argc, char** argv)
{
	Creat_graph(g);
	cout<<"图g的顶点为：";
	for (int i = 0; i < 4; ++i)
	{
		cout<<g->vexs[i]<<" ";
	}
	cout<<endl;
	//图的遍历算法,传入图和指定的起始遍历顶点序号
	DFSA(0);
	delete g;//记住要释放内存啊@ ！@
	system("pause");
	return 0;
}
