#define _CRT_SECURE_NO_WARNINGS 1
#include "sequence.h"
void Initseqlist(pSeqlist ps)
{
	assert(ps != NULL);
	ps->sz = 0;
	ps->capacity = DEFAULT_SZ;
	ps->data = malloc(sizeof(TypeData)*(ps->capacity));
	if (ps->data == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	memset(ps->data, 0, sizeof(TypeData)*(ps->capacity));
}

void Checkcap(pSeqlist ps)//����
{
	assert(ps != NULL);
	if (ps->sz == ps->capacity)
	{
		TypeData*ptr = realloc(ps->data, 
			(ps->capacity + INC)*sizeof(TypeData));
			if (ptr != NULL)
			{
				ps->data = ptr;
				ps->capacity += INC;//�����
			}
			else
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
	}
}

void PushBack(pSeqlist ps, TypeData d)
{
	assert(ps != NULL);
	Checkcap(ps);//����
	assert(ps->data != NULL);
	ps->data[ps->sz] = d;
	ps->sz++;
}

void Display(pSeqlist ps)
{
	assert(ps != NULL);
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

void PopBack(pSeqlist ps)
{
	assert(ps != NULL);
	if (ps->sz == 0)
	{
		return;
	}
	ps->sz--;
}

void PushFront(pSeqlist ps, TypeData d)
{
	assert(ps != NULL);
	int i = 0;
	Checkcap(ps);//����
	assert(ps->data != NULL);
	memmove(ps->data + 1, ps->data, sizeof(TypeData)*(ps->sz));
	/*for (i = ps->sz; i > 0; i--)
	{
		ps->data[i] = ps->data[i-1];
	}*/
	/*void *memmove( void *dest, const void *src, size_t count );*/  //memmove��ԭ��

	ps->data[0] = d;
	ps->sz++;
}

void PopFront(pSeqlist ps)
{
	int i = 0;
	assert(ps != NULL);
	if (ps->sz == 0)
	{
		return;
	}
	for (i = 0; i < ps->sz; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}

int Find(pSeqlist ps, TypeData d)
{
	int i = 0;
	for (i = 0; i < ps->sz - 1; i++)
	{
		if (d == ps->data[i])
		{
			return i;
		}
	}
	return -1;
}


void Remove(pSeqlist ps, TypeData d)
{
	assert(ps != NULL);
	int pos = 0;
	int i = 0;
	pos = Find(ps, 1);
	if (pos != -1)
	{
		for (i = 0; i < ps->sz; i++)
		{
			ps->data[i] = ps->data[i + 1];
		}
	}
	ps->sz--;
}

void RemoveAll(pSeqlist ps, TypeData d)//tiao
{
	assert(ps != NULL);
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		if (d == ps->data[i])
		{
			ps->data[i] = ps->data[i + 1];
			ps->sz--;
		}
	}

}

void Insert(pSeqlist ps, TypeData d, int pos)
{
	assert(ps != NULL);
	int i = 0;
	Checkcap(ps);//����
	assert(ps->data != NULL);
	/*for (i = ps->sz; i > pos; i--)         //����ʵ�ַ�ʽ
	{
	ps->data[i] = ps->data[i - 1];
	}*/
	memmove(ps->data + pos + 1, ps->data + pos, sizeof(TypeData)*(ps->sz - pos));
	ps->data[pos] = d;
	ps->sz++;
}

void Reverse(pSeqlist ps)
{
	TypeData tmp = 0;
	TypeData *left = ps->data;
	TypeData *right = ps->data + (ps->sz) - 1;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void Sort(pSeqlist ps)//ð������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ps->sz - 1; i++)
	{
		for (j = 0; j < ps->sz - i - 1; j++)
		{
			if (ps->data[j]>ps->data[j + 1])//����
			{
				TypeData tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
			}
		}
	}
}

int BinarySearch(pSeqlist ps, TypeData d)
{
	int left = 0;
	int right = ps->sz - 1;
	while (left <= right)  //�ڵ���֮ʱ��δʹ�����������û�н����ж�
	{
		int mid = left + (right - left) / 2;
		if (ps->data[mid]>d)
		{
			right = mid - 1;
		}
		else if (ps->data[mid] < d)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;//û�ҵ�
	//��ʾѭ����������return�ĺ�����ǣ�ֻҪ�ҵ�����ֱ�ӽ�������
}


void Destroy(pSeqlist ps)//���ٶ�̬���ٵ��ڴ�
{
	assert(ps != NULL);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->sz = 0;
}
