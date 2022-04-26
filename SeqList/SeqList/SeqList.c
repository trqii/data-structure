#include "SeqList.h"

// 顺序表初始化
void SeqListInit(SL* ps)
{
	assert(ps != NULL); // 防止传入空指针

	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

// 检察容量
void SeqListCheckCapacity(SL* ps)
{
	assert(ps != NULL); // 防止传入空指针

	// 检察容量空间，满了扩容
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

// 顺序表尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	//assert(ps != NULL); // 防止传入空指针

	//SeqListCheckCapacity(ps);

	//ps->a[ps->size] = x;
	//ps->size++; 

	SeqListInsert(ps, ps->size, x);
}

// 顺序表头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	//assert(ps != NULL); // 防止传入空指针

	//SeqListCheckCapacity(ps);

	//// 挪动数据
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

// 顺序表尾删
void SeqListPopBack(SL* ps)
{
	//assert(ps != NULL); // 防止传入空指针

	//// 温柔检察
	////if (ps->size == 0)
	////{
	////	printf("SeqList is empty\n");
	////	return;
	////}

	//// 暴力检察
	//assert(ps->size > 0);

	//ps->size--;

	SeqListErase(ps, ps->size - 1);
}

// 顺序表头删
void SeqListPopFront(SL* ps)
{
	//assert(ps != NULL); // 防止传入空指针
	//assert(ps->size > 0);

	//for (int i = 0; i < ps->size - 1; i++)
	//{
	//	ps->a[i] = ps->a[i + 1];
	//}

	//ps->size--;

	SeqListErase(ps, 0);
}

// 顺序表任意位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps != NULL); // 防止传入空指针
	assert(pos >= 0 && pos <= ps->size);

	SeqListCheckCapacity(ps);

	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}

	ps->a[pos] = x;
	ps->size++;

}

// 顺序表任意位置删除
void SeqListErase(SL* ps, int pos)
{
	assert(ps != NULL); // 防止传入空指针
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}

	ps->size--;
}

// 顺序表查找
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps != NULL); // 防止传入空指针

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i; // 找到了，返回下标
	}

	return -1; // 未找到
}

// 顺序表修改
void SeqListModify(SL* ps, int pos, SLDataType x)
{
	assert(ps != NULL); // 防止传入空指针
	assert(pos >= 0 && pos < ps->size);

	ps->a[pos] = x;
}


// 顺序表打印
void SeqListPrint(SL* ps)
{
	assert(ps != NULL); // 防止传入空指针

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// 顺序表销毁
void SeqListDestory(SL* ps)
{
	assert(ps != NULL); // 防止传入空指针

	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}