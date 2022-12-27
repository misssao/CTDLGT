#include "Struct.h"

int main()
{
	InitHashTable();
	/*Tu t1 = GanGiaTriChoTu("apple", "Qua Tao");

	Push(t1);
	Search("apple");*/
	AddFromFile();
	Traverse();

	getch();
	return 0;
}