#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define MAXSIZE 26

struct Tu
{
	char word[50];
	char mean[100];
};

struct HashNode
{
	Tu T;
	HashNode *Next;
};

HashNode* bucket[MAXSIZE];

int HashFunction(char Key[])
{
	int n = Key[0];
	return ((n - 97) % MAXSIZE);
}

void InitHashTable()
{
	for (int b = 0; b < MAXSIZE; b++)
		bucket[b] = NULL;
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
		printf("   %s", p->T.word);
		p = p->Next;
	}
}

void Traverse()
{
	for (int b = 0; b < MAXSIZE; b++)
	{
		printf("\n Bucket[%d]=", b);
		if (bucket[b] != NULL)
		{
			TraverseBucket(b);
		}
	}
}

//void Push(char w[], char m[])
//{
//	int b = HashFunction(w);
//	HashNode* p = new HashNode;
//	p->Next = NULL;
//	strcpy(p->T.word, w);
//	strcpy(p->T.mean, m);
//	if (IsEmptyBucket(b) == TRUE)
//		bucket[b] = p;
//	else
//	{
//		p->Next = bucket[b];
//		bucket[b] = p;
//	}
//}

Tu GanGiaTriChoTu(char w[], char m[])
{
	Tu t;
	strcpy(t.word, w);
	strcpy(t.mean, m);
	return t;
}

void Push(Tu t)
{
	int b = HashFunction(t.word);
	HashNode* p = new HashNode;
	p->Next = NULL;
	strcpy(p->T.word, t.word);
	strcpy(p->T.mean, t.mean);
	if (IsEmptyBucket(b) == TRUE)
		bucket[b] = p;
	else
	{
		p->Next = bucket[b];
		bucket[b] = p;
	}
}

int Search(char w[])
{
	int b = HashFunction(w);
	HashNode* p = bucket[b];
	while (p != NULL)
	{
		if (strcmp(p->T.word, w) == 0)
		{
			printf("%s\n", p->T.mean);
			return 1;
		}
		p = p->Next;
	}
	printf("Ko tim thay!\n");
}

void AddFromFile()
{
	FILE *f;
	f = fopen("INPUT.TXT", "rt");
	while (!feof(f))
	{
		Tu t;
		fscanf(f, "%[^#]#%[^\n]\n", t.word, t.mean);
		Push(t);
	}
	fclose(f);
}

//void createListFromFile(list &l)
//{
//	FILE *fileInput = fopen("INPUT.TXT", "r");
//	if (!fileInput)
//	{
//		printf("File khong ton tai! xin kiem tra lai");
//		getch();
//		exit(0);
//	}
//
//	node *p;
//	char st[10];
//	char nsx[10];
//	char g[15];
//	while (!feof(fileInput))
//	{
//		Sach *s = new Sach;
//		fscanf(fileInput, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%s", s->maSach, s->tenSach, st, nsx, g);
//		s->soTrang = atoi(st);
//		s->namSX = atoi(nsx);
//		s->gia = atof(g);
//		p = createNode(s);
//		insertTail(l, p);
//	}
//	fclose(fileInput);
//}