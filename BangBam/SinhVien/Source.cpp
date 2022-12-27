#include "Struct.h"
void menu(){
	printf("\n________________________MENU________________________");
	printf("\n\t1. Thay doi kich thuoc cua bang bam");
	printf("\n\t2. Them 1 nut vao bang bam");
	printf("\n\t3. Them ngau nhien nhieu nut vao bang bam");
	printf("\n\t4. Xoa 1 nut trong bang bam");
	printf("\n\t5. Xoa toan bo bang bam");
	printf("\n\t6. Duyet bang bam");
	printf("\n\t7. Tim kiem tren bang bam");
	printf("\n\t8. Mo rong bang bam");
	printf("\n\t0. Ket thuc chuong trinh");
	printf("\n____________________________________________________");
}
void main()
{
	int x, pos, i, n, luachon;
	char c;
	ItemType key;
	HashTable ht;
	int MaxSize = 15, MaxSizeNew;
	initHashTable(ht, MaxSize);
	do
	{
		menu();
		printf("\nChuc nang ban chon: "); scanf("%d", &luachon);
		switch (luachon)
		{
		case 1:
			printf("\nNhap kich thuoc toi da cua bang bam: ");
			scanf("%d", &MaxSize);
			initHashTable(ht, MaxSize);
			break;
		case 2:
			printf("\nNhap gia tri khoa cua nut can them vao: ");
			scanf("%d", &key);
			insert(ht, key);
			break;
		case 3:
			do{
				printf("\nSo nut ban muon them: ");
				scanf("%d", &n);
			} while (n <= 0);
			createHashTable_Random(ht, n);
			break;
		case 4:
			printf("\nNhap vao khoa cua nut can xoa: ");
			scanf("%d", &key);
			if (remove(ht, key) == FALSE)
				printf("\nKhoa %d khong ton tai!", key);
			else{
				printf("\nDuyet Bang Bam sau khi xoa %d: ", key);
				traverseHashTable(ht);
			}
			break;
		case 5:
			clear(ht);
			break;
		case 6:
			if (isEmpty(ht))
				printf("\nBang Bam rong!");
			else{
				printf("\nDuyet Bang Bam");
				traverseHashTable(ht);
			}
			break;
		case 7:
			printf("\nKhoa can tim: ");
			scanf("%d", &key);
			pos = search(ht, key);
			if (pos == ht.MAXSIZE)
				printf("\nKhong tim thay %d trong bang bam", key);
			else
				printf("\nTim thay %d trong bang bam", key);
			break;
		case 8:
			printf("\nBan muon mo them bao nhieu nut: ");
			scanf("%d", &x);
			MaxSizeNew = MaxSize + x;
			resize(ht, MaxSizeNew);
			break;
		}
	} while (luachon != 0);
	getch();
}