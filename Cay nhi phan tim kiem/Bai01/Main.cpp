#include "Struct.h"

int main()
{
	FILE *fileIn = fopen("INPUT.TXT", "r");
	Tree t;
	initTree(t);
	nhapDulLieuTuFile(fileIn, t.root);
	/*printf("Tong = %d", tinhTongCacSoCoGiaTriLonHonX(t.root, 2));*/
	RNL(t.root);
	/*xoaNodeCoDataCoHangDVLa4(t.root, t.root);
	printf("\n");
	RNL(t.root);
	printf("\n");
	xuatCacPTChanGiamDan(t.root);*/
	printf("\n");
	/*int x = 7;
	printf("Phan tu gan %d nhat la: %d", x, timPhanTuCoKCToiXNhoNhat(t.root, x));*/
	//printf("%d", tinhChieuCaoCuaCay(t.root));
	/*xuatCacNutOMucK(t.root, 4);*/
	//printf("%d", Cau6(t.root, 0, 2));
	int i = demNodeLa(t.root);
	int tong;

	printf("%f", Cau8(t.root) * 1.0 / i);
	getch();
	return 0;
} 