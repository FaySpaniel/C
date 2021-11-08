
#include <iostream>
#include<math.h>
using namespace std;

double calc(double num1,double num2,double num3,char symb)
{
    switch (symb)
    {
    case'+': return num1 + num2;
    case'-': return num1 - num2;
    case'*': return num1 * num2;
    case'/': return num1 / num2;
    case'a': return num1 / num2+123;
    case's': return num1 * num1;
    case'b': return 3,14 + pow(num1,2);
    case'с': return num2 * num2 / num1;
    case'd': return 0,5*(num1 * num2);
    case't': return 0,5 * (num1 * num2)*num3;
    default: return 6;
    }
}

int main()
{
    setlocale(0, "");
    system("color 79");
    cout << "Сдеалал студент группы 2ИСП11-14 Сафронов Кирилл\n";
    cout << "Здарова\n";
    cout << "Первое число на базу: ";
    double num1;
    cin >> num1;
    cout << "Второе число на базу: ";
    double num2;
    cin >> num2;
    cout << "Третье число на базу: ";
    double num3;
    cin >> num3;
    cout << "[+] Сложение\n";
    cout << "[-] Вычитание\n";
    cout << "[*] умножение\n";
    cout << "[/] Деление\n";
    cout << "[a] Рандомное действие №1\n";
    cout << "[s] Квадрат числа\n";
    cout << "[b] Площадь круга\n";
    cout << "[с] Рандомное действие №2\n";
    cout << "[d] Площадь треугольника\n";
    cout << "[t] Площадь трапеции\n";
    cout << "Введите действие: ";
    char symb;
    cin >> symb;
    cout << "Результат таков: " << calc(num1, num2,num3, symb) << endl;
    int _;
    cin >> _;
    return 0;
}

