#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
struct HashNode
{
	int Key;
	HashNode *Next;
};

HashNode* bucket[MAXSIZE];

int HashFunction(int Key)
{
	return (Key % MAXSIZE);
}

void InitHashTable()
{
	for (int b = 0; b < MAXSIZE; b++)
		bucket[b] = NULL;
}

void DeleteHashNode(HashNode* p)
{
	delete p;
}

int IsEmptyBucket(int b)
{
	if (bucket[b] == NULL)
		return TRUE;
	else
		return FALSE;
}

int IsEmpty()
{
	for (int b = 0; b < MAXSIZE; b++)
		if (bucket[b] != NULL)
			return FALSE;
	return TRUE;
}
 
void TraverseBucket(int b)
{
	HashNode* p = bucket[b];
	while (p != NULL)
	{
		printf("%4d", p->Key);
		p = p->Next;
	}
}

void Traverse()
{
	for (int b = 0; b < MAXSIZE; b++)
	{
		printf("\n Bucket[%d]=", b);
		TraverseBucket(b);
	}
}

void ClearBucket(int b)
{
	HashNode* q = NULL;
	HashNode* p = bucket[b];
	while (p != NULL)
	{
		q = p;
		p = p->Next;
		DeleteHashNode(q);
	}
	bucket[b] = NULL;
}

void Clear()
{
	for (int b = 0; b < MAXSIZE; b++)
	{
		ClearBucket(b);
	}
}

void Push(int b, int x)
{
	HashNode* p = new HashNode;
	p->Key = x;
	p->Next = bucket[b];
	bucket[b] = p;
}

int Pop(int b)
{
	if (IsEmptyBucket(b))
	{
		printf("Bucket %d bi rong, khong xoa duoc", b);
		return 0;
	}
	HashNode* p = bucket[b];
	int k = p->Key;
	bucket[b] = p->Next;
	DeleteHashNode(p);
	return k;
}

int InsertAfter(HashNode* p, int k)
{
	if (p == NULL)
	{
		printf("Khong them vao HashNode moi duoc!");
		return 0; 
	}
	else
	{
		HashNode* q = new HashNode;
		q->Key = k;
		q->Next = p->Next;
		p->Next = q;
	}
	return 1; 
}

void Place(int b, int k)
{
	HashNode* p, *q;
	q = NULL;
	for (p = bucket[b]; p != NULL && k > p->Key; p = p->Next)
		q = p;
	if (q == NULL)
		Push(b, k);
	else
		InsertAfter(q, k);
}

void Insert(int k)
{
	int b;
	b = HashFunction(k);
	Place(b, k);
}

int Search(int k)
{
	int b = HashFunction(k);
	HashNode* p = bucket[b];
	while (p != NULL && k > p->Key)
		p = p->Next;
	if (p == NULL || k != p->Key)
		return -1;
	else
		return b;
}

int DeleteAfter(HashNode* p)
{
	HashNode* q;
	int k;
	if (p == NULL || p->Next == NULL)
	{
		printf("\n Khong xoa HashNode duoc");
		return 0;
	}
	q = p->Next;
	k = q->Key;
	p->Next = q->Next;
	DeleteHashNode(q);
	return k;
}

void Remove(int k)
{
	int b;
	HashNode *p, *q;
	b = HashFunction(k);
	p = bucket[b];
	q = p;
	while (p != NULL && p->Key != k)
	{
		q = p;
		p = p->Next;
	}
	if (p == NULL)
		printf("\n Khong co HashNode co khoa la: %d", b);
	else if (p == bucket[b])
		Pop(b);
	else
		DeleteAfter(q);
}

