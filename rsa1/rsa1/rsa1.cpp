#include "pch.h"
#include <iostream>
#include <cstdio>
using namespace std;

bool Is_simple(int x)
{
	if (x < 2)
		return false;

	if (x == 2)
		return true;

	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int Get_e(int u)
{
	int e = 2;
	for (int i = 2; i <= u; i++)
	{
		if ((e % i == 0) && (u % i == 0))
		{
			e++; i = 1;
		}
	}
	return e;
}

int Get_d(int a, int b) //(e,u)
{
	int t, q, x1, x2, y1, y2, mod;
	mod = b;
	x1 = 1; x2 = 0; y1 = 0; y2 = 1;

	while (b != 1)
	{
		t = b;
		q = a / t;
		b = a % t;
		a = t;
		t = x1; x1 = x2; x2 = t - q * x1;
		t = y1; y1 = y2; y2 = t - q * y1;
	}
	x2 = (x2 + mod) % mod;
	return x2;
}

char crypt(char m, int e, int n)
{
	int base = m;
	int deg = 1;
	for (int i = 0; i < e; i++)
	{
		deg = (deg*base) % n;
	}
	return (deg);
}

int main()
{
	printf("Введите значения p и q (должны быть простыми числами!):\n");
	int p, q;
	scanf("%d %d", &p, &q);

	if (Is_simple(p) && Is_simple(q))
	{

		int n = p * q;
		int u = (p - 1)*(q - 1);

		int e = Get_e(u);
		int d = Get_d(e, u);

		printf("\nОткрытый ключ - [%d,%d]\n", e, n);
		char m;
		printf("\nВведите сообщение для шифрования:  \n");
		scanf("%d", &m);
		char encm;
		encm = crypt(m, e, n);
		printf("\nЗашифрованное открытым ключом сообщение  - %d \n", encm);
		printf("\nЗакрытый ключ - {%d,%d}\n", d, n);
		m = crypt(encm, d, n);
		printf("\nРасшифрованное закрытым ключом сообщение - %d \n", m);
	}
	else
		printf("Числа p и q не являются простыми!");

	return 0;
}
