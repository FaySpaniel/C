

#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	cout << "фигура квадрат \n";
	cout << "Введите размер квадрата\n";
	int size;
	cin >> size;
	cout << "Введите текстуру\n";
	char texture;
	cin >> texture;
	int a = 0;
	int b = 0;
	while (a < size) {
		b = 1;
		while (b < size) {
			cout << texture;
			b++; 
		}
		cout<<texture<<endl;
		a++; 
	}
	int _;
	cin >> _;
	return 0;
}

