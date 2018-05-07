#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode, *pList;

void InitLinkList(pList* pplist);
void PushFront(pList* pplist, DataType d);
void Display(pList pl);
void Show(pList pl);//逆序打印
void DestroyList(pList* pplist);
void DelNotTail(pNode pos);//删除一个无头单链表的非尾结点（任意一个位置）
pNode Find(pList pl, DataType d);//查找函数

void InsertFrontNode(pNode pos, DataType d);//在无头单链表的一个非头结点前插入一个结点
Node* JosephCycle(pList pl, int k);//约瑟夫环
void ReverseList(pList* pplist);///逆序链表
void BubbleSortList(pList plist);//（冒泡排序和快速排序）
pList Merge(pList* ppl1, pList* ppl2);//合并两条单链表，合并后依然有序
pNode FindMidNode(pList plist);//查找单链表的中间结点，要求只遍历一次


#endif //__LINKLIST_H__