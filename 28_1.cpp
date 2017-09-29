#include <iostream>
#include <cstdlib>
#include <utility>
#include <time.h>
#include <string.h>
#include <stdio.h>



typedef enum
{
	SINT,
	UINT
}type_t;

typedef struct
{
	type_t type;
	union
	{
		int sint;
		unsigned int uint;
	};
}un;


void f(un* asd)
{
	if (asd->type == SINT)
	{
		std::cout << asd->uint << '\n';
	}
	else if (asd->type == UINT)
	{
		std::cout << asd->sint << '\n';
	}

}



int main()
{
	setlocale(0, "");
	//int a = -2312312;
	//unsigned int b = 2312312;
	un a;
	un b;
	a.type = SINT;
	b.type = UINT;
	a.sint = -23423424;
	b.uint = 34234234;
	f(&a);
	f(&b);

	system("pause");
	return 0;
}