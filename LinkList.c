#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkList.h"
//初始化链表
void InitLinkList(pList* pplist)
{
	//注意优先级的问题
	*pplist = NULL;
}

//创建结点
Node* BuyNewNode(DataType data)
{
	Node*pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->data = data;
	pNewNode->next = NULL;
	return pNewNode;
}

//打印链表(普通方法）
void Display(pList pl)
{
	pList pCur = pl;
	if (pl == NULL)
	{
		return;
	}
	else
	{
		while (pCur)
		{
			printf("%d->", pCur->data);
			pCur = pCur->next;
		}
		printf("over");
		printf("\n");
	}
}
//递归
//void Display(pList pl)
//{
//	pList pCur = pl;
//	if (pl == NULL)
//	{
//		return;
//	}
//	else
//	{
//		printf("%d->", pCur->data);
//		Display(pCur->next);
//	}
//}

//逆序打印
void Show(pList pl)
{
	pList pCur = pl;
	if (pl == NULL)
	{
		return;
	}	
		while (pCur->next != NULL)
		{
			Show(pCur->next);
			break;
		}
		printf("%d->", pCur->data);
}
//头插
void PushFront(pList* pplist, DataType d)
{
	//空链表
	pList pCur = *pplist;
	if (pplist == NULL)
	{
		*pplist = BuyNewNode(d);
	}
	//链表只有一个结点
	else
	{
		Node* pNewNode = BuyNewNode(d);
		pNewNode->next = pCur;
		*pplist = pNewNode;
	}
}
Node* Find(Node*pHead, int data)
{
	assert(pHead);
	Node*pCur = pHead;
	while (pCur != NULL)
	{
		if (pCur->data == data)
		{
			return pCur;
		}
		pCur = pCur->next;
	}
	return NULL;//没找到的情况
}

//删除一个无头单链表的非尾结点（任意一个位置）
void DelNotTail(pNode pos)
{
	assert(pos&&(pos->next));//判断结点有效与非尾结点
	pList pCur = pos->next;
	pos->data = pos->next->data;
	pos->next = pCur->next;
	free(pCur);
	pCur = NULL;
}

void InsertFrontNode(pNode pos, DataType d)
{
	assert(pos);
	Node*pNewNode = BuyNewNode(d);
	Node*next = pos->next;
	pos->next = pNewNode;//将新结点加到pos的后面
	pNewNode->next = next;//将新结点链接到刚才pos所指向的后面

	DataType data = pos->data;//保存指定位置中的数据
	pos->data = pNewNode->data;//交换数据
	pNewNode->data = data;
}
Node* JosephCycle(pList pl, int k)//删除k结点
{
	if (pl == NULL)
	{
		return NULL;
	}
	Node*pCur = pl;
	while (pCur->next != pCur)//程序结束的条件
	{
		int count = k;
		while (--count)
		{
			pCur = pCur->next;
		}
		Node*next = pCur->next;
		pCur->data = next->data;//改变所删位置上的数据为所删位置的下一个位置上的数据
		pCur->next = next->next;//链接所删位置与next的next的位置
		free(next);
		next = NULL;
	}
	return pCur;
}

void ReverseList(pList* pplist)
{
	/*if (pplist == NULL)
	{
		return;
	}
	Node*p1 = NULL;
	Node*p2 = pplist;
	Node*p3 = p2->next;
	while (p2)
	{
		p2->next = p1;

		p1 = p2;
		p2 = p3;
		if (p3)
		{
			p3 = p3->next;
		}
			
		
	}
	pplist = p1;*/

	if (pplist == NULL)
	{
		return;
	}
	pList newHead = NULL;
	pList pCur = *pplist;
	pList Per = pCur->next;
	while (pCur)
	{
		pCur->next = newHead;
		
		newHead = pCur;
		pCur = Per;
	}
	*pplist = newHead;
}
//void DestroyList(pList* pplist)\\有问题
//{
//	pList pCur = pplist;
//	pList Per = NULL;
//	if (pplist == NULL)
//	{
//		return;
//	}
//	
//	while (pCur!=NULL)
//	{	
//		pCur = pCur->next;	
//		free(Per);		
//		Per = pCur;
//	}
//		pplist = NULL;
//}