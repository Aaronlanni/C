#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkList.h"
//��ʼ������
void InitLinkList(pList* pplist)
{
	//ע�����ȼ�������
	*pplist = NULL;
}

//�������
Node* BuyNewNode(DataType data)
{
	Node*pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->data = data;
	pNewNode->next = NULL;
	return pNewNode;
}

//��ӡ����(��ͨ������
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
//�ݹ�
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

//�����ӡ
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
//ͷ��
void PushFront(pList* pplist, DataType d)
{
	//������
	pList pCur = *pplist;
	if (pplist == NULL)
	{
		*pplist = BuyNewNode(d);
	}
	//����ֻ��һ�����
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
	return NULL;//û�ҵ������
}

//ɾ��һ����ͷ������ķ�β��㣨����һ��λ�ã�
void DelNotTail(pNode pos)
{
	assert(pos&&(pos->next));//�жϽ����Ч���β���
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
	pos->next = pNewNode;//���½��ӵ�pos�ĺ���
	pNewNode->next = next;//���½�����ӵ��ղ�pos��ָ��ĺ���

	DataType data = pos->data;//����ָ��λ���е�����
	pos->data = pNewNode->data;//��������
	pNewNode->data = data;
}
Node* JosephCycle(pList pl, int k)//ɾ��k���
{
	if (pl == NULL)
	{
		return NULL;
	}
	Node*pCur = pl;
	while (pCur->next != pCur)//�������������
	{
		int count = k;
		while (--count)
		{
			pCur = pCur->next;
		}
		Node*next = pCur->next;
		pCur->data = next->data;//�ı���ɾλ���ϵ�����Ϊ��ɾλ�õ���һ��λ���ϵ�����
		pCur->next = next->next;//������ɾλ����next��next��λ��
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
//void DestroyList(pList* pplist)\\������
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