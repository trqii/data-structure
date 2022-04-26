#include "SeqList.h"

// ˳����ʼ��
void SeqListInit(SL* ps)
{
	assert(ps != NULL); // ��ֹ�����ָ��

	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

// �������
void SeqListCheckCapacity(SL* ps)
{
	assert(ps != NULL); // ��ֹ�����ָ��

	// ��������ռ䣬��������
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}

// ˳���β��
void SeqListPushBack(SL* ps, SLDataType x)
{
	//assert(ps != NULL); // ��ֹ�����ָ��

	//SeqListCheckCapacity(ps);

	//ps->a[ps->size] = x;
	//ps->size++; 

	SeqListInsert(ps, ps->size, x);
}

// ˳���ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
	//assert(ps != NULL); // ��ֹ�����ָ��

	//SeqListCheckCapacity(ps);

	//// Ų������
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}

	//ps->a[0] = x;
	//ps->size++;

	SeqListInsert(ps, 0, x);
}

// ˳���βɾ
void SeqListPopBack(SL* ps)
{
	//assert(ps != NULL); // ��ֹ�����ָ��

	//// ������
	////if (ps->size == 0)
	////{
	////	printf("SeqList is empty\n");
	////	return;
	////}

	//// �������
	//assert(ps->size > 0);

	//ps->size--;

	SeqListErase(ps, ps->size - 1);
}

// ˳���ͷɾ
void SeqListPopFront(SL* ps)
{
	//assert(ps != NULL); // ��ֹ�����ָ��
	//assert(ps->size > 0);

	//for (int i = 0; i < ps->size - 1; i++)
	//{
	//	ps->a[i] = ps->a[i + 1];
	//}

	//ps->size--;

	SeqListErase(ps, 0);
}

// ˳�������λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps != NULL); // ��ֹ�����ָ��
	assert(pos >= 0 && pos <= ps->size);

	SeqListCheckCapacity(ps);

	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}

	ps->a[pos] = x;
	ps->size++;

}

// ˳�������λ��ɾ��
void SeqListErase(SL* ps, int pos)
{
	assert(ps != NULL); // ��ֹ�����ָ��
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}

	ps->size--;
}

// ˳������
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps != NULL); // ��ֹ�����ָ��

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i; // �ҵ��ˣ������±�
	}

	return -1; // δ�ҵ�
}

// ˳����޸�
void SeqListModify(SL* ps, int pos, SLDataType x)
{
	assert(ps != NULL); // ��ֹ�����ָ��
	assert(pos >= 0 && pos < ps->size);

	ps->a[pos] = x;
}


// ˳����ӡ
void SeqListPrint(SL* ps)
{
	assert(ps != NULL); // ��ֹ�����ָ��

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// ˳�������
void SeqListDestory(SL* ps)
{
	assert(ps != NULL); // ��ֹ�����ָ��

	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}