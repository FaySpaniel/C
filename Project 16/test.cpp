#include <iostream>
using namespace std;

int getInt() {
    return 4;
}
int getChar() {
    return 1;
}
int getDouble() {
    return 8;
}
int getFloat() {
    return 4;
}
int getBooleanSize() {
    return 1;
}
string Message() {
    return "Привет я функция!\n\n";
}
string otkogo() {
    return "Выполнил студент группы 2ИСП11-14 Сафронов Кирилл\n";
}
void Square() {
        cout << "#####\n";
        cout << "#####\n";
        cout << "#####\n";
        cout << "#####\n";
        cout << "#####\n";
}
int main() {
    setlocale(0, "");
    system("color 0c");
    cout << otkogo();
    printf("Int: %i", getInt());
    printf("\nChar: %i", getChar());
    printf("\nDouble: %i", getDouble());
    printf("\nFloat: %i", getFloat());
    printf("\nBool: %i\n\n", getBooleanSize());
    cout<< Message();
    Square();
    int _;
    cin >>_;
    return 0;
}