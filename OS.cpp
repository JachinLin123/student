#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PCB_type
{
    char name;    //进程名
    int state;    //进程状态 ; 2--表示"执行"状态; 1--表示"就绪"状态; 0--表示"阻塞"状态
    int cpu_time; //运行需要的CPU时间（需运行的时间片个数）
} PCB_type;

typedef struct QueueNode
{
    PCB_type PCB;
    QueueNode *next;
} QueueNode;

typedef struct Queue
{

    QueueNode *head, *tail;
} Queue;

Queue rq, bq, runq; //ready队列、blocked队列、run队列

int deletestate = 0;
int ready = 2;
int blocked = 3;
int counter = 5;

int Init(Queue *queue)           //初始化队列
{
    queue->head = (QueueNode *)malloc(sizeof(QueueNode));

    if (queue->head != NULL)
    {

        queue->tail = queue->head;

        queue->head->next = NULL;

        return 1;
    }
    else
        return 0;
}

int Enter(Queue *queue, QueueNode x)      //入队列操作
{
    QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
    if (p == NULL)
        return 0;
    else
    {
        p->PCB.name = x.PCB.name;
        p->PCB.cpu_time = x.PCB.cpu_time;
        p->PCB.state = x.PCB.state;
        p->next = NULL;
        queue->tail->next = p;
        queue->tail = p;
        return 1;
    }
}

void Display(Queue *q)             //遍历进程的信息
{
    QueueNode *p = q->head->next;
    while (p != q->tail->next)
    {
        printf("*************\n");
        printf("进程的名称:%c\n", p->PCB.name);
        printf("进程的需要的CPU个数:%d\n", p->PCB.cpu_time);
        printf("进程的状态:%d\n", p->PCB.state);
        printf("*************\n");
        p = p->next;
    }
}

void createq()        //创建进程信息
{

    QueueNode *p;
    PCB_type *pcb;
    p = (QueueNode *)malloc(sizeof(QueueNode));
    pcb = (PCB_type *)malloc(sizeof(PCB_type));
    printf("请输入进程名，进程所需CPU时间片个数，进程状态(最后一个进程后面输入!结束):\n");
    int f = 1;
    char c='0';
    while (f)
    {
        scanf("%c %d %d", &pcb->name, &pcb->cpu_time, &pcb->state);
        if (c!='!')
        {
            p->PCB.name = pcb->name;
            p->PCB.cpu_time = pcb->cpu_time;
            p->PCB.state = pcb->state;

            if (pcb->state == 2)    //如果状态为2，入执行队列
            {
                Enter(&runq, *p);
            }
            if (pcb->state == 1)//如果状态为1，入就绪队列
            {
                Enter(&rq, *p);
            }
            if (pcb->state == 0)  //如果状态为0，入阻塞队列
                Enter(&bq, *p);
            c = getchar();
            if(c=='!')
                f = 0;
        }
        else
            break;
    }
    Display(&rq);
    Display(&bq);
}

QueueNode *deleteq(Queue *queue)//出队列操作
{
    QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
    if (queue->head == queue->tail)
    {
        deletestate = 0;
    }
    else
    {

        p = queue->head->next;
        queue->head->next = p->next;
        if (queue->tail == p)
        {
            queue->head = queue->tail;
        }
        deletestate = 1;
    }
    return p;
}

int empty(Queue *queue)//判断是否为空操作
{
    int judge;
    if (queue->head == queue->tail)
        judge = 0;
    else
        judge = 1;
    return judge;
}

void dispatch() //模拟调度函数
{
    int count = 0, i = 0;
    char name[20];
    int f1, f2;
    QueueNode *p;
    while (1)
    {
        if (empty(&rq) || empty(&bq))
        {
            if (empty(&rq))
            {
                p = (QueueNode *)malloc(sizeof(QueueNode));
                p = deleteq(&rq);
                f1 = Enter(&runq, *p);
                if (f1)
                {
                    printf("进程%c调度成功,就绪-->运行!\t", p->PCB.name);
                    p->PCB.state = 2;
                    printf("状态变为:%d\n", p->PCB.state);
                    p->PCB.cpu_time--;
                    name[i++] = p->PCB.name;
                }
                if (p->PCB.cpu_time > 0)
                {
                    p->PCB.state = 1;
                    f1 = Enter(&rq, *p);
                    if (f1)

                        printf("进程%c调度成功,运行-->就绪!\t", p->PCB.name);
                    printf("状态变为:%d\n", p->PCB.state);
                }
                else
                    free(p);
            }
            count++;
            if (count == counter)
            {
                if (empty(&bq))
                {
                    p = deleteq(&bq);
                    f2 = Enter(&rq, *p);
                    if (f2)
                    {
                        printf("进程%c调度成功,阻塞-->就绪!\t", p->PCB.name);
                    }
                    p->PCB.state = 1;
                    printf("状态变为:%d\n", p->PCB.state);
                    count = 0;
                }
            }
           
        }
         else
            break;
        
    }
    printf("执行系列为:\n");
    for (int j = 0; j < i; j++)
    {
        printf("%c", name[j]);
    }
    printf("\n");
}

int main()
{
    Init(&rq);
    Init(&bq);
    Init(&runq);
    printf("初始化队列完成\n");
    createq();
    dispatch();
    system("pause");
    return 0;
}