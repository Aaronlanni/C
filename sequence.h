#ifndef __SEQU_H__
#define __SEQU_H__
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#define DEFAULT_SZ 2
#define INC 2
typedef int TypeData;

typedef struct Seqlist
{
	TypeData *data;
	int sz;
	int capacity;
}Seqlist, *pSeqlist;

void Initseqlist(pSeqlist ps);
void PushBack(pSeqlist ps, TypeData d);
void Display(pSeqlist ps);
void PopBack(pSeqlist ps);
void PushFront(pSeqlist ps, TypeData d);
void PopFront(pSeqlist ps);
int Find(pSeqlist ps, TypeData d);
void Remove(pSeqlist ps, TypeData d);
void RemoveAll(pSeqlist ps, TypeData d);
void Insert(pSeqlist ps, TypeData d, int pos);
void Reverse(pSeqlist ps);
void Sort(pSeqlist ps);
int BinarySearch(pSeqlist ps, TypeData d);
void Destroy(pSeqlist ps);

#endif//__SEQU_H__
