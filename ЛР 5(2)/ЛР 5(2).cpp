#include <iostream>
#include <windows.h>
#include "E:\Информатика\ТАиСД\Лабораторные за 1 семестр 2 курса\Diapason\Diapason.cpp"

using namespace std;

double InputValidation(double num, string s);
int InputValidation(int num, string s);

int main() {
    setlocale(0, "");
    Diapason D, d;
    double z = 0;
    int num = 0;
    D.x = InputValidation(D.x, "Введите начало диапазона: ");
    D.y = InputValidation(D.y, "Введите конец  диапазона: ");
    z = InputValidation(z, "Введите число для проверки на вхождение: ");
	num = InputValidation(num, "Введите на сколько нужно увеличить координаты: ");
    int increase, decrease;

    cout << "\nВаш диапазон:"
        << "\n" << D.x << " ... " << D.y
        << "\n\nУнарные операции:\nДлина диапазона: " << D.size()
		<< "\nОперация по увелечению координат на 1: "
        << "\nКоордината X: " << D.unar_operation(D.x)
        << "\nКоордината Y: " << D.unar_operation(D.y)
        << "\n\nОперации приведения типа:\nЦелая часть от X: " << D.Convert(D.x)
        << "\nКоордината Y: " << D.Convert(D.y)
        << "\n\nБинарные операции:\n1.Операция по увелечению координат на заданное число:"
		<< "\nКоординаты диапазона после увеличения: "
        << "\nКоордината X: " << D.binar_operation(num, D.x)
        << "\nКоордината Y: " << D.binar_operation(num, D.y)
        << "\n\n2.Операция по проверке на вхождение числа:"
        << "\nРезультат: " << D.binar_operation(D, z) << '\n';
}
double InputValidation(double num, string s) {
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
int InputValidation(int num, string s) {
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