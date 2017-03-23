#ifndef _Sqlist__H_
#define _Sqlist__H_
#define MAX_SIZE 100
#define DataType int

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SeqList
{
	DataType array[MAX_SIZE];
	int size;     // 记录有效元素的个数
}SeqList,*PSeqList;

//typedef struct SeqList SeqList;


void InitSeqList(PSeqList psq);//初始化顺序表	
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