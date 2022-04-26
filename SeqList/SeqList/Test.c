#include "SeqList.h"

void TestSeqList()
{
	SL sl;

	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListInsert(&sl, 0, 3);
	SeqListInsert(&sl, 0, 2);
	SeqListPrint(&sl);

	SeqListErase(&sl, 1);
	SeqListPrint(&sl);

	int pos = SeqListFind(&sl, 3);
	if (pos != -1)
	{
		SeqListModify(&sl, pos, 5);
	}
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

int main()
{
	
	TestSeqList();

	return 0;
}