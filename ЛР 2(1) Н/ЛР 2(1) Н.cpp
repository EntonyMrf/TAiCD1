#include <iostream>
#include <vector>
#include <Windows.h>
#include <time.h>

using namespace std;

int InputValidation(int num, string s);
double InputValidation(double num, string s);
int PositiveInputValidation(int num, string s);
double PositiveInputValidation(double n, string s);


int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n = 1, m = 1, choice = 0, k;
    bool b = true, a = true;
    int** mas = new int* [1];

    do
    {
        b = true;

        n = PositiveInputValidation(n, "Введите количество строк: ");
        m = PositiveInputValidation(m, "Введите сколько элементов должно быть в строке: ");

        mas = new int* [n];
        for (int i = 0; i < n; i++)
        {
            mas[i] = new int[m];
        }
        choice = InputValidation(choice, "Выберите способ заполнения массива:"
            "\n1. Вручную\n2. Рандомно\nВаш выбор: ");
        switch (choice)
        {
        case 1:
            cout << "\nЗаполнение массива.\n";
            for (int i = 0; i < n; i++)
            {
                cout << "Заполните " << i + 1 << "-ю строку массива (через пробел или по одному элементу).\n";
                for (int j = 0; j < m; j++)
                {
                    mas[i][j] = InputValidation(mas[i][j], "");
                }
            }
            b = false;
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    mas[i][j] = rand() % 10;
                }
            }
            b = false;
            break;
        default:
            cout << "Некорректный ввод!\n";
            break;
        }
    } while (b);

    cout << "\nИзначальный массив:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mas[i][j] << " ";
        }
        cout << "\n";
    }

    k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mas[i][j] == 0) k += 1;
        }
        if ((k > 0)&&(a))
        {
            while (i <= n)
            {
                mas[i] = mas[i + 1];
                i++;
            }
            n -= 1;
            a = false;
        }
    }

    cout << "\nОбновленный массив:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mas[i][j] << " ";
        }
        cout << "\n";
    }
}

int InputValidation(int num, string s)
{
    bool b = false;
    do {
        b = false;
        cout << s;
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Ошибка ввода!\n";
            b = true;
        }
    } while (b);
    return num;
}

double InputValidation(double num, string s)
{
    bool b = false;
    do {
        b = false;
        cout << s;
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Ошибка ввода!\n";
            b = true;
        }
    } while (b);
    return num;
}

int PositiveInputValidation(int num, string s)
{
    do {
        num = InputValidation(num, s);
        if (num < 1)
        {
            cout << "Ошибка. Введено отрицательно число или 0\n";
        }
    } while (num < 1);
    return num;
}

double PositiveInputValidation(double num, string s)
{
    do {
        num = InputValidation(num, s);
        if (num < 1)
        {
            cout << "Ошибка. Введено отрицательно число или 0\n";
        }
    } while (num < 1);
    return num;
}