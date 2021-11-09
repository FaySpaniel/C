#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "");
    float arr1[10] = { 1.1 , 1.2 , 1.3 , 1.4 , 1.5 , 1.6, 1.7, 1.8 , 1.9, 2.1 };
    double arr2[10] = { 1.12 , 1.23 , 1.34 , 1.45 , 1.56 , 1.678, 1.78, 1.89 , 1.96, 2.15 };
    int arr3[10] = { 228, 1488, 1337, 295, 478, 666, 555, 876, 994, 88 };
    short arr4[10] = { 2289, 14888, 13367, 5295, 4738, 6466, 5555, 8766, 9924, 838 };
    long arr5[10] = { 2285858, 9870981488, 1337687, 245695, 3656478, 8789666, 50955, 835654376, 9356794, 87567488 };
    char arr6[10] = { 'f', 'l', 'o' , 'p' ,'p' , 'a' , '-' , 'g' , 'o', 'd' };
    string arr7[10] = { "bol'shie" , "pel'meni" , "eto" , "ochen'" , "vkusno", "ot" , "russkogo", "kota", "S'hle", "ppi" };
    bool arr8[10] = { 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 };

    cout << "Выберите массив данных для вывода: \n[1] float\n[2] double\n[3] int\n[4] short\n[5] long\n[6] char\n[7] string\n[8] (cyber)bool(ing)\n";
    int a;
    cin >> a;
    cout << "\n";
    switch (a)
    {
    case 1:
        for (int i = 0; i < 10; i++)
        {
            cout << "[" << i + 1 << "]" << " - " << arr1[i] << endl;
        }
        break;
    case 2:
        for (int i = 0; i < 10; i++)
        {
            cout << "[" << i + 1 << "]" << " - " << arr2[i] << endl;
        }
        break;
    case 3:
        for (int i = 0; i < 10; i++)
        {
            cout << "[" << i + 1 << "]" << " - " << arr3[i] << endl;
        }
        break;
    case 4:
        for (int i = 0; i < 10; i++)
        {
            cout << "[" << i + 1 << "]" << " - " << arr4[i] << endl;
        }
        break;
    case 5:
        for (int i = 0; i < 10; i++)
        {
            cout << "[" << i + 1 << "]" << " - " << arr5[i] << endl;
        }
        break;
    case 6:
        for (int i = 0; i < 10; i++)
        {
            cout << "[" << i + 1 << "]" << " - " << arr6[i] << endl;
        }
        break;
    case 7:
        for (int i = 0; i < 10; i++)
        {
            cout << "[" << i + 1 << "]" << " - " << arr7[i] << endl;
        }
        break;
    case 8:
        for (int i = 0; i < 10; i++)
        {
            cout << "[" << i + 1 << "]" << " - " << arr8[i] << endl;
        }
        break;
    default:
        cout << "Вы ввели неприкольный прикол..........";
        break;

    }

    int _;
    cin >> _;
    return 0;
}
