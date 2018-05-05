#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(pContact pcon)//��ʼ��
{	pcon->sz = 0;
memset(pcon->data, 0,MAX*sizeof(struct PeoInfo));
}

void AddContact(pContact pcon)//����ͨѶ¼�е���Ϣ
{
	assert(pcon->data);
	if (pcon->data == MAX)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("����������>: ");
		scanf("%s", pcon->data[pcon->sz].name);
		printf("�������Ա�>: ");
		scanf("%s", pcon->data[pcon->sz].sex);
		printf("����������>: ");
		scanf("%d", &pcon->data[pcon->sz].age);
		printf("������绰>: ");
		scanf("%s", pcon->data[pcon->sz].tele);
		printf("�������ַ>: ");
		scanf("%s", pcon->data[pcon->sz].addr);
		pcon->sz++;
	}
	printf("¼��ɹ�\n");
}

static int FindEntry(pContact pcon,char name[])//���Һ������
{
	int i = 0;
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(pcon->data[i].name, name) == 0)
		{
			return i;//�ҵ��������±�
		}
	}
	return -1;//����-1ʱ��������ڱȽ�һȦ֮�󣬲����ҵ�������ͬ�ģ���˷���-1
} 

int SearchContact(pContact pcon)//����ͨѶ¼�е���Ϣ
{
	char name[NAME_MAX];
	printf("������Ҫ��ѯ������: ");
	scanf("%s",name);
	int pos = 0;
	pos = FindEntry(pcon, name);
	if (pos == -1)
	{
		printf("��Ҫ��ѯ���˲�����\n");
		return;
	}
	else
	{
		printf("����:%10s\t�Ա�%5s\t����:%5d\t�绰��%10s\tסַ��%15s\n", pcon->data[pos].name,
			pcon->data[pos].sex,
			pcon->data[pos].age,
			pcon->data[pos].tele,
			pcon->data[pos].addr);
	}
}                  

void ShowContact(pContact pcon)
{
	    printf("��ϵ����Ϣ��\n");
		int i = 0;
		printf("%10s\t%5s\t%5s\t%10s\t%15s\n","����","�Ա�","����","�绰","��ַ");
		for (i = 0; i < pcon->sz; i++)
		{
			printf("%10s\t%5s\t%5d\t%10s\t%15s\n",pcon->data[i].name,
			pcon->data[i].sex,
			pcon->data[i].age,
			pcon->data[i].tele,
			pcon->data[i].addr);
		}
}


void DelContact(pContact pcon)//ɾ����ϵ��
{
	char name[NAME_MAX];
	printf("������Ҫɾ���ĳ���ϵ��\n");
	scanf("%s", name);
	int pos = 0;//����pos����FindEntry���صĵ�ַ
	pos = FindEntry(pcon, name);
	if (pos == -1)
	{
		printf("Ҫɾ������ϵ�˲�����");
		return;
	}
	else
	{
		int j = 0;
		for (j = pos; j < pcon->sz; j++)
		{
			pcon->data[j] = pcon->data[j + 1];//���ú���һ������ǰһ�����Ӷ��ﵽɾ����Ч��
		}
		pcon->sz--;
		printf("ɾ���ɹ�\n");
	}
}


void ModifyContact(pContact pcon)
{
	char name[NAME_MAX];
	printf("������Ҫ�޸ĵĳ���ϵ��\n");
	scanf("%s", name);
	int pos = 0;//����pos����FindEntry���صĵ�ַ
	pos = FindEntry(pcon, name);
	if (pos != -1)
	{
		printf("�������޸ĺ�������� ");
		scanf("%s", pcon->data[pcon->sz].name);
		printf("�������޸ĺ���Ա� ");
		scanf("%s", pcon->data[pcon->sz].sex);
		printf("�������޸ĺ�����䣺 ");
		scanf("%d", &pcon->data[pcon->sz].age);
		printf("�������޸ĺ�ĵ绰�� ");
		scanf("%s", pcon->data[pcon->sz].tele);
		printf("�������޸ĺ�ĵ�ַ�� ");
		scanf("%s", pcon->data[pcon->sz].addr);
		printf("�޸����\n");
	}
	else
	{
		printf("Ҫ�޸ĵ���ϵ�˲����ڣ�\n");
	}
}

void SortContact(pContact pcon)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pcon->sz-1; i++)//ð������
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
	printf("%10s\t%5s\t%5s\t%10s\t%15s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%10s\t%5s\t%5d\t%10s\t%15s\n", pcon->data[i].name,
			pcon->data[i].sex,
			pcon->data[i].age,
			pcon->data[i].tele,
			pcon->data[i].addr);
	}
	
	printf("�������\n");
}

void ClearContact(pContact pcon)
{
		pcon->sz = 0;
}