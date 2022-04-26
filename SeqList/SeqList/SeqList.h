#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#define N 200
//typedef int SLDataType;
//
//// ˳���ľ�̬�洢 -- N̫С�����ܲ����ã�N̫�󣬿����˷ѿռ�
//struct SeqList
//{
//	SLDataType a[N]; // ��������
//	int size;        // ���ݸ���
//};


typedef int SLDataType;

// ˳���Ķ�̬�洢
typedef struct SeqList
{
	SLDataType* a; // ָ��̬����ָ��
	int size;	   // ���ݸ���
	int capacity;  // �����ռ��С
} SL;


// ˳����ʼ��
void SeqListInit(SL* ps);

// �������
void SeqListCheckCapacity(SL* ps);

// ˳���β��
void SeqListPushBack(SL* ps, SLDataType x);

// ˳���ͷ��
void SeqListPushFront(SL* ps, SLDataType x);

// ˳���βɾ
void SeqListPopBack(SL* ps);

// ˳���ͷɾ
void SeqListPopFront(SL* ps);

// ˳�������λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x);

// ˳�������λ��ɾ��
void SeqListErase(SL* ps, int pos);

// ˳������
int SeqListFind(SL* ps, SLDataType x);

// ˳����޸�
void SeqListModify(SL* ps, int pos, SLDataType x);

// ˳����ӡ
void SeqListPrint(SL* ps);

// ˳�������
void SeqListDestory(SL* ps);