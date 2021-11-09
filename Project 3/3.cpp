#include <iostream> 
using namespace std;

int main()
{
    setlocale(0, "");

    int operation,
        a,
        b;
    cout << "Выбери арифметическую операцию: \n[1] + \n[2] - \n[3] * \n[4] / \n[5] % \n";
    cin >> operation;
    cout << "Введи первое число: ";
    cin >> a;
    cout << "\nВведи второе число: ";
    cin >> b;

    if (operation == 1)
    {
        cout << "\n" << a << " + " << b << " = " << a + b;
    }
    else if (operation == 2)
    {
        cout << "\n" << a << " - " << b << " = " << a - b;
    }
    else if (operation == 3)
    {
        cout << "\n" << a << " * " << b << " = " << a * b;
    }
    else if (operation == 4)
    {
        cout << "\n" << a << " / " << b << " = " << a / b;
    }
    else if (operation == 5)
    {
        cout << "\n" << a << " % " << b << " = " << a % b;
    }
    else
    {
        cout << "\nШо error";
    }

    return 0;
}
