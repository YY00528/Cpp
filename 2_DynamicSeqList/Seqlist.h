#ifndef _Sqlist__H_
#define _Sqlist__H_
#define INITSIZE 3
#define EXPORTSIZE 2
#define DataType int

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct SeqList
{
	DataType *array;
	int size;     // 记录有效元素的个数
	int capacity;//空间总大小
}SeqList,*PSeqList;
typedef enum
{
	DESC,
	ASC
}SORT;
//typedef struct SeqList SeqList;


void InitSeqList(PSeqList psq);//初始化顺序表
//////////////////////////////////////////////////////////////////新增功能////////////////////////////
int CheckCapacity(PSeqList psq);//检查空间
void DestroySeqList(PSeqList psq);//销毁顺序表
void BubbleSort(PSeqList psq,SORT s);//冒泡排序
void SelectSort(PSeqList psq,SORT s);//选择排序
int BinarySearch(PSeqList psq, DataType data);//二分查找
////////////递归实现二分查找
int BinarySearchRecursion(int left,int right,PSeqList psq, DataType data);//二分查找
int Size(PSeqList psq);//返回顺序表元素个数
void Clear(PSeqList psq);//清空顺序表
//////////////////////////////////////////////////////////////////
void PushBack(PSeqList psq, DataType data);//头插
void PopBack(PSeqList psq);//头删
void PushFront(PSeqList psq, DataType data);//尾插
void PopFront(PSeqList psq);//尾删
void Insert(PSeqList psq, int pos, DataType data);//任意插入
void Erase(PSeqList psq, int pos);//按下标删除
int Find(PSeqList psq, DataType data);//查找
void Remove(PSeqList psq, DataType data);//删除第一个查找到的数字
void RemoveAll(PSeqList psq, DataType data);//删除所有查找到的数字
int Empty(PSeqList psq);//判空
void PrintSeqList(PSeqList psq);//打印

#endif//_Sqlist__H_