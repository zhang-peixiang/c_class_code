#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SDataType;
//typedef double SDataType;

typedef struct SeqList
{
	SDataType* array;     // ���Ԫ�صĿռ䣬����ʱ��������
	int capacity;   // �ռ��ܵĴ�С
	int size;       // �ռ�����ЧԪ�صĸ���
}SeqList;


// typedef struct SeqList SeqList;

//��ʼ��
void SeqListInit(SeqList* s, int initCapacity);

// β��
void SeqListPushBack(SeqList* s, SDataType data);

// βɾ
void SeqListPopBack(SeqList* s);

// ͷ��
void SeqListPushFront(SeqList* s, SDataType data);

// ͷɾ
void SeqListPopFront(SeqList* s);

// ����λ�ò���
void SeqListInsert(SeqList* s, int pos, SDataType data);

// ����λ��ɾ��
void SeqListErase(SeqList* s, int pos);

// ��ȡ˳�������ЧԪ�ظ���
int SeqListSize(SeqList* s);

// ��ȡ˳���������
int SeqListCapacity(SeqList* s);

// ���˳����Ƿ�Ϊ��
int SeqListEmpty(SeqList* s);

// ���
void SeqListClear(SeqList* s);

// ����ֵΪdata��Ԫ���Ƿ���˳����У�����ڷ����±꣬���򷵻�-1
int SeqListFind(SeqList* s, SDataType data);

// ����
void SeqListDestroy(SeqList* s);



//////////////////////////////////////////////////////
// ���Է���
void TestSeqList();