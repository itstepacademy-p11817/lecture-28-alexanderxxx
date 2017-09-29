#include <iostream>
#include <cstdlib>
#include <utility>
#include <time.h>
#include <string.h>
#include <stdio.h>






typedef union
{
	int i;
	bool b[4];
}un;


void f_nb(un* asd)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (asd->b[i] == 0)
		{
			count++;
		}
	}
	std::cout << count << '\n';
	for (int i = 0; i < 4; i++)
	{
		std::cout << (int)asd->b[i] << " ";
	}
}




int main()
{
	setlocale(0, "");
	un a;
	a.i = 121212;
	f_nb(&a);


	system("pause");
	return 0;
}