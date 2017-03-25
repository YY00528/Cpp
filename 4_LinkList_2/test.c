#include "LinkedList.h"

void menu()
{
	printf("************************************************\n");
	printf("*                                              *\n");
	printf("*     1. 头插法插入数据                        *\n");//1
	printf("*     2. 头删法删除数据                        *\n");//1
	printf("*     3. 尾插法插入数据                        *\n");//1
	printf("*     4. 尾删法删除数据                        *\n");//1
	printf("*     5. 打印链表                              *\n");//1
	printf("*     6. 插入结点                              *\n");//1
	printf("*     7. 删除链表Pos位置的元素                 *\n");//
	printf("*     8. 删除链表中第一个值为data的元素        *\n");
	printf("*     9. 删除链表中所有值为Data的元素          *\n");
	printf("*     10.求链表中结点的个数                    *\n");
	printf("*     11.链表是否为空                          *\n");
	printf("*     12.退出                                  *\n");
	printf("*                                              *\n");
	printf("************************************************\n");
	printf("请选择->");
}

int main()
{
	PNode pHead=NULL;
	char ch='y';
	int  flag=0;
	DataType data=0,data1=0;
	int pos=0;
	InitList(&pHead);//初始化顺序表	
	while(ch=='y')
	{
		menu();
		scanf("%d",&flag);
		switch(flag)
		{
		case 1:
				printf("请输入数据：");
				scanf("%d",&data);
				PushFront(&pHead,data);
				PrintList(pHead);
				break;
		case 2:
				PopFront(&pHead);
				PrintList(pHead);
				break;
		case 3:
				printf("请输入数据：");
				scanf("%d",&data);
				PushBack(&pHead,data);
				PrintList(pHead);
				break;
		case 4:
				PopBack(&pHead);
				PrintList(pHead);
				break;
		case 5:
				PrintList(pHead);
				break;
		case 6:
				printf("请输入要插入结点位置数据：\n");
				scanf("%d",&data);
				printf("请输入要插入的数据\n");
				scanf("%d",&data1);
				Insert( Find( &pHead,data),data1);
				PrintList(pHead);
				break;
		case 7:
				printf("请输入要删除结点位置数据：\n");
				scanf("%d",&data);
				Erase(&pHead,Find( &pHead,data));
				PrintList(pHead);
				break;
		case 8:
				printf("请输入要删除的结点数据\n");
				scanf("%d",&data);
				Remove(&pHead,data);
				PrintList(pHead);
				break;
		case 9:
				printf("请输入要删除的结点数据\n");
				scanf("%d",&data);
				RemoveAll(&pHead,data);
				PrintList(pHead);
				break;
		case 11:
				if(Empty(pHead))
				{
					printf("链表为空！\n");
				}
				else
				{
					printf("链表不为空！\n");
				}
				break;
		case 10:
				printf("链表中共有%d个结点\n",Size(pHead));
				break;
		case 12:
				ch=0;
				break;
		default:
				printf("输入有误！！请重新输入\n");
				break;
		}
	}
	Destroy(&pHead);
	return 0;
}