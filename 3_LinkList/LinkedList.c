#include "LinkedList.h"

void InitList(PNode* pHead)//初始化链表
{
	if(*pHead)
	{
		*pHead=NULL;
	}
	return ;
}
void PushBack(PNode* pHead, DataType data)//尾插
{
	PNode new_node=NULL;
	PNode count_node=*pHead;
	if(!*pHead)
	{
		new_node=BuyNode(data);
		if(new_node!=NULL){
			*pHead=new_node;
		}
		else{
			printf("空间不足，插入失败！\n");
			return;
		}
	}
	else
	{
		while(count_node->next)
		{
			count_node=count_node->next;
		}
		new_node=BuyNode(data);
		if(new_node!=NULL){
			count_node=new_node;
		}
		else{
			printf("空间不足，插入失败！\n");
			return;
		}
	}
	return;
}
void PopBack(PNode* pHead)//尾删
{
	PNode count_node=*pHead;
	if(!*pHead)
	{
		printf("所选链表为空！\n");
	}
	else
	{
		while(count_node->next->next)
		{
			count_node=count_node->next;
		}
		free(count_node->next);
		count_node->next=NULL;
	}
	return ;
}
void PushFront(PNode* pHead, DataType data)//头插
{
	PNode new_node=BuyNode(data);
	if(new_node!=NULL){
			new_node->next=*pHead;
			*pHead=new_node;
		}
	else{
			printf("空间不足，插入失败！\n");
			return;
		}
}
void PopFront(PNode* pHead)//头删
{
	if(!*pHead)
	{
		printf("所选链表为空！\n");
	}
	else
	{
		PNode count_node=*pHead;
		count_node=count_node->next;
		free(*pHead);
		*pHead=count_node;
	}
	return;
}
PNode Find(PNode* pHead, DataType data)//查找结点
{
	PNode count_node=*pHead;
	while(count_node->next)
	{
		if(count_node->data==data)
		{
			return count_node;
		}
		else
		{
			count_node=count_node->next;
		}
	}
	return NULL;
}
void Insert(PNode pos, DataType data)//插入节点
{
	PNode new_node=NULL;
	new_node= BuyNode(data);
	if(new_node!=NULL)
	{
		new_node->next=pos->next;
		pos->next=new_node;
	}
	else
	{
		printf("空间不足，插入失败！\n");
		return;
	}
}
PNode BuyNode(DataType data)//申请新节点
{
	PNode new_node=(PNode)malloc(sizeof(Node));
	return new_node;
}
void PrintList(PNode pHead)//打印链表
{
	PNode count_node=pHead;
	while(count_node->next)
	{
		printf("%d ",count_node->data);
		count_node=count_node->next;
	}
	printf("\n");
	return ;
}
//////////////////////////////////////////////
void Erase(PNode* pHead, PNode pos);// 删除链表Pos位置的元素
void Remove(PNode* pHead, DataType data);// 删除链表中第一个值为data的元素
void RemoveAll(PNode* pHead, DataType data);// 删除链表中所有值为Data的元素
void Destroy(PNode* pHead);// 销毁链表
int Empty(PNode pHead);// 链表是否为空
int Size(PNode pHead);// 求链表中结点的个数