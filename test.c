#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("*********************************\n");
	printf("***  1. Add           2. Del  ***\n");
	printf("***  3.Search         4.Modify***\n");
	printf("***  5. Show          6.Sort  ***\n");
	printf("***  7.Clear          0.Exit  ***\n");
	printf("*********************************\n");
	printf("                                 \n");
}
void test()
{
	Contact my_con;
	InitContact(&my_con);//��ʼ��ͨѶ¼
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>: ");
		scanf("%d", &input);
		switch (input)
		{
		case Exit:
			break;
		case Add:
			AddContact(&my_con);//������ϵ��
			break;
		case Del:
			DelContact(&my_con);//ɾ����ϵ��
			break;
		case Search:
			SearchContact(&my_con);//��ѯ��ϵ��
			break;
		case Modify:
			ModifyContact(&my_con);//�޸���ϵ��
			break;
		case Show:
			ShowContact(&my_con);//��ʾ��ϵ��
			break;
		case Sort:
			SortContact(&my_con);//����ϵ�����򣬰���������
			break;
		case Clear:
			ClearContact(&my_con);//���ͨѶ¼
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
}


int main()
{
	test();
	return 0;
}
