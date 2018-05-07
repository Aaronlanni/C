#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkList.h"

void Test()
{
	pNode plist;//此为一级指针的变量
	InitLinkList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	Display(plist);
	
	//Show(plist);
	/*Node*pos = Find(plist, 3);
	DelNotTail(pos);
	Display(plist);
	Node*pos1 = Find(plist, 2);
	DelNotTail(pos1);
	Display(plist);*/
	/*Node*pos = Find(plist, 3);
	InsertFrontNode(pos, 6);
	Display(plist);
	Node*pos1 = Find(plist, 1);
	InsertFrontNode(pos1, 7);
	Display(plist);*/
	//Node*pos = Find(plist, 1);//成环
	//pos->next = plist;
	//
	//Node* last=JosephCycle(plist, 3);
	//printf("lucky %d", last->data);
	//DestroyList(&plist);
	ReverseList(&plist);
	Display(plist);
}
int main()
{
	Test();
	system("pause");
	return 0;
}
