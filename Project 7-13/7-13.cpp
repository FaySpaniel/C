#include <iostream>
using namespace std;

int main() {
	setlocale(0, "");
	cout << "Выберите фигуру: \n[1]Линия\n[2]Квадрат\n[3]Пустой квадрат\n[4]Прямоугольник\n[5]Пустой прямоугольник\n[6]Треугольник\n[7]Пустой треугольник\n[8]Решетка\n[9]Крест\n[10]Плюс\n";
	int figure;
	cin >> figure;
	if (figure == 1)
	{
		cout << "Введите длину линии: ";
		int size;
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			cout << "[]";
		}
	}
	else if (figure == 2)
	{
		cout << "Введите длину боковой грани квадрата: ";
		int size;
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			cout << "\n";
			for (int k = 0; k < size; k++)
			{
				cout << "[]";
			}
		}
	}
	else if (figure == 3)
	{
		cout << "Введите длину боковой грани квадрата: ";
		int size;
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			cout << "\n";
			for (int k = 0; k < size; k++)
			{
				if (i == 0 || i == size - 1 || k == 0 || k == size - 1)
				{
					cout << "[]";
				}
				else
				{
					cout << "  ";
				}
			}
		}
	}
	else if (figure == 4)
	{
		cout << "Введите длину прмяоугольника: ";
		int size1;
		cin >> size1;
		cout << "Введите ширину прмяоугольника: ";
		int size2;
		cin >> size2;
		for (int i = 0; i < size1; i++)
		{
			cout << "\n";
			for (int k = 0; k < size2; k++)
			{
				cout << "[]";
			}
		}
	}
	else if (figure == 5)
	{
		cout << "Введите длину прямоугольника ";
		int size1,
			size2;
		cin >> size1;
		cout << "Введите ширину прямоугольника ";
		cin >> size2;

		for (int i = 0; i < size1; i++)
		{
			cout << "\n";
			for (int k = 0; k < size2; k++)
			{
				if (i == 0 || i == size1 - 1 || k == 0 || k == size2 - 1)
				{
					cout << "[]";
				}
				else
				{
					cout << "  ";
				}
			}
		}
	}

	else if (figure == 6)
	{
		cout << "Введите основние: ";
		int size;
		cin >> size;
		cout << "Введите текстуру: ";
		char symb;
		cin >> symb;
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				if (x == size / 2 + y || x == size / 2 - y || y == size / 2 || x >= size / 2 - y && x <= size / 2 + y && y <= size / 2)
				{
					cout << symb << " ";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << "\n";
		}


		int _;
		cin >> _;
		return 0;
	}
	else if (figure == 7)
	{
		cout << "Введите основание: ";
		int size;
		cin >> size;
		cout << "Введите текстуру: ";
		char symb;
		cin >> symb;
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				if (x == size / 2 + y || x == size / 2 - y || y == size / 2)
				{
					cout << symb << " ";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << "\n";
		}


		int _;
		cin >> _;
		return 0;
	}

	else if (figure == 8)
	{
		cout << "Введите длину решетки(лучше нечетную))))): ";
		int size;
		cin >> size;
		cout << "Введите текстуру: ";
		char symb;
		cin >> symb;
		for (int y = 1; y <= size; y++)
		{
			cout << "\n";
			for (int x = 1; x <= size; x++)
			{
				if (y % 2 == 0 || x % 2 == 0)
				{
					cout << symb << " ";
				}
				else
				{

					cout << "  ";

				}
			}
		}
	}

	else if (figure == 9)
	{
		cout << "Введите длину креста: ";

		int size;
		cin >> size;
		cout << "Введите текстуру: ";
		char symb;
		cin >> symb;
		cout << endl;
		for (int y = 0; y <= size; y++)
		{
			for (int x = 0; x <= size; x++)
			{
				if (x == y || x == size - y)
				{
					cout << symb << " ";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << "\n";
		}
	}

	else if (figure == 10)
	{
		cout << "Введите длину плюса (лучше нечетную))): ";

		int size;
		cin >> size;
		cout << "Введите текстуру: ";
		char symb;
		cin >> symb;
		cout << endl;
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				if (x == size / 2 || y == size / 2)
				{
					cout << symb << " ";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << "\n";
		}
	}


	else
	{
		cout << "\nВы ввели что-то не то :(";
	}
}
