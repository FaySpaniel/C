
#include <iostream>

using namespace std;

    int main()
    {
        setlocale(0, "");
        char lang;
        char deist;
        int words;
        cout << "[!] Привет, выбери действие" << endl << endl;
        cout << "[r] Русские слова" << endl << endl;
        cout << "[а] английские слова" << endl << endl;
        cout << "[e] выход " << endl << endl;

        cin >> lang;

        switch (lang) {
        case 'r':
            cout << "[l] Вывести список слов" << endl;
            cout << "[e] Выход" << endl;
            cout << "[!] Выбери действие " << endl;
            cin >> deist;
            switch (deist)
            {
            case'l':
                cout << "[1] Я" << endl;
                cout << "[2] Ты" << endl;
                cout << "[3] Он" << endl;
                cout << "[4] Она" << endl;
                cout << "[5] Оно" << endl;
                cout << "[6] Мы" << endl;
                cout << "[7] Вы" << endl;
                cout << "[8] Они" << endl;
                cout << "[9] Тебя" << endl;
                cout << "[10] Их" << endl;
                cout << "[11] Нас" << endl;
                cout << "[12] Обоих" << endl;
                cout << "[13] Да" << endl;
                cout << "[14] Нет" << endl;
                cout << "[15] Может" << endl;
                cout << "выбери номер слова" << endl;
                cin >> words;
                switch (words)
                {
                case 1:
                    cout << "Я";
                    break;
                case 2:
                    cout << "Ты ";
                    break;
                case 3:
                    cout << "Он ";
                    break;
                case 4:
                    cout << "Она ";
                    break;
                case 5:
                    cout << "Оно ";
                    break;
                case 6:
                    cout << "Мы ";
                    break;
                case 7:
                    cout << "Вы ";
                    break;
                case 8:
                    cout << "Они ";
                    break;
                case 9:
                    cout << "Тебя ";
                    break;
                case 10:
                    cout << "Их ";
                    break;
                case 11:
                    cout << "Нас ";
                    break;
                case 12:
                    cout << "Обоих ";
                    break;
                case 13:
                    cout << "Да ";
                    break;
                case 14:
                    cout << "Нет ";
                    break;
                case 15:
                    cout << "Может ";
                    break;
                }
            case'e':
                cout << "Пока";
                return 0;
            default:
                cout << "нет такого слова";
                break;
            }
        case 'a':
            cout << "[l] Вывести список слов" << endl;
            cout << "[e] Выход" << endl;
            cout << "[!] Выбери действие " << endl;
            cin >> deist;
            switch (deist)
            {
            case'l':
                cout << "[1] I" << endl;
                cout << "[2] You" << endl;
                cout << "[3] He" << endl;
                cout << "[4] She" << endl;
                cout << "[5] It" << endl;
                cout << "[6] We" << endl;
                cout << "[7] You" << endl;
                cout << "[8] They" << endl;
                cout << "[9] Thee" << endl;
                cout << "[10] Their" << endl;
                cout << "[11] Us" << endl;
                cout << "[12] Both" << endl;
                cout << "[13] Yes" << endl;
                cout << "[14] No" << endl;
                cout << "[15] Maybe" << endl;
                cout << "выбери номер слова" << endl;
                cin >> words;
                switch (words)
                {
                case 1:
                    cout << "I";
                    break;
                case 2:
                    cout << "You ";
                    break;
                case 3:
                    cout << "He ";
                    break;
                case 4:
                    cout << "She ";
                    break;
                case 5:
                    cout << "It ";
                    break;
                case 6:
                    cout << "We ";
                    break;
                case 7:
                    cout << "You ";
                    break;
                case 8:
                    cout << "They ";
                    break;
                case 9:
                    cout << "Thee ";
                    break;
                case 10:
                    cout << "Their ";
                    break;
                case 11:
                    cout << "Us ";
                    break;
                case 12:
                    cout << "Both ";
                    break;
                case 13:
                    cout << "Yes ";
                    break;
                case 14:
                    cout << "No ";
                    break;
                case 15:
                    cout << "Maybe ";
                    break;
                }
            case'e':
                cout << "Пока";
                return 0;
            default:
                cout << "нет такого слова";
                break;
            }

            break;
        case'e':
            cout << "Пока";
            return 0;
        default:
            cout << "нет такого слова";
            break;
        }

    }

