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
			new_node->next=NULL;
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
			count_node->next=new_node;
			new_node->next=NULL;
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
	else if(!(*pHead)->next)
	{
		free((*pHead));
		*pHead=NULL;
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
	if(NULL==*pHead)
	{
		return NULL;
	}
	while(count_node)
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
	if(NULL==pos)
	{
		printf("未找到此节点！\n");
		return;
	}
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
	new_node->data=data;
	return new_node;
}
void PrintList(PNode pHead)//打印链表
{
	PNode count_node=pHead;
	if(count_node!=NULL)
	{
		if(count_node->next==NULL)
			printf("%d->",count_node->data);
		else
		{
			while(count_node)
			{
				printf("%d->",count_node->data);
				count_node=count_node->next;
			}
		}
		printf("NULL");
	}
	else
	{
		printf("所选链表为!!\n");
	}
	printf("\n");
	return ;
}
//////////////////////////////////////////////
void Erase(PNode* pHead, PNode pos)// 删除链表Pos位置的元素
{
	PNode count_node=*pHead;
	//PNode pre_count_node=pos;
	if(NULL==pos)
	{
		printf("未找到此节点！\n");
		return;
	}
	if(*pHead==pos)
	{
		*pHead=pos->next;
		free(pos);
		return;
	}
	else
	{
		while(count_node->next!=pos&&count_node!=NULL)
		{
			count_node=count_node->next;
		}
	}
	
	if(NULL==count_node)
	{
		printf("未找到此节点！\n");
		return;
	}
	else if(count_node->next==pos)
	{
		count_node->next=pos->next;
		free(pos);
	}
}
void Remove(PNode* pHead, DataType data)// 删除链表中第一个值为data的元素
{
	PNode Pos=Find(pHead,data);
	Erase(pHead,Pos);
}
void RemoveAll(PNode* pHead, DataType data)// 删除链表中所有值为Data的元素
{
	PNode Pos=Find(pHead,data);
	Erase(pHead,Pos);
	while(Pos=Find(pHead,data))
	{
		Erase(pHead,Pos);
	}
}
void Destroy(PNode* pHead)// 销毁链表
{
	while(*pHead!=NULL)
	{
		PopFront(pHead);
	}
}
int Empty(PNode pHead)// 链表是否为空
{
	if(pHead!=NULL)
	{
		return 0;
	}
	else
	{
		return 1;//为空
	}
}
int Size(PNode pHead)// 求链表中结点的个数
{
	int LinkedList_size=1;
	PNode count_node=pHead;
	while(count_node->next)
	{
		count_node=count_node->next;
		LinkedList_size++;
	}
	return LinkedList_size;
}