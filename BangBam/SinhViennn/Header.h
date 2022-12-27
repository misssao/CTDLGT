#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define NULLKEY -1
#define SIZE 15

struct SV
{
	char ma[100];
	char hoten[100];
	float dtb;
};

struct HashTable
{
	SV *Info;
	int size;
	int MAXSIZE = 0;
};

//void initHashTable(HashTable &ht){
//	for (int i = 0; i < SIZE; i++)
//		ht.Info[i] = NULL;
//	ht.size = 0;
//}

void initHashTable(HashTable &ht, int size){
	ht.MAXSIZE = size;
	ht.Info = new SV[ht.MAXSIZE];
	for (int i = 0; i < size; i++)
		ht.Info[i] = NULL;
	ht.size = 0;
}

int isEmpty(HashTable ht){
	if (ht.size == 0)
		return TRUE;
	return FALSE;
}

int isFull(HashTable ht){
	if (ht.size == ht.MAXSIZE)
		return TRUE;
	return FALSE;
}

void traverseHashTable(HashTable ht){
	for (int i = 0; i < ht.MAXSIZE; i++)
		printf("\n Table[%2d]: %4d", i, ht.Info[i].ma);
}

int insert(HashTable &ht, SV x){
	if (isFull(ht)){
		printf("\n Bang bam bi day, khong them vao duoc!");
		return ht.MAXSIZE;
	}
	int i = hashFunction(x, ht.MAXSIZE);
	while (ht.Info[i] != NULL){
		i++;
		if (i >= ht.MAXSIZE)
			i = i - ht.MAXSIZE;
	}
	ht.Info[i] = x;
	ht.size++;
	return i;
}