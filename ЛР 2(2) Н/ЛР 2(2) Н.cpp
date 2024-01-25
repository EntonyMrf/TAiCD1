#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <algorithm>
using namespace std;

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i, n, k, a, beg0, beg, end;
	char str[1000];
	cout << "Введите строку: ";
	cin.getline(str, strlen(str));
	n = strlen(str);
	k = 1;
	i = 0;
	while (i <= n)
	{
		while (str[i] != ' ') i++;
		if ((str[i] == ' ') && (str[i + 1] == ' '))
		{
			while (str[i + 1] == ' ') i++;
		}
		if ((str[i] == ' ') && (str[i + 1] != ' '))
		{
			beg0 = i + 1;
			while ((str[i + 1] != ' ') && (str[i + 1] != '!') && (str[i + 1] != '?') && (str[i + 1] != '.') && (str[i + 1] != ',') && (str[i + 1] != ':') && (str[i + 1] != ';'))
			{
				i++;
			}
			k++;
			beg = beg0;
			end = i;
		}
		if (k % 2 == 0)
		{
			while (beg <= end)
			{
				a = str[beg];
				str[beg] = str[end];
				str[end] = a;
				beg++;
				end--;
			}
		}
	}
	cout << "\nИзменённая строка: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << str[i];
	}
	cout << endl;
	return 0;
}