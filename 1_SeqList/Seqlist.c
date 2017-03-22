#include "Seqlist.h"
#define TEST

void EmptyArr(DataType arr[],int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		arr[i]=0;
	}
#ifdef TEST
	for(i=0;i<10;i++)
	{
		arr[i]=i;
	}
#endif
}
void InitSeqList(PSeqList psq)//初始化顺序表
{
	psq->size=0;
	EmptyArr(psq->array,MAX_SIZE);	
	#ifdef TEST
	psq->size=10;
	#endif
}
void PushBack(PSeqList psq, DataType data)//头插
{
	int i=0;
	if(psq->size+1>MAX_SIZE)
	{
		printf("顺序表已满！！\n");
		return ;
	}
	for(i=psq->size;i>0;i--)
	{
		psq->array[i]=psq->array[i-1];
	}
	psq->array[0]=data;
	psq->size++;
	return ;
}
void PopBack(PSeqList psq)//头删
{
	int i=0;
	if(Empty(psq))
	{
		printf("顺序表为空，操作失败！\n");
		return;
	}
	for(i=0;i<psq->size;i++)
	{
		psq->array[i]=psq->array[i+1];
	}
	psq->array[psq->size-1]=0;
	psq->size--;	
	return ;
}
void PushFront(PSeqList psq, DataType data)//尾插
{
	if(psq->size+1>MAX_SIZE)
	{
		printf("顺序表已满！！\n");
		return ;
	}
	psq->array[psq->size]=data;	
	psq->size++;		
	return ;
}
void PopFront(PSeqList psq)//尾删
{
	if(Empty(psq))
	{
		printf("顺序表为空，操作失败！\n");
		return;
	}
	psq->array[psq->size]=0;	
	psq->size--;		
	return ;
}
void Insert(PSeqList psq, int pos, DataType data)//任意插入
{
	int i=0;
	if(psq->size+1>MAX_SIZE)
	{
		printf("顺序表已满！！\n");
		return ;
	}
	for(i=psq->size;i>pos;i--)
	{
		psq->array[i]=psq->array[i-1];
	}
	psq->array[pos]=data;
	psq->size++;
	return ;
}
void Erase(PSeqList psq, int pos)//按下标删除
{
	int i=0;
	if(Empty(psq))
	{
		printf("顺序表为空，操作失败！\n");
		return;
	}
	for(i=pos;i<psq->size;i++)
	{
		psq->array[i]=psq->array[i+1];
	}
	psq->array[psq->size-1]=0;
	psq->size--;	
	return ;
}
int Find(PSeqList psq, DataType data)//查找
{
	int i=0;
	if(Empty(psq))
	{
		printf("顺序表为空，操作失败！\n");
		return;
	}
	for(i=0;i<psq->size;i++)
	{
		if(psq->array[i]==data)
			break;
	}	
	if(i==psq->size)
		i=-1;
	return i;
}
void Remove(PSeqList psq, DataType data)//删除第一个查找到的数字
{
	if(Empty(psq))
	{
		printf("顺序表为空，操作失败！\n");
		return;
	}
	Erase(psq, Find(psq,data));
}
void RemoveAll(PSeqList psq, DataType data)//删除所有查找到的数字
{
	int i=0;
	if(Empty(psq))
	{
		printf("顺序表为空，操作失败！\n");
		return;
	}
	while(i!=-1)
	{
		while(i<psq->size)
		{
			if(psq->array[i]==data)
				break;
			i++;
		}	
		if(i==psq->size)
			i=-1;
		Erase(psq, i);
	}
	return ;
}
int Empty(PSeqList psq)//判空
{
	int flag=0;
	if(psq->size==0)
		flag=1;
	else
		flag=0;
	return flag;
}
void PrintSeqList(PSeqList psq)//打印
{
	int i=0;
	for(i=0;i<psq->size;i++)
	{
		printf("%d ",psq->array[i]);
	}
	printf("\n");
}