#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#define N 200
//typedef int SLDataType;
//
//// 顺序表的静态存储 -- N太小，可能不够用，N太大，可能浪费空间
//struct SeqList
//{
//	SLDataType a[N]; // 定长数组
//	int size;        // 数据个数
//};


typedef int SLDataType;

// 顺序表的动态存储
typedef struct SeqList
{
	SLDataType* a; // 指向动态数组指针
	int size;	   // 数据个数
	int capacity;  // 容量空间大小
} SL;


// 顺序表初始化
void SeqListInit(SL* ps);

// 检察容量
void SeqListCheckCapacity(SL* ps);

// 顺序表尾插
void SeqListPushBack(SL* ps, SLDataType x);

// 顺序表头插
void SeqListPushFront(SL* ps, SLDataType x);

// 顺序表尾删
void SeqListPopBack(SL* ps);

// 顺序表头删
void SeqListPopFront(SL* ps);

// 顺序表任意位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x);

// 顺序表任意位置删除
void SeqListErase(SL* ps, int pos);

// 顺序表查找
int SeqListFind(SL* ps, SLDataType x);

// 顺序表修改
void SeqListModify(SL* ps, int pos, SLDataType x);

// 顺序表打印
void SeqListPrint(SL* ps);

// 顺序表销毁
void SeqListDestory(SL* ps);