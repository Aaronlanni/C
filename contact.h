//#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __CONTACT_H__   //防止头文件的重复引用
#define __CONTACT_H__
#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 15
#define ADDER_MAX 30
#include<stdio.h>
#include<assert.h>
#include<string.h>

typedef struct PeoInfo//定义个人信息结构体
{
	char name[NAME_MAX];
	long int age;
	char  sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDER_MAX];
}PeoInfo;
typedef struct Contact
{
	struct PeoInfo data[MAX];
	int sz;//统计放入的个数
}Contact,*pContact;
enum MyEnum
{
	Exit,
	Add,
	Del,
	Search,
	Modify,
	Show,
	Sort,
	Clear
};
void InitContact(pContact pcon);
void AddContact(pContact pcon);
int SearchContact(pContact pcon);
void ShowContact(pContact pcon);
void DelContact(pContact pcon);
void ModifyContact(pContact pcon);
void SortContact(pContact pcon);
void ClearContact(pContact pcon);



#endif

