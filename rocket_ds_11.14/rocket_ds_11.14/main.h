//#pragma once
//
//#include <stdlib.h>
//#include <assert.h>
//#include <stdio.h>
//
//typedef int DataType;
//
//typedef struct ListNode
//{
//	DataType data;
//	struct ListNode *next;
//}	ListNode;
//
////��ʼ��
//void ListInit(ListNode **ppfirst)
//{
//	assert(ppfirst != NULL);
//	*ppfirst = NULL;
//}
//
////����
//void ListDestroy(ListNode **ppFirst)
//{
//	assert(ppFirst != NULL);
//	//1 ���ж�����
//	//2 free ������ʹ�� cur
//	ListNode *next;
//	for (ListNode *cur = *ppFirst; cur != NULL; cur = next)
//	{
//		next = cur->next;
//		free(cur);
//	}
//	*ppFirst = NULL;
//}
//
////��ɾ���
////��㴴��
//static ListNode *CreateNode(DataType data)
//{
//	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
//	assert(newNode);
//	newNode->data = data;
//	newNode->next = NULL;
//
//	return newNode;
//}
//
////ͷ��
//void ListPushFront(ListNode **ppFirst, DataType data)
//{
//	assert(ppFirst);
//	//��������Ϊ�յ������
//	//�������
//	ListNode *newNode = CreateNode(data);
//	newNode->next = *ppFirst;
//
//	*ppFirst = newNode;
//}
//
////β��
//void ListPushBack(ListNode **ppFirst, DataType data)
//{
//	ListNode *newNode = CreateNode(data);
//	//����������ҵ�����һ��
//	if (*ppFirst == NULL)
//	{
//		*ppFirst = newNode;
//		return;
//	}
//	//ͨ�����
//	ListNode *cur = *ppFirst;
//	while (cur->next != NULL)
//	{
//		cur = cur->next;
//	}
//	//cur �������һ�����
//	cur->next = newNode;
//}
//
////ͷɾ
//void ListPopFront(ListNode **ppFirst)
//{
//	assert(ppFirst);//������ַ��Ϊ��
//	assert(*ppFirst);//�����ǿ�����
//
//	ListNode *del = *ppFirst;
//	*ppFirst = del->next;
//	free(del);//����
//}
//
////βɾ
//void ListPopBack(ListNode **ppFirst)
//{
//	assert(ppFirst);//������ַ��Ϊ��
//	assert(*ppFirst);//�����ǿ�����
//	//����ֻ��һ�����
//	if ((*ppFirst)->next == NULL)
//	{
//		free(*ppFirst);
//		*ppFirst = NULL;
//		return;
//	}
//	//�������
//	ListNode *del;
//	ListNode *cur = *ppFirst;
//
//	while (cur->next ->next != NULL)
//	{
//		cur = cur->next;
//	}
//
//	del = cur->next;
//	cur->next = NULL;
//	free(del);
//}
//
////����
//ListNode *ListFind(ListNode *first, DataType data)
//{
//	//˳����ң���������
//	for (ListNode *cur = first; cur != NULL; cur = cur->next)
//	{
//		if (data == cur->data)
//		{
//			return cur;
//		}
//	}
//	return NULL;
//}
//
////�޸�
////��ָ���Ľ��ǰ������
//void ListInsert(ListNode **ppFirst, ListNode *pos, DataType data)
//{
//	//ͷ��
//	if (*ppFirst == pos)
//	{
//		ListPushFront(ppFirst, data);
//		return;
//	}
//
//	ListNode *cur = *ppFirst;
//	//��pos��ǰһ�����
//	while (cur->next != pos)
//	{
//		cur = cur->next;
//	}
//	//�����½��
//	ListNode *newNode = CreateNode(data);
//	newNode->next = cur->next;
//	cur->next = newNode;
//}
//
////ɾ��ָ�����
//void ListErase(ListNode **ppFirst, ListNode *pos)
//{
//	//ͷɾ
//	if (*ppFirst == pos)
//	{
//		ListPopFront(ppFirst);
//		return;
//	}
//	ListNode *cur = *ppFirst;
//	//��pos��ǰһ�����
//	while (cur->next != pos)
//	{
//		cur = cur->next;
//	}
//	cur->next = pos->next;
//	free(pos);
//}
//
//void ListPrint(ListNode *first)
//{
//	for (ListNode *cur = first; cur != NULL; cur = cur->next)
//	{
//		printf("%d -> ", cur->data);
//	}
//	printf("NULL\n");
//}
//
//void Test()
//{
//	ListNode *first;
//	ListInit(&first);
//	ListPushBack(&first, 1);
//	ListPushBack(&first, 2);
//	ListPushBack(&first, 3);
//
//	ListNode *result = ListFind(first, 2);
//	ListInsert(&first, result, 0);
//	ListPrint(first);
//}


