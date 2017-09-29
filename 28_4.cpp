#include <iostream>
#include <cstdlib>
#include <utility>
#include <time.h>
#include <string.h>
#include <stdio.h>

typedef enum
{
	CHAR,
	INT
}type_t;

typedef struct
{
	type_t type;
	union
	{
		char nc[8];
		int n;
	};
}num;

/*
typedef union
{
	char nc[8];
	int n;
}num;
*/

typedef struct
{
	num  n;
	char model[100];
	char color[100];
}car;


void create_car(car* c)
{
	int g = 0;
	std::cout << "1 - int, 2 char: ";
	std::cin >> g;
	if (g == 1)
	{
		c->n.type = INT;
		std::cout << "Num: ";
		std::cin >> c->n.n;
	}
	else if (g == 2)
	{
		c->n.type = CHAR;
		std::cout << "Num: ";
		std::cin >> c->n.nc;
	}
	std::cout << "Model: ";
	std::cin >> c->model;
	std::cout << "Color: ";
	std::cin >> c->color;
}

void print_car(car* c_m, int i)
{
	
	if (c_m[i].n.type == CHAR)
	{
		std::cout << "Num: " << c_m[i].n.nc << '\n';
	}
	else if (c_m[i].n.type == INT)
	{
		std::cout << "Num: " << c_m[i].n.n << '\n';
	}
	std::cout << "Model: " << c_m[i].model << '\n';
	std::cout << "Color: " << c_m[i].color << '\n' << '\n';
}





int main()
{
	setlocale(0, "");
	int g = -1;
	car c_m[10];
	car c;

	//num a;
	//num b;



	//a.type = CHAR;
	//b.type = INT;


	
	while (g != 0)
	{
		std::cout << "1 - Create car, 2 - Edit car, 3 - Print car, 4 - Print all car, 5 - Find car, 0 - Exit: ";
		std::cin >> g;
		if (g == 1)
		{
			int i = 0;
			while (i < 10)
			{
				create_car(&c);
				c_m[i] = c;
				i++;
			}
			g = -1;
		}
		else if (g == 2)
		{
			int i = 0;
			std::cout << "Car index: ";
			std::cin >> i;
			create_car(&c);
			c_m[i] = c;
			g = -1;
		}
		else if (g == 3)
		{
			int i = 0;
			std::cout << "Car index: ";
			std::cin >> i;
			print_car(c_m,i);
			g = -1;
		}
		else if (g == 4)
		{
			for (int i = 0; i < 10; i++)
			{
				if (c_m[i].n.type == CHAR)
				{
					std::cout << c_m[i].n.nc;
				}
				else if (c_m[i].n.type == INT)
				{
					std::cout << c_m[i].n.n;
				}
				std::cout << "Model: " << c_m[i].model << '\n';
				std::cout << "Color: " << c_m[i].color << '\n' << '\n';
			}
			g = -1;
		}
		else if (g == 5)
		{
			int n = 0;
			std::cout << "1 - int, 2 char: ";
			std::cin >> n;
			if (n == 1)
			{
				std::cout << "Num: ";
				std::cin >> c.n.n;
				for (int i = 0; i < 10; i++)
				{
					if (c_m[i].n.n == c.n.n)
					{
						print_car(c_m, i);
						break;
					}
				}
				std::cout << "Not exist" << '\n';
			}
			else if (n == 2)
			{
				std::cout << "Num: ";
				std::cin >> c.n.nc;
				for (int i = 0; i < 10; i++)
				{
					if (strcmp(c_m[i].n.nc, c.n.nc) == 0);
					{
						print_car(c_m, i);
						break;
					}
				}
				std::cout << "Not exist" << '\n';
			}
			g = -1;
		}
	}



	//system("pause");
	return 0;
}