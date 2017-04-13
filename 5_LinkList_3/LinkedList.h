#ifndef _LinkedList__H_
#define _LinkedList__H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct Node
{
	int data;
	struct Node* radom; 
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
////////////////////////////////////////实现单链表的一下题目
void PrintListFromT2H(PNode pHead);//倒序打印链表
void DeleteNotTail(PNode pos);//删除一个无头链表的非尾结点
void InsertNotHead(PNode pHead, PNode pos, DataType data);//在无头链表前插入一个结点
void JosephCircle(PNode* pHead, int M);//单链表实现约瑟夫环
PNode ReverseList(PNode pHead);//逆置链表
void BubbleSort(PNode pHead);//冒泡排序
PNode MergeList(PNode pList1, PNode pList);//合并两个有序链表
PNode FindMidNode(PNode pHead);//只能遍历一次链表，寻找中间元素
PNode FindLastKNode(PNode pHead, int k);//寻找倒数第k个结点
//链表是否带环？
int IsCross(PNode pHead1, PNode pHead2);//判断两个链表是否相交
PNode GetCrossNode(PNode pHead1, PNode pHead2);//相交的交点
/////////////////////////////////////9.18更新
PNode HasCircle(PNode pHead);//判断是否有环
int GetCirclrLen(PNode pMeetNode);//返回环的长度
// 获取环的入口点--给出推理的过程
PNode GetEnterNode(PNode pHead, PNode pMeetNode);
//判断两个带环链表是否相交
int IsCrossWithCircle(PNode pHead1, PNode pHead2);
//求两个已排序单链表中相同的数据--打印出来
void UnionSet(Node* l1, Node* l2);
//复杂链表的赋值--给出实现原理及图解
//给出实现代码(最好都去实现下)
PNode coypComplexList(PNode pHead,PNode* newHead);//复制复杂链表
#endif//_LinkedList__H_