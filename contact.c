#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(pContact pcon)//初始化
{	pcon->sz = 0;
memset(pcon->data, 0,MAX*sizeof(struct PeoInfo));
}

void AddContact(pContact pcon)//增加通讯录中的信息
{
	assert(pcon->data);
	if (pcon->data == MAX)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入名字>: ");
		scanf("%s", pcon->data[pcon->sz].name);
		printf("请输入性别>: ");
		scanf("%s", pcon->data[pcon->sz].sex);
		printf("请输入年龄>: ");
		scanf("%d", &pcon->data[pcon->sz].age);
		printf("请输入电话>: ");
		scanf("%s", pcon->data[pcon->sz].tele);
		printf("请输入地址>: ");
		scanf("%s", pcon->data[pcon->sz].addr);
		pcon->sz++;
	}
	printf("录入成功\n");
}

static int FindEntry(pContact pcon,char name[])//查找函数入口
{
	int i = 0;
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(pcon->data[i].name, name) == 0)
		{
			return i;//找到，返回下标
		}
	}
	return -1;//返回-1时，则表明在比较一圈之后，不能找到两个相同的，因此返回-1
} 

int SearchContact(pContact pcon)//查找通讯录中的信息
{
	char name[NAME_MAX];
	printf("请输入要查询的姓名: ");
	scanf("%s",name);
	int pos = 0;
	pos = FindEntry(pcon, name);
	if (pos == -1)
	{
		printf("你要查询的人不存在\n");
		return;
	}
	else
	{
		printf("姓名:%10s\t性别：%5s\t年龄:%5d\t电话：%10s\t住址：%15s\n", pcon->data[pos].name,
			pcon->data[pos].sex,
			pcon->data[pos].age,
			pcon->data[pos].tele,
			pcon->data[pos].addr);
	}
}                  

void ShowContact(pContact pcon)
{
	    printf("联系人信息：\n");
		int i = 0;
		printf("%10s\t%5s\t%5s\t%10s\t%15s\n","姓名","性别","年龄","电话","地址");
		for (i = 0; i < pcon->sz; i++)
		{
			printf("%10s\t%5s\t%5d\t%10s\t%15s\n",pcon->data[i].name,
			pcon->data[i].sex,
			pcon->data[i].age,
			pcon->data[i].tele,
			pcon->data[i].addr);
		}
}


void DelContact(pContact pcon)//删除联系人
{
	char name[NAME_MAX];
	printf("请输入要删除的除联系人\n");
	scanf("%s", name);
	int pos = 0;//利用pos接收FindEntry返回的地址
	pos = FindEntry(pcon, name);
	if (pos == -1)
	{
		printf("要删除的联系人不存在");
		return;
	}
	else
	{
		int j = 0;
		for (j = pos; j < pcon->sz; j++)
		{
			pcon->data[j] = pcon->data[j + 1];//利用后面一个覆盖前一个，从而达到删除的效果
		}
		pcon->sz--;
		printf("删除成功\n");
	}
}


void ModifyContact(pContact pcon)
{
	char name[NAME_MAX];
	printf("请输入要修改的除联系人\n");
	scanf("%s", name);
	int pos = 0;//利用pos接收FindEntry返回的地址
	pos = FindEntry(pcon, name);
	if (pos != -1)
	{
		printf("请输入修改后的姓名： ");
		scanf("%s", pcon->data[pcon->sz].name);
		printf("请输入修改后的性别： ");
		scanf("%s", pcon->data[pcon->sz].sex);
		printf("请输入修改后的年龄： ");
		scanf("%d", &pcon->data[pcon->sz].age);
		printf("请输入修改后的电话： ");
		scanf("%s", pcon->data[pcon->sz].tele);
		printf("请输入修改后的地址： ");
		scanf("%s", pcon->data[pcon->sz].addr);
		printf("修改完毕\n");
	}
	else
	{
		printf("要修改的联系人不存在！\n");
	}
}

void SortContact(pContact pcon)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pcon->sz-1; i++)//冒泡排序
	{
		for (j = 1; j < pcon->sz - i-1; j++)
		{
			if (strcmp(pcon->data[i].name, pcon->data[i+1].name)<0)
			{
			struct PeoInfo tem;
			tem = pcon->data[j];
			pcon->data[j] = pcon->data[j+1];
			pcon->data[j+1]=tem;
			}
		}
	}
	printf("%10s\t%5s\t%5s\t%10s\t%15s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%10s\t%5s\t%5d\t%10s\t%15s\n", pcon->data[i].name,
			pcon->data[i].sex,
			pcon->data[i].age,
			pcon->data[i].tele,
			pcon->data[i].addr);
	}
	
	printf("排序完成\n");
}

void ClearContact(pContact pcon)
{
		pcon->sz = 0;
}