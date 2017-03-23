#include "Seqlist.h"

void menu()
{
	printf("************************************************\n");
	printf("*                                              *\n");
	printf("*     1. 头插法插入数据                        *\n");//0
	printf("*     2. 头删法删除数据                        *\n");//1
	printf("*     3. 尾插法插入数据                        *\n");
	printf("*     4. 尾删法删除数据                        *\n");
	printf("*     5. 任意位置插入数据                      *\n");
	printf("*     6. 任意位置删除数据                      *\n");
	printf("*     7. 查找数据返回下标                      *\n");
	printf("*     8. 删除第一个查找到的数字                *\n");
	printf("*     9. 删除所有查找到的数字                  *\n");
	printf("*     10.判空                                  *\n");
	printf("*     11.打印顺序表                            *\n");
	printf("*     12.退出                                  *\n");
	printf("*                                              *\n");
	printf("************************************************\n");
	printf("请选择->");
}

int main()
{
	SeqList seq; 
	PSeqList psq=&seq;
	char ch='y';
	int  flag=0;
	DataType data=0;
	int pos=0;
	InitSeqList(psq);//初始化顺序表	
	while(ch=='y')
	{
		menu();
		scanf("%d",&flag);
		switch(flag)
		{
		case 1:
				printf("请输入数据：");
				scanf("%d",&data);
				PushBack(psq,data);
				PrintSeqList(psq);
				break;
		case 2:
				PopBack(psq);
				PrintSeqList(psq);
				break;
		case 3:
				printf("请输入数据：");
				scanf("%d",&data);
				PushFront(psq,data);
				PrintSeqList(psq);
				break;
		case 4:
				PopFront(psq);
				PrintSeqList(psq);
				break;
		case 5:
				printf("请输入下标：");
				scanf("%d",&pos);
				printf("请输入数据：");
				scanf("%d",&data);
				Insert(psq,pos,data);
				PrintSeqList(psq);
				break;
		case 6:
				printf("请输入下标：");
				scanf("%d",&pos);
				Erase(psq, pos);
				PrintSeqList(psq);
				break;
		case 7:
				printf("请输入数据：");
				scanf("%d",&data);
				printf("%d\n",Find(psq,data));
				PrintSeqList(psq);
				break;
		case 8:
				printf("请输入数据：");
				scanf("%d",&data);
				Remove(psq,data);
				PrintSeqList(psq);
				break;
		case 9:
				printf("请输入数据：");
				scanf("%d",&data);
				RemoveAll(psq,data);
				PrintSeqList(psq);
				break;
		case 10:
				if(Empty(psq))
					printf("顺序表为空\n");
				else
					printf("顺序表不为空\n");
		case 11:
				PrintSeqList(psq);
				break;
		case 12:
				ch=0;
				break;
		default:
				printf("输入有误！！请重新输入\n");
		}
	}
	return 0;
}