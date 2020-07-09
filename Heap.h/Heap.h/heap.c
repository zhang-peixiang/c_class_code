#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"

int Less(HDataType left, HDataType right)
{
	return left < right;
}
int Greater(HDataType left, HDataType right)
{
	return left > right;
}


//��ʼ����
void HeapInit(Heap* hp, int initCap,CMP cmp)
{
	assert(hp);
	initCap = initCap < 10 ? 10 : initCap;
	hp->array = (HDataType*)malloc(sizeof(HDataType)*initCap);
	if (hp->array == NULL)
	{
		assert(0);
		return;
	}

	hp->capacity = initCap;
	hp->size = 0;
	hp->cmp = cmp;
}

void Swap(HDataType* left, HDataType* right)
{
	HDataType tmp = *left;
	*left = *right;
	*right = tmp;
}

void AdjustDown(Heap* hp, int parent)
{
	HDataType* array = hp->array;
	int size = hp->size;
	CMP cmp = hp->cmp;
	//��child���parent�Ľ�С�ĺ���--Ĭ���ȱ��parent������
	int child = parent * 2 + 1;
	while (child < size)
	{
		//�ҵ�parent���������н�С�ĺ���
		if (child + 1 < size && cmp(array[child + 1],array[child]))
		{
			child += 1;
		}
		//parent��С�ĺ����Ѿ��ҵ�
		//���parnt�Ƿ�����ѵ�����

		if (cmp(array[child] ,array[parent]))
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}


//�������е�Ԫ�ش�����
void HeapCreate(Heap* hp, HDataType* array, int size,CMP cmp)
{
	int root = 0;
	//1.�Ƚ������е�Ԫ�ط��ڶѽṹ��
	HeapInit(hp, size,cmp);
	memcpy(hp->array, array, sizeof(HDataType)*size);
	hp->size = size;
	//2.���е���
	for (root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp, root);
	}
}
void CheckCapacity(Heap* hp)
{
	if (hp->size == hp->capacity)
	{
		HDataType* tmp = (HDataType*)malloc(sizeof(HDataType)*hp->size * 2);

		if (tmp != NULL)
		{
			hp->array = tmp;
			hp->capacity = hp->size * 2;
		}
	}
}

void AdjustUP(Heap* hp,int child)
{
	HDataType* array = hp->array;
	int size = hp->size;
	CMP cmp = hp->cmp;
	int parent = (child - 1) / 2;
	while (parent >= 0)
	{
		if (cmp(array[child] ,array[parent]))
		{
			Swap(&array[child], &array[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HeapPush(Heap* hp, HDataType data)
{
	//0.����Ƿ���Ҫ����
	CheckCapacity(hp);

	//1.����Ԫ�ز��뵽�����ĩβ����������Ԫ�ز��뵽��ȫ�����������
	hp->array[hp->size++] = data;

	//2.��Ԫ�ز���󣬿��ܻ��ƻ��ѵ�����
	AdjustUP(hp, hp->size - 1);

}
void HeapPop(Heap* hp)
{
	if (HeapEmpty(hp))
		return;
	 
	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;

	AdjustDown(hp, 0);
}


HDataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}


void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}



void TestHeap()
{
	int array[] = { 3, 6, 9, 1, 5, 3, 0, 7, 8, 4 };
	Heap hp;
	HeapCreate(&hp, array, sizeof(array) / sizeof(array[0]),Greater);
	printf("heap size = %d\n", HeapSize(&hp));
	printf("heap top = %d\n", HeapTop(&hp));

	HeapPop(&hp);
	printf("heap size = %d\n", HeapSize(&hp));
	printf("heap top = %d\n", HeapTop(&hp));

	HeapPush(&hp, -1);

	HeapDestroy(&hp);
}