#include <iostream> 
using namespace std;

int main()
{
    setlocale(0, "");

    int season;
    cout << "Выбери время года: \n[1] Зима \n[2] Весна \n[3] Лето \n[4] Осень \n";
    cin >> season;
    if (season == 1)
    {
        cout << "Сейчас зима. Шапку надел";
    }
    else if (season == 2)
    {
        cout << "Сейчас весна. сапоги резиновые одел";
    }
    else if (season == 3)
    {
        cout << "Сейчас лето. шорты одел";
    }
    else if (season == 4)
    {
        cout << "Сейчас осень. одел портфель";
    }
    else
    {
        cout << "Нет такого времени года!";
    }

    return 0;
}
