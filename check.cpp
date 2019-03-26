#include<stdio.h> 
#include<cstdlib>
#include<malloc.h> 
#define  TRUE  1 
#define  FALSE 0 
typedef struct PCB_type {
char name;	//进程名
int state;	//进程状态
//2--表示 " 执行 " 状态
//1--表示 " 就绪 " 状态
//0--表示 " 阻塞 " 状态
int cpu_time;	//运行需要的CPU时间（需要运行的时间片个数）
}PCBtype;
 
typedef struct QueueNode		//定义节点
{
PCBtype  PCB;
struct QueueNode *next;
} LinkQueueNode;
typedef struct Queue	//定义队列
{
 
LinkQueueNode  * head;
LinkQueueNode  * tail; 
}
LinkQueue;
LinkQueue rq,bq,runq;
int deleteState=0; 
int ready=2;
int blocked=3; 
int counter=5;
int createq(LinkQueue*Q)			//队列初始化
 
{
 
Q->head=(LinkQueueNode*)malloc(sizeof(LinkQueueNode));
if(Q->head !=NULL) 
{
Q->tail=Q->head; 
Q->head->next=NULL; 
return (TRUE);
}
else return(FALSE);
}
 
void fuzhi(PCBtype*PCB1,PCBtype*PCB2) 
{
PCB1->name=PCB2->name; 
PCB1->state=PCB2->state;
PCB1->cpu_time=PCB2->cpu_time;
}
 
int enterQueue(LinkQueue *Q,LinkQueueNode x)	//入队列操作算法
{
 
LinkQueueNode *NewNode; 
NewNode=(LinkQueueNode*)malloc(sizeof(LinkQueueNode)); 
if(NewNode!=NULL)
{
fuzhi(&NewNode->PCB,&x.PCB); 
NewNode->next=NULL; 
Q->tail->next=NewNode; 
Q->tail=NewNode;
return (TRUE);
}
else return(FALSE);
 
}
 
LinkQueueNode*deleteQ(LinkQueue*Q)
 
{
LinkQueueNode*NewNode;
if(Q->head == Q->tail) 
{
deleteState=0;
 
} 
else 
{
NewNode = Q->head->next;
Q->head->next = NewNode->next; 
if(Q->tail == NewNode)
Q->tail = Q->head;
deleteState =1;
}
return NewNode ;
}


void display(LinkQueue Q) 
 
{
LinkQueueNode *Newhead=Q.head->next;
 
while(Newhead !=Q.tail->next) {
printf("**************\n");
printf("该进程的名称为:%c\n",Newhead->PCB.name);
printf("该进程的状态为:%d\n",Newhead->PCB.state);
printf("进程运行所需的CPU时间为:%d\n",Newhead->PCB.cpu_time);
printf("**************\n");
Newhead=Newhead->next;
}
 
}
 
void create() 
{
	char c1, c2;

	LinkQueueNode *NewNode;

	PCBtype *pcbnode;

	NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));

	pcbnode = (PCBtype *)malloc(sizeof(PCBtype));

	printf("请按序输入进程名, 进程状态 , 运行所需时间片个数:\n");

	printf("\t  2- 表示执行状态\n\t  1- 表示就绪状态\n\t0- 表示阻塞状态\n");

	while (1)

	{
		scanf("%c %d %d", &pcbnode->name, &pcbnode->cpu_time, &pcbnode->state);

		fuzhi(&NewNode->PCB, pcbnode);

		printf(" Enter继续输入, 否则结束输入\n");

		if (pcbnode->state == 2)
			enterQueue(&runq, *NewNode);

		if (pcbnode->state == 1)
			enterQueue(&rq, *NewNode);

		if (pcbnode->state == 0)
			enterQueue(&bq, *NewNode);
		c1 = getchar();

		if(c1!='\n')
			break;
} 
display(rq);
 
display(bq);
}
 
 
 
int GetStateQueue(LinkQueue Q) {
int retval;
 
if(Q.head == Q.tail)
 
retval=0;
 
else
 
retval=1;
 
return retval;
 
}
 
 
void dispath() 
{
int counte=0,i=0,j; 
LinkQueueNode *deleteNode; 
int flag1,flag2;
char name[20]; 
while(TRUE)
{
 
if(rq.head->next!=NULL||bq.head->next!=NULL)
 
{
 
if(GetStateQueue(rq))
 
{
 
deleteNode=deleteQ(&rq);
 
flag1 =enterQueue(&runq,*deleteNode); 
if(flag1)
{
printf("进程%c 调度成功, 状态由绪变成运行 !\t",deleteNode->PCB.name);
 
deleteNode->PCB.state = 2;
 
printf("进程状态变为:%d\n",deleteNode->PCB.state);
 
deleteNode->PCB.cpu_time--;
 
name[i++]=deleteNode->PCB.name;
} 

if(deleteNode->PCB.cpu_time>0) 
{
deleteNode->PCB.state= 1;
 
flag1 =enterQueue(&rq,*deleteNode);
 
if(flag1)
 
printf("进程%c调度成功,状态由运行变成就绪!\t",deleteNode->PCB.name);
 
printf("进程状态变为:%d\n",deleteNode->PCB.state);
 
}
else
free(deleteNode);
}
 
counte++; 
if(counte==counter) 
{
if(GetStateQueue(bq))
 
{
 
deleteNode = deleteQ(&bq);
 
flag2 =enterQueue(&rq,*deleteNode);
 
if(flag2)
 
printf("进程%c调度成功,状态由阻塞变成就绪 !\t",deleteNode->PCB.name); 
 
deleteNode->PCB.state=1;
 
printf("进程状态变为:%d\n",deleteNode->PCB.state);
 
counte=0;

	}
 
  }
 
}
else break;
}
printf("执行序列为 \n");
 
for(j=0;j<i;j++)
 
{
printf("%c",name[j]);
 
} 
printf("\n");

}
 

int main() 
{
if(createq(&rq)&&createq(&bq)&&createq(&runq))
printf("\t队列初始化成功!\n");
else
{
printf("队列初始化失败, 程序将退出\n!");
exit(0);
} 
create(); 
dispath();
system("pause");
return 0;
}