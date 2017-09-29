#include <iostream>
#include <cstdlib>
#include <utility>
#include <time.h>
#include <string.h>
#include <stdio.h>






typedef union
{
	int i;
	unsigned char ch[4];
}un;


void f_i(un* asd)
{
	std::cout << asd->i << '\n';
}

void f_bytes(un* asd)
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << (int)asd->ch[i] << " ";
	}
	std::cout << '\n';
}

void f_byte(un* asd)
{
	std::cout << "номер байта: ";
	int n = 0;
	std::cin >> n;
	std::cout << (int)asd->ch[n] << '\n';
}


void f_hex(un* asd)
{
	std::cout << std::hex << asd->i << '\n';
}


int main()
{
	setlocale(0, "");
	un a;
	a.i = 23423424;
	f_i(&a);
	f_bytes(&a);
	f_byte(&a);
	f_hex(&a);

	system("pause");
	return 0;
}