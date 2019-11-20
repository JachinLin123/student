#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*为系统中允许的最多进程数*/
#define maxPCB 5
/*为系统中可能最多的空闲分区数*/
#define maxPart 5
typedef struct PCB_type
{
   char name;   //进程名
   int adderss; //进程所占分区的起始地址
   int len;     //所占长度
   int valid;   //有效标识符
} PCB;

typedef struct seqlist
{
   PCB PCBelem[maxPCB];
   int total; //系统中实际的进程数
} PCBseql;

/*分区类型及内存空闲分区表 */
typedef struct Partition
{
   int address; //进程起始地址
   int len;     //进程长度
   int valid;   //有效标识符
} Part;

typedef struct Partlist
{
   Part Partelem[maxPart];
   int sum; //实际分区数
} Partseql;

PCBseql *pcbl;
Partseql *partl;
int count = 0;
int pcb = 0;
/*初始化进程表*/
void InitPCB()
{
   pcbl = (PCBseql *)malloc(sizeof(PCBseql));
   pcbl->total = 0;
}
/*初始化进程分区表*/
void InitPart()
{
   partl = (Partseql *)malloc(sizeof(Partseql));
   partl->sum = 1;
   partl->Partelem[0].address = 40;
   partl->Partelem[0].len = 600;
   partl->Partelem[0].valid = 1;
}
/*进程请求空间*/
void request(char name, int len)
{
   for (int i = partl->sum - 1; i >= 0; i--)
   {
      if (partl->Partelem[i].len >= len)
      {
         pcbl->PCBelem[pcb].adderss = partl->Partelem[i].address;
         partl->Partelem[i].address += len;
         pcbl->PCBelem[pcb].len = len;
         partl->Partelem[i].len -= len;
         pcbl->PCBelem[pcb].name = name;
         pcbl->PCBelem[pcb].valid = 1;
         pcb++;
         pcbl->total++;
         break;
      }
      else
      {
         printf("内存分配不足!\n");
         break;
      }
   }
}
/*进程释放空间*/
void release(char name)
{
   int flag = 0;
   for (int i = 0; i <= maxPCB; i++)
   {
      if ((pcbl->PCBelem[i].name == name) && pcbl->PCBelem[i].valid != 0)
      {
         flag = 1;
         printf("进程%c释放成功\n", name);
         partl->sum++;
         pcbl->PCBelem[i].valid = 0;
         partl->Partelem[partl->sum - 1].address = pcbl->PCBelem[i].adderss;
         partl->Partelem[partl->sum - 1].len = pcbl->PCBelem[i].len;
         partl->Partelem[partl->sum - 1].valid = 1;
         pcbl->total--;
         break;
      }
   }
   if (!flag)
   {
      printf("不存在此进程!\n");
   }
   /*按地址排序*/
   if (flag)
   {
      for (int i = 0; i < partl->sum - 1; i++)
      {
         for (int j = 0; j < partl->sum - 1 - i; j++)
         {
            if (partl->Partelem[j].address > partl->Partelem[j + 1].address)
            {
               int temp1 = partl->Partelem[j].address;
               int temp2 = partl->Partelem[j].len;
               partl->Partelem[j].address = partl->Partelem[j + 1].address;
               partl->Partelem[j].len = partl->Partelem[j + 1].len;
               partl->Partelem[j + 1].address = temp1;
               partl->Partelem[j + 1].len = temp2;
            }
         }
      }
   }
   /*合并相邻的空闲分区*/
   if (partl->sum >= 2)
   {
      for (int i = 0; i < partl->sum; i++)
      {
         for (int j = i+1; j < partl->sum; j++)
         {
            if (((partl->Partelem[i].address + partl->Partelem[i].len) == partl->Partelem[j].address)&&partl->Partelem[j].valid!=0)
            {
               int temp = partl->Partelem[j].len + partl->Partelem[i].len;
               partl->Partelem[i].len = temp;
               partl->Partelem[j].len = temp;
               partl->Partelem[j].address = partl->Partelem[i].address;
               partl->Partelem[j].valid=0;
            }
         }
      }
   }
}
/*输出内存空闲分区*/
void print()
{
   count++;
   for (int i = 0; i < partl->sum; i++)
   {
      if (partl->Partelem[i].valid)
      {
         printf("t%d时刻空闲分区:地址%d  长度%d\n", count, partl->Partelem[i].address, partl->Partelem[i].len);
      }
   }
}
/*主函数*/
int main()
{
   char c, name1, name2;
   int len;
   InitPCB();
   InitPart();
   printf("----------r:请求内存分配----------\n");
   printf("----------s:释放内存空间----------\n");
   printf("----------p:输出空闲分区----------\n");
   printf("----------e:   退 出   ----------\n");
   printf("请输入你要进行的操作!\n");
   while (1)
   {
      fflush(stdin);
      scanf("%c", &c);
      fflush(stdin);
      if (c == 'e')
         break;
      switch (c)
      {
      case 'r':
         //printf("请输入作业的名称和所需分配的长度:\n");
         fflush(stdin);
         scanf("%c%d", &name1, &len);
         fflush(stdin);
         request(name1, len);
         break;
      case 's':
         //printf("请输入要释放进程的名称:\n");
         fflush(stdin);
         scanf("%c", &name2);
         fflush(stdin);
         release(name2);
         break;
      case 'p':
         //printf("打印出空闲分区\n");
         print();
         break;
      default:
         printf("你输入的选择有误!\n");
         break;
      }
   }
   return 0;
}