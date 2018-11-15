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
////初始化
//void ListInit(ListNode **ppfirst)
//{
//	assert(ppfirst != NULL);
//	*ppfirst = NULL;
//}
//
////销毁
//void ListDestroy(ListNode **ppFirst)
//{
//	assert(ppFirst != NULL);
//	//1 所有都回收
//	//2 free 后不能再使用 cur
//	ListNode *next;
//	for (ListNode *cur = *ppFirst; cur != NULL; cur = next)
//	{
//		next = cur->next;
//		free(cur);
//	}
//	*ppFirst = NULL;
//}
//
////增删查改
////结点创建
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
////头插
//void ListPushFront(ListNode **ppFirst, DataType data)
//{
//	assert(ppFirst);
//	//考虑链表为空的情况，
//	//正常情况
//	ListNode *newNode = CreateNode(data);
//	newNode->next = *ppFirst;
//
//	*ppFirst = newNode;
//}
//
////尾插
//void ListPushBack(ListNode **ppFirst, DataType data)
//{
//	ListNode *newNode = CreateNode(data);
//	//特殊情况，找倒数第一个
//	if (*ppFirst == NULL)
//	{
//		*ppFirst = newNode;
//		return;
//	}
//	//通常情况
//	ListNode *cur = *ppFirst;
//	while (cur->next != NULL)
//	{
//		cur = cur->next;
//	}
//	//cur 就是最后一个结点
//	cur->next = newNode;
//}
//
////头删
//void ListPopFront(ListNode **ppFirst)
//{
//	assert(ppFirst);//变量地址不为空
//	assert(*ppFirst);//不能是空链表
//
//	ListNode *del = *ppFirst;
//	*ppFirst = del->next;
//	free(del);//谨记
//}
//
////尾删
//void ListPopBack(ListNode **ppFirst)
//{
//	assert(ppFirst);//变量地址不为空
//	assert(*ppFirst);//不能是空链表
//	//链表只有一个结点
//	if ((*ppFirst)->next == NULL)
//	{
//		free(*ppFirst);
//		*ppFirst = NULL;
//		return;
//	}
//	//正常情况
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
////查找
//ListNode *ListFind(ListNode *first, DataType data)
//{
//	//顺序查找，遍历链表
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
////修改
////在指定的结点前做插入
//void ListInsert(ListNode **ppFirst, ListNode *pos, DataType data)
//{
//	//头插
//	if (*ppFirst == pos)
//	{
//		ListPushFront(ppFirst, data);
//		return;
//	}
//
//	ListNode *cur = *ppFirst;
//	//找pos的前一个结点
//	while (cur->next != pos)
//	{
//		cur = cur->next;
//	}
//	//插入新结点
//	ListNode *newNode = CreateNode(data);
//	newNode->next = cur->next;
//	cur->next = newNode;
//}
//
////删除指定结点
//void ListErase(ListNode **ppFirst, ListNode *pos)
//{
//	//头删
//	if (*ppFirst == pos)
//	{
//		ListPopFront(ppFirst);
//		return;
//	}
//	ListNode *cur = *ppFirst;
//	//找pos的前一个结点
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

//声明链表结点结构
typedef struct ListNode
{
	DataType data;
	struct ListNode *next;
}ListNode;

//创建链表结点(系统已经知道有一个结点结构，我们只需要申请一个结点空间存放数据即可)
ListNode* CreateNode(data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	if (newNode == NULL){
		printf("申请空间失败\n");
		exit(0);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//链表的初始化（只需要让单链表的头指针指向空即该链表为空链表）
void ListInit(ListNode **ppHead)
{
	assert(ppHead);
	*ppHead = NULL;//单链表的头指针置空
}

//链表的销毁（需要从第一个结点开始依次往后free结点即可）
void ListDestroy(ListNode **ppHead)
{
	assert(ppHead);
	ListNode *nextNode = NULL;
	for (ListNode *cur = *ppHead; cur != NULL; cur = nextNode){
		nextNode = cur->next;
		free(cur);
	}
	*ppHead = NULL;//最后要让单链表的头指针指向NULL，整个链表才算销毁完毕！
}

//头插（增）
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

//尾插（增）
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

//头删（删）
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

//尾删（删）(需要注意空链表、只有一个结点、有多个结点三种情况)
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

//查找（查）
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

// 在pos的后面进行插入 （改）（所有元素位置，均无差别）
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

// 在pos的前面进行插入 （改）（注意pos是第一个结点，需要头插，其余元素位置都一样）
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

//	删除指定结点 （改）
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

//删除值为data的单个结点（改）（需要注意第一个节点的情况，其余结点删除方法都一样）
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

//删除值为data的所有结点（改）（需要注意第一个节点的情况，其余结点删除方法都一样）
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

// 打印链表
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
	ListPushFront(&pHead, 2);//头插
	ListPushBack(&pHead, 2);//尾插
	ListPushBack(&pHead, 6);//尾插
	ListPrint(pHead);

	//ListPopFront(&pHead);//头删
	//ListPopBack(&pHead);//尾删

	// 在pos的后面进行插入 （改）（所有元素位置，均无差别）
	//ListInsertAfter(&pHead, ListFind(pHead, 4), 1);

	// 在pos的前面进行插入 （改）（注意pos是第一个结点，需要头插，其余元素位置都一样）
	//ListInsertBefore(&pHead, ListFind(pHead, 4), 1);

	//	删除指定结点 （改）
	//ListErase(&pHead, ListFind(pHead, 4));

	//删除值为data的单个结点（改）（需要注意第一个节点的情况，其余结点删除方法都一样）
	//ListRemove(&pHead, 4);

	//删除值为data的所有结点（改）（需要注意第一个节点的情况，其余结点删除方法都一样）
	ListRemoveAll(&pHead, 2);

	ListPrint(pHead);
	ListDestroy(&pHead);
}