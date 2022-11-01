#include"Struct.h"

void showMenu()
{
	printf("\n*************************************************");
	printf("\n*                     MENU                      *");
	printf("\n*************************************************");
	printf("\n* 1.Tao danh sach tu file                       *");
	printf("\n* 2.Xuat danh sach                              *");
	printf("\n* 3.In nhung cuon sach co so trang > 500        *");
	printf("\n* 4.Xoa tat cac sach co gia ban hon 100000      *");
	printf("\n* 5.                                            *");
	printf("\n* 6.                                            *");
	printf("\n*************************************************");
}

void process()
{
	int luaChon;
	list l;
	initList(l);
	do
	{
		showMenu();
		printf("\nNhap lua chon cua ban: ");
		scanf("%d", &luaChon);
		switch (luaChon)
		{
		case 1:
			createListFromFile(l);
			break;
		case 2:
			showList(l);
			break;
		case 3:
			inSachCoSoTrangLonHon500(l);
			break;
		case 4:
			xoaSachCoGiaBanHon100000(l);
			break;
		default:
			break;
		}
	} while (luaChon != 0);
}

int main()
{
	process();
	getch();
	return 0;
}