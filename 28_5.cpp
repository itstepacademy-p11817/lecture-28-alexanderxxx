#include <iostream>
#include <cstdlib>
#include <utility>
#include <time.h>
#include <string.h>
#include <stdio.h>

typedef enum
{
	PT,
	SK,
	CH
}type_t;
/*
typedef struct
{
	type_d_t type;
	union
	{
		char nc[8];
		int n;
	};
}num;
*/

typedef union
{
	double speed_p;
	bool p;
	int iq;
}charact;


typedef struct
{
	int speed;
	type_t type;
	char color[100];
	charact ch;



}alive;


void create_alive(alive* c)
{
	int g = 0;
	std::cout << "type, 1 - Птица, 2 - Скот, 3 - Человек: ";
	std::cin >> g;
	if (g == 1)
	{
		c->type = PT;
		std::cout << "Характеристика, скорость полёта: ";
		std::cin >> c->ch.speed_p;
	}
	else if (g == 2)
	{
		c->type = SK;
		std::cout << "Характеристика, парнокопытное или не: ";
		std::cin >> c->ch.p;
	}
	else if (g == 3)
	{
		c->type = CH;
		std::cout << "Характеристика, iq: ";
		std::cin >> c->ch.iq;
	}

	std::cout << "скорость передвижения: ";
	std::cin >> c->speed;
	std::cout << "Color: ";
	std::cin >> c->color;
}

void print_alive(alive* c_m, int i)
{

	if (c_m[i].type == PT)
	{
		std::cout << "Птица" << '\n' << "Скорость полёта: " << c_m[i].ch.speed_p << '\n';
	}
	else if (c_m[i].type == SK)
	{
		std::cout << "Скот" << '\n';
		if (c_m[i].ch.p == 0)
		{
			std::cout << "Не парнокопытное" << '\n';
		}
		else
		{
			std::cout << "Парнокопытное" << '\n';
		}
	}
	else if (c_m[i].type == CH)
	{
		std::cout << "Человек" << '\n' << "iq: " << c_m[i].ch.iq << '\n';
	}

	std::cout << "скорость передвижения: " << c_m[i].speed << '\n';
	std::cout << "Color: " << c_m[i].color << '\n' << '\n';
}





int main()
{
	setlocale(0, "");
	int g = -1;
	alive a_m[10];
	alive c;

	//num a;
	//num b;



	//a.type = CHAR;
	//b.type = INT;



	while (g != 0)
	{
		std::cout << "1 - Create, 2 - Edit, 3 - Print, 4 - Print all, 5 - Find, 0 - Exit: ";
		std::cin >> g;
		if (g == 1)
		{
			int i = 0;
			while (i < 10)
			{
				create_alive(&c);
				a_m[i] = c;
				i++;
			}
			g = -1;
		}
		else if (g == 2)
		{
			int i = 0;
			std::cout << "index: ";
			std::cin >> i;
			create_alive(&c);
			a_m[i] = c;
			g = -1;
		}
		else if (g == 3)
		{
			int i = 0;
			std::cout << "index: ";
			std::cin >> i;
			print_alive(a_m, i);
			g = -1;
		}
		else if (g == 4)
		{
			for (int i = 0; i < 10; i++)
			{
				print_alive(a_m, i);
			}
			g = -1;
		}
		else if (g == 5)
		{
			int n = 0;
			std::cout << "type, 1 - Птица, 2 - Скот, 3 - Человек: ";
			std::cin >> n;
			if (n == 1)
			{
				std::cout << "Характеристика, скорость полёта: ";
				std::cin >> c.ch.speed_p;
				for (int i = 0; i < 10; i++)
				{
					if (a_m[i].ch.speed_p == c.ch.speed_p)
					{
						print_alive(a_m, i);
						break;
					}
				}
				std::cout << "Not exist" << '\n';
			}
			else if (n == 2)
			{
				std::cout << "Характеристика, парнокопытное или не: ";
				std::cin >> c.ch.p;
				for (int i = 0; i < 10; i++)
				{
					if (a_m[i].ch.p == c.ch.p);
					{
						print_alive(a_m, i);
						break;
					}
				}
				std::cout << "Not exist" << '\n';
			}
			else if (n == 3)
			{
				std::cout << "Характеристика, iq: ";
				std::cin >> c.ch.iq;
				for (int i = 0; i < 10; i++)
				{
					if (a_m[i].ch.iq == c.ch.iq);
					{
						print_alive(a_m, i);
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