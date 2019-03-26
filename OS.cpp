#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PCB_type
{
    char name;    //������
    int state;    //����״̬ ; 2--��ʾ"ִ��"״̬; 1--��ʾ"����"״̬; 0--��ʾ"����"״̬
    int cpu_time; //������Ҫ��CPUʱ�䣨�����е�ʱ��Ƭ������
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

Queue rq, bq, runq; //ready���С�blocked���С�run����

int deletestate = 0;
int ready = 2;
int blocked = 3;
int counter = 5;

int Init(Queue *queue)           //��ʼ������
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

int Enter(Queue *queue, QueueNode x)      //����в���
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

void Display(Queue *q)             //�������̵���Ϣ
{
    QueueNode *p = q->head->next;
    while (p != q->tail->next)
    {
        printf("*************\n");
        printf("���̵�����:%c\n", p->PCB.name);
        printf("���̵���Ҫ��CPU����:%d\n", p->PCB.cpu_time);
        printf("���̵�״̬:%d\n", p->PCB.state);
        printf("*************\n");
        p = p->next;
    }
}

void createq()        //����������Ϣ
{

    QueueNode *p;
    PCB_type *pcb;
    p = (QueueNode *)malloc(sizeof(QueueNode));
    pcb = (PCB_type *)malloc(sizeof(PCB_type));
    printf("���������������������CPUʱ��Ƭ����������״̬(���һ�����̺�������!����):\n");
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

            if (pcb->state == 2)    //���״̬Ϊ2����ִ�ж���
            {
                Enter(&runq, *p);
            }
            if (pcb->state == 1)//���״̬Ϊ1�����������
            {
                Enter(&rq, *p);
            }
            if (pcb->state == 0)  //���״̬Ϊ0������������
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

QueueNode *deleteq(Queue *queue)//�����в���
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

int empty(Queue *queue)//�ж��Ƿ�Ϊ�ղ���
{
    int judge;
    if (queue->head == queue->tail)
        judge = 0;
    else
        judge = 1;
    return judge;
}

void dispatch() //ģ����Ⱥ���
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
                    printf("����%c���ȳɹ�,����-->����!\t", p->PCB.name);
                    p->PCB.state = 2;
                    printf("״̬��Ϊ:%d\n", p->PCB.state);
                    p->PCB.cpu_time--;
                    name[i++] = p->PCB.name;
                }
                if (p->PCB.cpu_time > 0)
                {
                    p->PCB.state = 1;
                    f1 = Enter(&rq, *p);
                    if (f1)

                        printf("����%c���ȳɹ�,����-->����!\t", p->PCB.name);
                    printf("״̬��Ϊ:%d\n", p->PCB.state);
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
                        printf("����%c���ȳɹ�,����-->����!\t", p->PCB.name);
                    }
                    p->PCB.state = 1;
                    printf("״̬��Ϊ:%d\n", p->PCB.state);
                    count = 0;
                }
            }
           
        }
         else
            break;
        
    }
    printf("ִ��ϵ��Ϊ:\n");
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
    printf("��ʼ���������\n");
    createq();
    dispatch();
    system("pause");
    return 0;
}