#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

typedef int DataType;

//����������ṹ
typedef struct ListNode
{
	DataType data;
	struct ListNode *next;
}ListNode;

//����������(ϵͳ�Ѿ�֪����һ�����ṹ������ֻ��Ҫ����һ�����ռ������ݼ���)
ListNode* CreateNode(data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	if (newNode == NULL){
		printf("����ռ�ʧ��\n");
		exit(0);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//����ĳ�ʼ����ֻ��Ҫ�õ������ͷָ��ָ��ռ�������Ϊ������
void ListInit(ListNode **ppHead)
{
	assert(ppHead);
	*ppHead = NULL;//�������ͷָ���ÿ�
}

//��������٣���Ҫ�ӵ�һ����㿪ʼ��������free��㼴�ɣ�
void ListDestroy(ListNode **ppHead)
{
	assert(ppHead);
	ListNode *nextNode = NULL;
	for (ListNode *cur = *ppHead; cur != NULL; cur = nextNode){
		nextNode = cur->next;
		free(cur);
	}
	*ppHead = NULL;//���Ҫ�õ������ͷָ��ָ��NULL�������������������ϣ�
}

//ͷ�壨����
void ListPushFront(ListNode **ppHead, DataType data)
{
	assert(ppHead);
	ListNode *newNode = CreateNode(data);
	if (*ppHead == NULL)
	{
		*ppHead = newNode;
		return;
	}
	newNode->next = (*ppHead);
	*ppHead = newNode;
}

//β�壨����
void ListPushBack(ListNode **ppHead, DataType data)
{
	assert(ppHead);
	ListNode *newNode = CreateNode(data);
	if (*ppHead == NULL)
	{
		*ppHead = newNode;
		return;
	}
	ListNode *cur = *ppHead;
	while (NULL != cur->next){
		cur = cur->next;
	}
	cur->next = newNode;
}

//ͷɾ��ɾ��
void ListPopFront(ListNode **ppHead)
{
	assert(ppHead);
	if (*ppHead == NULL)
	{
		return;
	}
	ListNode *del = *ppHead;
	*ppHead = del->next;
	free(del);
}

//βɾ��ɾ��(��Ҫע�������ֻ��һ����㡢�ж������������)
void ListPopBack(ListNode **ppHead)
{
	assert(ppHead);
	if (*ppHead == NULL)
	{
		return;
	}

	ListNode *cur = *ppHead;
	if (cur->next == NULL)
	{
		free(cur);
		*ppHead = NULL;
		return;
	}

	while (cur->next->next != NULL){
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

//���ң��飩
ListNode *ListFind(ListNode *ppHead, DataType data)
{
	assert(ppHead);
	if (ppHead == NULL)
	{
		return NULL;
	}

	ListNode *cur = ppHead;
	while (cur != NULL){
		if (data == cur->data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ��pos�ĺ�����в��� ���ģ�������Ԫ��λ�ã����޲��
void ListInsertAfter(ListNode **ppHead, ListNode *pos, DataType data)
{
	
	assert(ppHead);
	assert(*ppHead);
	assert(pos);
	ListNode *newNode = CreateNode(data);
	assert(newNode);

	ListNode *cur = *ppHead;
	while (cur != pos){
		cur = cur->next;
	}
	newNode->next = cur->next;
	cur->next = newNode;
}

// ��pos��ǰ����в��� ���ģ���ע��pos�ǵ�һ����㣬��Ҫͷ�壬����Ԫ��λ�ö�һ����
void ListInsertBefore(ListNode **ppHead, ListNode *pos, DataType data)
{
	assert(ppHead);
	assert(*ppHead);
	assert(pos);
	ListNode *newNode = CreateNode(data);
	assert(newNode);
	if (pos == *ppHead)
	{
		ListPushFront(ppHead, data);
		return;
	}
	ListNode *cur = *ppHead;
	while (pos != cur->next && cur != NULL)
	{
		cur = cur->next;
	}
	if (cur != NULL)
	{
		newNode->next = pos;
		cur->next = newNode;
	}
	else
	{
		printf("have no pos\n");
	}
}

//	ɾ��ָ����� ���ģ�
void ListErase(ListNode **ppHead, ListNode *pos)
{
	assert(ppHead);
	assert(*ppHead);
	assert(pos);
	if (pos == *ppHead)
	{
		ListPopFront(ppHead);
		return;
	}
	ListNode *cur = *ppHead;
	while (pos != cur->next && cur != NULL)
	{
		cur = cur->next;
	}
	if (NULL == cur)
	{
		printf("have no pos\n");
		return;
	}
	cur->next = pos->next;
	free(pos);
}

//ɾ��ֵΪdata�ĵ�����㣨�ģ�����Ҫע���һ���ڵ�������������ɾ��������һ����
void ListRemove(ListNode **ppHead, DataType data)
{
	assert(ppHead);
	assert(*ppHead);
	if (data == (*ppHead)->data)
	{
		ListPopFront(ppHead);
		return;
	}
	ListNode *cur = *ppHead;
	ListNode *pre = NULL;
	while (cur != NULL && data != cur->data)
	{
		pre = cur;
		cur = cur->next;
	}
	if (NULL == cur)
	{
		printf("have no %d\n", data);
		return;
	}
	pre->next = cur->next;
	free(cur);
}

//ɾ��ֵΪdata�����н�㣨�ģ�����Ҫע���һ���ڵ�������������ɾ��������һ����
void ListRemoveAll(ListNode **ppHead, DataType data)
{
	assert(ppHead);
	assert(*ppHead);

	ListNode *cur = *ppHead;
	ListNode *pre = NULL;

	int count = 0;
	while (cur)
	{
		if (data == cur->data)
		{
			if (cur == *ppHead)
			{
				*ppHead = cur->next;
				free(cur);
				cur = *ppHead;
				count = 1;;
			}
			else
			{
				pre->next = cur->next;
				free(cur);
				cur = pre->next;
				count = 1;
			}
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
	if (!count)
	{
		printf("have no %d\n\n", data);
	}
}

// ��ӡ����
void ListPrint(ListNode *ppHead)
{
	assert(ppHead);
	ListNode *cur = ppHead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n\n");
}


void Test()
{
	ListNode *pHead;
	ListInit(&pHead);

	ListPushFront(&pHead, 2);
	ListPushFront(&pHead, 5);
	ListPushFront(&pHead, 2);
	ListPushFront(&pHead, 3);
	ListPushFront(&pHead, 4);
	ListPushFront(&pHead, 2);
	ListPushFront(&pHead, 2);//ͷ��
	ListPushBack(&pHead, 2);//β��
	ListPushBack(&pHead, 6);//β��
	ListPrint(pHead);

	//ListPopFront(&pHead);//ͷɾ
	//ListPopBack(&pHead);//βɾ

	// ��pos�ĺ�����в��� ���ģ�������Ԫ��λ�ã����޲��
	//ListInsertAfter(&pHead, ListFind(pHead, 4), 1);

	// ��pos��ǰ����в��� ���ģ���ע��pos�ǵ�һ����㣬��Ҫͷ�壬����Ԫ��λ�ö�һ����
	//ListInsertBefore(&pHead, ListFind(pHead, 4), 1);

	//	ɾ��ָ����� ���ģ�
	//ListErase(&pHead, ListFind(pHead, 4));

	//ɾ��ֵΪdata�ĵ�����㣨�ģ�����Ҫע���һ���ڵ�������������ɾ��������һ����
	//ListRemove(&pHead, 4);

	//ɾ��ֵΪdata�����н�㣨�ģ�����Ҫע���һ���ڵ�������������ɾ��������һ����
	ListRemoveAll(&pHead, 2);

	ListPrint(pHead);
	ListDestroy(&pHead);
}