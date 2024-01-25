#include <iostream>
#include "D:\Информатика\ТАиСД\Лабораторные за 1 семестр 2 курса\Diapason\Diapason.cpp"

using namespace std;

double inter(double x, double y, double z);
double InputValidation(double num, string s);

int main()
{
    setlocale(0, "");
    Diapason D;
    double z;
    D.x = InputValidation(D.x, "Введите начало диапазона: ");
    D.y = InputValidation(D.y, "Введите конец диапазона: ");
    cout << "Введите число: ";
    cin >> z;
    cout << "Ваш диапазон: [" << D.x << " ; " << D.y << "]" << endl;
    cout << "\n\nРезультаты проверки на вхождение в диапазон через метод: " << D.intersection(D, z)
        << "\nРезультаты проверки на вхождение в диапазон через функцию: " << inter(D.x, D.y, z)
        << "\n\nВсего было создано " << Diapason::getCounter() << " объектов класса\n";
}

double inter(double x, double y, double z)
{
    return ((z >= x) && (z <= y));
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