#include "LinkedList.h"

void menu()
{
	printf("************************************************\n");
	printf("*                                              *\n");
	printf("*     0. 退出                                  *\n");
	printf("*     1. 头插法插入数据                        *\n");//1
	printf("*     2. 头删法删除数据                        *\n");//1
	printf("*     3. 尾插法插入数据                        *\n");//1
	printf("*     4. 尾删法删除数据                        *\n");//1
	printf("*     5. 打印链表                              *\n");//1
	printf("*     6. 插入结点                              *\n");//1
	printf("*     7. 删除链表Pos位置的元素                 *\n");//1
	printf("*     8. 删除链表中第一个值为data的元素        *\n");//1
	printf("*     9. 删除链表中所有值为Data的元素          *\n");//1
	printf("*     10.求链表中结点的个数                    *\n");//1
	printf("*     11.链表是否为空                          *\n");//1
	printf("*     12.倒序打印链表                          *\n");
	printf("*     13.删除一个无头链表的非尾结点            *\n");
	printf("*     14.在无头链表前插入一个结点              *\n");
	printf("*     15.单链表实现约瑟夫环                    *\n");
	printf("*     16.逆置链表				               *\n");
	printf("*     17.冒泡排序				               *\n");
	printf("*     18.合并两个有序链表                      *\n");
	printf("*     19.寻找中间元素                          *\n");
	printf("*     20.寻找倒数第k个结点                     *\n");
	printf("*     21.判断两个链表是否相交                  *\n");
	printf("*     22.判断两个链表相交的交点                *\n");
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
		case 0:
				ch=0;
				break;
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
				PrintListFromT2H(pHead);
				break;
		case 13:	
				printf("请输入要删除结点位置数据：\n");
				scanf("%d",&data);
				DeleteNotTail(Find( &pHead,data));
				PrintList(pHead);
				break;
		case 14:
				printf("请输入要插入结点位置数据：\n");
				scanf("%d",&data);
				printf("请输入要插入的数据\n");
				scanf("%d",&data1);
				InsertNotHead(pHead,Find( &pHead,data),data1);
				PrintList(pHead);
				break;
		case 15:
				JosephCircle(&pHead,3);
				PrintList(pHead);
				break;
		case 16:
				PrintList(ReverseList(pHead));
				break;
		case 17:
				BubbleSort(pHead);
				PrintList(pHead);
				break;
		case 18:
				//PrintList(MergeList(pList1,pList2));
				break;
		case 19:
				PrintList(FindMidNode(pHead));
				break;
		case 20:
				PrintList(FindLastKNode(pHead,3));
				break;
		case 21:
				//printf("%d",IsCross(PNode pHead1, PNode pHead2));
				break;
		case 22:
				//PrintList(PNode GetCrossNode(PNode pHead1, PNode pHead2));
				break;
		default:
				printf("输入有误！！请重新输入\n");
				break;
		}
	}
	Destroy(&pHead);
	return 0;
}