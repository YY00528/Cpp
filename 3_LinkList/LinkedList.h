#ifndef _LinkedList__H_
#define _LinkedList__H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Node
{
	int data;
	struct Node* next;   // 下一个结点的地址
}Node, *PNode;


void InitList(PNode* pHead);//初始化链表
void PushBack(PNode* pHead, DataType data);//尾插
void PopBack(PNode* pHead);//尾删
void PushFront(PNode* pHead, DataType data);//头插
void PopFront(PNode* pHead);//头删
PNode Find(PNode* pHead, DataType data);//查找结点
void Insert(PNode pos, DataType data);//插入节点
PNode BuyNode(DataType data);//申请新节点
void PrintList(PNode pHead);//打印链表
//////////////////////////////////////////////
void Erase(PNode* pHead, PNode pos);// 删除链表Pos位置的元素
void Remove(PNode* pHead, DataType data);// 删除链表中第一个值为data的元素
void RemoveAll(PNode* pHead, DataType data);// 删除链表中所有值为Data的元素
void Destroy(PNode* pHead);// 销毁链表
int Empty(PNode pHead);// 链表是否为空
int Size(PNode pHead);// 求链表中结点的个数
#endif//_LinkedList__H_