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
void Show(pList pl);//�����ӡ
void DestroyList(pList* pplist);
void DelNotTail(pNode pos);//ɾ��һ����ͷ������ķ�β��㣨����һ��λ�ã�
pNode Find(pList pl, DataType d);//���Һ���

void InsertFrontNode(pNode pos, DataType d);//����ͷ�������һ����ͷ���ǰ����һ�����
Node* JosephCycle(pList pl, int k);//Լɪ��
void ReverseList(pList* pplist);///��������
void BubbleSortList(pList plist);//��ð������Ϳ�������
pList Merge(pList* ppl1, pList* ppl2);//�ϲ������������ϲ�����Ȼ����
pNode FindMidNode(pList plist);//���ҵ�������м��㣬Ҫ��ֻ����һ��


#endif //__LINKLIST_H__