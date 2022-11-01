#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Sach
{
	char maSach[15];
	char tenSach[30];
	int soTrang, namSX;
	float gia;
};

typedef Sach itemType;
struct node
{
	itemType *info;
	node *next;
};

node* createNode(itemType *x)
{
	node *p = new node;
	if (p == NULL)
	{
		printf("Khong du bo nho de tao nut!");
		getch();
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void show1Sach(Sach *s)
{
	printf("%s\t%-15s\t%d\t%d\t%f", s->maSach, s->tenSach, s->soTrang, s->namSX, s->gia);
}

void showNode(node *p)
{
	show1Sach(p->info);
}

struct list
{
	node *head;
	node *tail;
};

void initList(list &l)
{
	l.head = l.tail = NULL;
}

int isEmpty(list l)
{
	if (l.head == NULL)
		return 1;
	return 0;
}

void showList(list l)
{
	if (isEmpty(l))
	{
		printf("Danh sach rong!");
		getch();
		return;
	}
	for (node *p = l.head; p != NULL; p = p->next)
		showNode(p);
}

int insertTail(list &l, node *p)
{
	if (p == NULL)
		return 0;
	if (isEmpty(l))
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
	return 1;
}

void createListFromFile(list &l)
{
	FILE *fileInput = fopen("INPUT.TXT", "r");
	if (!fileInput)
	{
		printf("File khong ton tai! xin kiem tra lai");
		getch();
		exit(0);
	}
	
	node *p;
	char st[10];
	char nsx[10];
	char g[15];
	while (!feof(fileInput))
	{
		Sach *s = new Sach;
		fscanf(fileInput, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%s", s->maSach, s->tenSach, st, nsx, g);
		s->soTrang = atoi(st);
		s->namSX = atoi(nsx);
		s->gia = atof(g);
		p = createNode(s);
		insertTail(l, p);
	}
	fclose(fileInput);
}

void inSachCoSoTrangLonHon500(list l)
{
	for (node *p = l.head; p != NULL; p = p->next)
	{
		if (p->info->soTrang > 500)
		{
			showNode(p);
		}
	}
}


int deleteNode(list &l, node *p)
{
	if (isEmpty(l))
		return 0;
	if (p == l.head)
	{
		l.head = l.head->next;
		if (l.head == NULL)
			l.tail = NULL;
	}
	else
	{
		node *q = l.head;
		while (q->next != p)
			q = q->next;
		q->next = p->next;
		if (p == l.tail)
			l.tail = q;
	}
	return 1;
}

void upLoadFile(list &l)
{
	FILE *fileOutput = fopen("INPUT.TXT", "w+");
	for (node *p = l.head; p != NULL; p = p->next)
	{
		fprintf(fileOutput, "%s\t%s\t%d\t%d\t%f", p->info->maSach, p->info->tenSach, p->info->soTrang, p->info->namSX, p->info->gia);
	}
	fclose(fileOutput);
}

void xoaSachCoGiaBanHon100000(list &l)
{
	node *p = l.head;
	while (p != NULL)
	{
		node *z = new node;
		if (p->info->gia > 100000)
		{
			z = p;
			deleteNode(l, p);
		}
		p = p->next;
		delete z;
	}
	upLoadFile(l);
}