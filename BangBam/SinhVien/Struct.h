#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define NULLKEY -1
#define SIZE 15

typedef int KeyType;
typedef int ItemType;
struct HashTable
{
	ItemType *Info;
	int size;
	int MAXSIZE = 0;
};

int hashFunction(KeyType key){
	return (key % SIZE);
}
void initHashTable(HashTable &ht){
	for (int i = 0; i < SIZE; i++)
		ht.Info[i] = NULLKEY;
	ht.size = 0;
}
int hashFunction(KeyType key, int size){
	return (key % size);
}
void initHashTable(HashTable &ht, int size){
	ht.MAXSIZE = size;
	ht.Info = new ItemType[ht.MAXSIZE];
	for (int i = 0; i < size; i++)
		ht.Info[i] = NULLKEY;
	ht.size = 0;
}
//========================================
void resize(HashTable &ht, int MaxSizeNew){
	ItemType *temp = new ItemType[MaxSizeNew];
	for (int i = 0; i < MaxSizeNew; i++)
		temp[i] = NULLKEY;
	for (int i = 0; i < ht.MAXSIZE; i++)
		temp[i] = ht.Info[i];
	ht.MAXSIZE = MaxSizeNew;
	ht.Info = new ItemType[ht.MAXSIZE];
	for (int i = 0; i < ht.MAXSIZE; i++)
		ht.Info[i] = temp[i];
}
//========================================
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
		printf("\n Table[%2d]: %4d", i, ht.Info[i]);
}
void clear(HashTable &ht){
	for (int i = 0; i < ht.MAXSIZE; i++)
		ht.Info[i] = NULLKEY;
	ht.size = 0;
}
int insert(HashTable &ht, ItemType x){
	if (isFull(ht)){
		printf("\n Bang bam bi day, khong them vao duoc!");
		return ht.MAXSIZE;
	}
	int i = hashFunction(x, ht.MAXSIZE);
	while (ht.Info[i] != NULLKEY){
		i++;
		if (i >= ht.MAXSIZE)
			i = i - ht.MAXSIZE;
	}
	ht.Info[i] = x;
	ht.size++;
	return i;
}
int search(HashTable ht, KeyType k){
	int i = hashFunction(k, ht.MAXSIZE);
	int pivot = i;
	while (ht.Info[i] != k){
		i++;
		if (i >= ht.MAXSIZE)
			i = i - ht.MAXSIZE;
		if (i == pivot) return ht.MAXSIZE;
	}
	return i;
}
int remove(HashTable &ht, KeyType k){
	int i = hashFunction(k, ht.MAXSIZE);
	int pivot = i;
	while (ht.Info[i] != k){
		i = i + 1;
		if (i >= ht.MAXSIZE)
			i = i - ht.MAXSIZE;
		if (i == pivot) return FALSE;
	}
	ht.Info[i] = NULLKEY;
	ht.size--;
	return TRUE;
}
void createHashTable_Random(HashTable &ht, int n){
	srand(unsigned(time(NULL)));
	for (int i = 0; i < n; i++){
		KeyType key = rand() % 1000;
		insert(ht, key);
	}
}