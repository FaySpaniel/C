#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
short questionNumber, amountOfQuestions = 5, menuChoise, settingsChoise, trysAmount = 5, firstHint = 1, secondHint = 1, answer;
short trysChoice, quizHintChoise, correctAnswerPoints = 0, kostylschet = 1;
int massivQuestionsCheck[15];
string backgroundColor, textColor;
string color;
//уборщик текста
void clearAll()
{
	system("cls");
}
//главное меню
void mainMenu()
{
	cout << " [@] Quiz\n\n";
	cout << " [1] Start\n [2] Settings\n [3] Instructions\n [4] Quit\n\n";
	cout << "Choose button: ";
	cin >> menuChoise;
	while (menuChoise < 1 || menuChoise > 4)
	{
		cout << "\nWrong button.\nTry again: ";
		cin >> menuChoise;
	}
}
//цвета
void changeColor()
{
	clearAll();
	cout << "  Available colors: \n\n";
	cout << " [0] - Black\n";
	cout << " [1] - Sapphirine\n";
	cout << " [2] - Green\n";
	cout << " [3] - Blue\n";
	cout << " [4] - Red\n";
	cout << " [5] - Magenta\n";
	cout << " [6] - Yellow\n";
	cout << " [7] - White\n";
	cout << " [8] - Gray\n";
	cout << " [9] - Light sapphirine\n";
	cout << " [A] - Light green\n";
	cout << " [B] - Light blue\n";
	cout << " [C] - Light red\n";
	cout << " [D] - Light magenta\n";
	cout << " [E] - Light yellow\n";
	cout << " [F] - Bright white\n";

	cout << "\n [?] Choose your background color: ";
	cin >> backgroundColor;
	cout << "\n [?] Choose your text color: ";
	cin >> textColor;
	cout << "\n\n";
	color = "color " + backgroundColor + textColor;
	const char* userColor = color.c_str();
	system(userColor);
}
//число попыток
void amountTrys()
{
	clearAll();
	cout << " [2] Try's amount\n\n";
	cout << " [1] one Try\n";
	cout << " [2] three Try's\n";
	cout << " [3] five Try's\n";
	cout << " [4] eight Try's\n";
	cout << " [5] no restrictions\n\n";
	cin >> trysChoice;
	while (trysChoice < 1 || trysChoice > 5)
	{
		cout << "\nWrong button.\nTry again: ";
		cin >> trysChoice;
	}
	switch (trysChoice)
	{
	case 1:
		trysAmount = 1;
		break;
	case 2:
		trysAmount = 3;
		break;
	case 3:
		trysAmount = 5;
		break;
	case 4:
		trysAmount = 8;
		break;
	case 5:
		trysAmount = 300;
		break;
	}
}
//Число вопросов
void amountQuestions()
{
	clearAll();
	cout << " [2] Question's amount\n\n";
	cout << " [1] five question's\n";
	cout << " [2] ten question's\n";
	cout << " [3] 15 question's\n\n";
	int choiceamountOfQuestions = 1;
	cin >> choiceamountOfQuestions;
	while (choiceamountOfQuestions < 1 || choiceamountOfQuestions > 4)
	{
		cout << "\nWrong button.\nTry again: ";
		cin >> amountOfQuestions;
	}
	switch (choiceamountOfQuestions)
	{
	case 1:
		amountOfQuestions = 5;
		break;
	case 2:
		amountOfQuestions = 10;
		break;
	case 3:
		amountOfQuestions = 15;
		break;
	default:
		break;
	}
}
//настройка подсказок
void helpSettings()
{
	clearAll();
	cout << " [4] Help stuff\n\n";
	cout << " [1] 50/50 stuff\n";
	cout << " [2] 1 correct answer\n\n";
	cout << " Do you want to activate the first hint?\n\n";
	cout << " Yes-input 1. No-input 0\n\n";
	if (firstHint == 0)
	{
		cout << " It is currently off" << "\n\n";
	}
	else
	{
		cout << " It is currently on" << "\n\n";
	}
	cin >> firstHint;
	cout << endl;
	while (firstHint < 0 || firstHint > 1)
	{
		cout << "\nWrong button.\nTry again: ";
		cin >> firstHint;
	}
	cout << " Do you want to activate the second hint?\n\n";
	cout << " Yes-input 1. No-input 0\n\n";
	if (secondHint == 0)
	{
		cout << " It is currently off" << "\n\n";
	}
	else
	{
		cout << " It is currently on" << "\n\n";
	}
	cin >> secondHint;
	while (secondHint < 0 || secondHint > 1)
	{
		cout << "\nWrong button.\nTry again: ";
		cin >> secondHint;
	}
}
//меню настроек
void settingsMenu()
{
	clearAll();
	cout << " [2] Settings\n\n";
	cout << " [1] Colors\n [2] Try's amount\n [3] Amount of questions\n [4] Help stuff\n [5] Back to menu\n";
	cout << "Choose button: ";
	cin >> settingsChoise;
	while (settingsChoise < 1 || settingsChoise > 6)
	{
		cout << "\nWrong button.\nTry again: ";
		cin >> settingsChoise;
	}
	switch (settingsChoise)
	{
	case 1:
		changeColor();
		break;
	case 2:
		amountTrys();
		break;
	case 3:
		amountQuestions();
		break;
	case 4:
		helpSettings();
		break;
	case 5:
		clearAll();
		cout << "0";
		break;
	default:
		cout << "placeholder";
		break;
	}
	cout << "\n\n";
}
//инструкции
void Instructions()
{
	cout << " [3] Instructions\n\n";
	cout << "  1)it's a Quiz. You answer questions, if you answer correctly-you go to the next one.\n";
	cout << "  2)If not-you lose one try, and has to answer Quiz again or you lose.\n";
	cout << "  3)There is also a timer.\n";
	cout << "  4)You can activate 2 hints in the settings(i recomend you to check it out actually).\n";
	cout << "  5)I am a cool guy, so they have names like 50/50 stuff and 1 correct answer.\n";
	cout << "  6)The first stuff remove 2 false answers, and the second stuff select the correct answer for you.\n";
	cout << "  7)Basic settings-five questions and zero try's and zero hints.\n";
	cout << "  8)After you finish your game select new trys amount. If you dont do it, than your game wont be started again.\n";
	system("pause");
	cout << "\n\n";
}
//рандом генерирование вопроса
void getQuestion()
{
	questionNumber = 1 + rand() % 15;
}
//проверка на повторение у вопросa
void questionCheck()
{
	int J12 = 0;
	massivQuestionsCheck[questionNumber] = questionNumber;
	while (J12 < 15)
	{
		if (questionNumber = massivQuestionsCheck[J12])
		{
			while (questionNumber != massivQuestionsCheck[J12])
			{
				getQuestion();
			}
		}
		J12++;
	}
}
//вопросы
void defQuestion()
{
	clearAll();
	setlocale(0, "");
	switch (questionNumber)
	{
	//Сам вопрос
	case 1:
		cout << "\t" << "Question 1\n\n";
		cout << "\t" << "2 + 2 = ?\n\n";
		cout << "[1] 5\t" << "[2] 4\t" << endl;
		cout << "[3] Я ещё не проходил такого в школе\t" << "[4] эээээээ\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 2)
		{
			cout << "correct answer is answer 2" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 2)
				{
					cout << "correct answer is answer 2" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 2" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 2)
						{
							cout << "correct answer is answer 2" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 2" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "placeholder\n\n";
					cout << "[1] answer 1\t" << "[2] answer 2\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 2)
					{
						cout << "correct answer is answer 2" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 2" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 2)
						{
							cout << "correct answer is answer 2" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 2" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 2)
					{
						cout << "correct answer is answer 2" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 2" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "placeholder\n\n";
					cout << "answer 2 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 2)
						{
							cout << "correct answer is answer 2" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "2 + 2 = ?\n\n";
					cout << "[1] 5\t" << "[2] 4\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 2)
						{
							cout << "correct answer is answer 2" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 2" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 2)
					{
						cout << "correct answer is answer 2" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 2" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "2 + 2 =?\n\n";
					cout << "answer 1 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
		case 2:
		cout << "\t" << "Question 2\n\n";
		cout << "\t" << "Самая сложная игра на ПК в мире?\n\n";
		cout << "[1] ТНО после ТТ\t" << "[2] Goat simulator\t" << endl;
		cout << "[3] Aurora C#\t" << "[4] Doki-doki literature club\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 3)
		{
			cout << "correct answer is answer 3" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 1)
				{
					cout << "correct answer is answer 3" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 3" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 2\n\n";
					cout << "\t" << "Самая сложная игра на ПК в мире?\n\n";
					cout << "[1] ТНО после ТТ\t" << endl;
					cout << "[3] Aurora C#\t" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 3)
					{
						cout << "correct answer is answer 3" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 3" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 3)
					{
						cout << "correct answer is answer 3" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 3" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 2\n\n";
					cout << "answer 3 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 2\n\n";
					cout << "\t" << "Самая сложная игра на ПК в мире?\n\n";
					cout << "[1] ТНО после ТТ\t" << endl;
					cout << "[3] Aurora C#\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 3)
					{
						cout << "correct answer is answer 3" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 3" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "placeholder\n\n";
					cout << "answer 3 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
	case 3:
		cout << "\t" << "Question 3\n\n";
		cout << "\t" << "int mass[15][15] - что это?\n\n";
		cout << "[1] Одномерный массив\t" << "[2] Двумерный массив\t" << endl;
		cout << "[3] Не знаю\t" << "[4] функция\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 2)
		{
			cout << "correct answer is answer 2" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 2)
				{
					cout << "correct answer is answer 1" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 1" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 2)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 3\n\n";
					cout << "\t" << "int mass[15][15] - что это?\n\n";
					cout << "               \t" << "[2] Двумерный массив\t" << endl;
					cout << "               \t" << "[4] функция\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 2)
					{
						cout << "correct answer is answer 2" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 2" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 1)
						{
							cout << "correct answer is answer 2" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 2" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 2)
					{
						cout << "correct answer is answer 2" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 2" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 3\n\n";
					cout << "answer 2 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 2;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 2)
						{
							cout << "correct answer is answer 2" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 2" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 3\n\n";
					cout << "\t" << "int mass[15][15] - что это?\n\n";
					cout << "               \t" << "[2] Двумерный массив\t" << endl;
					cout << "               \t" << "[4] функция\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 2)
						{
							cout << "correct answer is answer 2" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 2" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 2)
					{
						cout << "correct answer is answer 2" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 2" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "Question 3\n\n";
					cout << "answer 1 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
	case 4:
		cout << "\t" << "Question 4\n";
		cout << "\t" << "Когда произошла авария на ЧС?\n\n";
		cout << "[1] 26 апреля 1986 года\t" << "[2] 19 августа 1991 года\t" << endl;
		cout << "[3] 30 октября 1961 года\t" << "[4] 4 мая 1986 года\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 1)
		{
			cout << "correct answer is answer 1" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 1)
				{
					cout << "correct answer is answer 1" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 1" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 4\n";
					cout << "\t" << "Когда произошла авария на ЧС?\n\n";
					cout << "[1] 26 апреля 1986 года\t" << "                   \t" << endl;
					cout << "                       \t" << "[4] 4 мая 1986 года\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 1)
					{
						cout << "correct answer is answer 1" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 1" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 1)
					{
						cout << "correct answer is answer 1" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 1" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 4\n";
					cout << "\t" << "Когда произошла авария на ЧС?\n\n";
					cout << "[1] 26 апреля 1986 года\t" << endl;
					cout << "answer 1 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 4\n";
					cout << "\t" << "Когда произошла авария на ЧС?\n\n";
					cout << "[1] 26 апреля 1986 года\t" << "                   \t" << endl;
					cout << "                       \t" << "[4] 4 мая 1986 года\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 1)
					{
						cout << "correct answer is answer 1" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 1" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "Question 4\n";
					cout << "\t" << "Когда произошла авария на ЧС?\n\n";
					cout << "[1] 26 апреля 1986 года\t" << endl;
					cout << "answer 1 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
	case 5:
		cout << "\t" << "Question 5\n\n";
		cout << "\t" << "Какие птицы наиболее распрастранённы в европейской части России\n\n";
		cout << "[1] Вороны\t" << "[2] Грачи\t" << endl;
		cout << "[3] Синицы\t" << "[4] Голуби\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 4)
		{
			cout << "correct answer is answer 1" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 4)
				{
					cout << "correct answer is answer 4" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 4" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 4)
						{
							cout << "correct answer is answer 4" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 4" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 5\n\n";
					cout << "\t" << "Какие птицы наиболее распрастранённы в европейской части России\n\n";
					cout << "[1] Вороны\t" << "          \t" << endl;
					cout << "          \t" << "[4] Голуби\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 4)
					{
						cout << "correct answer is answer 4" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 4" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 4)
						{
							cout << "correct answer is answer 4" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 4" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 4)
					{
						cout << "correct answer is answer 4" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 4" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 5\n\n";
					cout << "\t" << "Какие птицы наиболее распрастранённы в европейской части России\n\n";
					cout <<  "[4] Голуби\t" << endl << endl;
					cout << "answer 4 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 4)
						{
							cout << "correct answer is answer 4" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 4" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 5\n\n";
					cout << "\t" << "Какие птицы наиболее распрастранённы в европейской части России\n\n";
					cout << "[1] Вороны\t" << "          \t" << endl;
					cout << "          \t" << "[4] Голуби\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 4)
						{
							cout << "correct answer is answer 4" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 4" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 4)
					{
						cout << "correct answer is answer 4" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 4" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "Question 5\n\n";
					cout << "\t" << "Какие птицы наиболее распрастранённы в европейской части России\n\n";
					cout << "[4] Голуби\t" << endl << endl;
					cout << "answer 1 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
	case 6:
		cout << "\t" << "Question 6\n\n";
		cout << "\t" << "Как называется парламент в Ирландии?\n\n";
		cout << "[1] Дайль\t" << "[2] Гэл\t" << endl;
		cout << "[3] Дойл\t" << "[4] Ленстер Хаус\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 3)
		{
			cout << "correct answer is answer 3" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 3)
				{
					cout << "correct answer is answer 3" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 3" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 6\n\n";
					cout << "\t" << "Как называется парламент в Ирландии?\n\n";
					cout << "[3] Дойл\t" << "[4] Ленстер Хаус\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 3)
					{
						cout << "correct answer is answer 3" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 3" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 3)
					{
						cout << "correct answer is answer 3" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 3" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 6\n\n";
					cout << "\t" << "Как называется парламент в Ирландии?\n\n";
					cout << "[1] Дайль\t" << "[2] Гэл\t" << endl;
					cout << "[3] Дойл\t" << "[4] Ленстер Хаус\t" << endl << endl;
					cout << "answer 3 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 6\n\n";
					cout << "\t" << "Как называется парламент в Ирландии?\n\n";
					cout << "[3] Дойл\t" << "[4] Ленстер Хаус\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 3)
					{
						cout << "correct answer is answer 3" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 3" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "Question 6\n\n";
					cout << "\t" << "Как называется парламент в Ирландии?\n\n";
					cout << "[3] Дойл\t" << "[4] Ленстер Хаус\t" << endl << endl;
					cout << "answer 3 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
	case 7:
		cout << "\t" << "Question 7\n\n";
		cout << "\t" << "Кто написал 'Так говорил Заратустра'\n";
		cout << "[1] Фридрих Ницше\t" << "[2] Карл Маркс\t" << endl;
		cout << "[3] Иммануил Кант\t" << "[4] Артур Шопенгауэр\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 1)
		{
			cout << "correct answer is answer 1" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 1)
				{
					cout << "correct answer is answer 1" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 1" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 7\n\n";
					cout << "\t" << "Кто написал 'Так говорил Заратустра'\n";
					cout << "[1] Фридрих Ницше\t" << endl;
					cout << "[3] Иммануил Кант\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 1)
					{
						cout << "correct answer is answer 1" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 1" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 1)
					{
						cout << "correct answer is answer 1" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 1" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 7\n\n";
					cout << "\t" << "Кто написал 'Так говорил Заратустра'\n";
					cout << "[1] Фридрих Ницше\t" << endl;
					cout << "[3] Иммануил Кант\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 7\n\n";
					cout << "\t" << "Кто написал 'Так говорил Заратустра'\n";
					cout << "[1] Фридрих Ницше\t" << endl;
					cout << "[3] Иммануил Кант\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 1)
					{
						cout << "correct answer is answer 1" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 1" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "Question 7\n\n";
					cout << "\t" << "Кто написал 'Так говорил Заратустра'\n";
					cout << "[1] Фридрих Ницше\t" << "[2] Карл Маркс\t" << endl;
					cout << "[3] Иммануил Кант\t" << "[4] Артур Шопенгауэр\t" << endl << endl;
					cout << "answer 1 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
	case 8:
		cout << "\t" << "Question 8\n\n";
		cout << "\t" << "Начало 2-ой мировой войны\n";
		cout << "[1] 1941\t" << "[2] 1939\t" << endl;
		cout << "[3] 1933\t" << "[4] 1940\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 2)
		{
			cout << "correct answer is answer 1" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		else if(answer != 2 || answer != 5)
		{
			cout << "You wrong" << "\n\n";
			cout << "correct answer is answer 2" << "\n\n";
			system("pause");
			trysAmount -= 1;
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 2)
				{
					cout << "correct answer is answer 2" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 2" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 2)
						{
							cout << "correct answer is answer 2" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 2" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 8\n\n";
					cout << "\t" << "Начало 2-ой мировой войны\n";
					cout << "        \t" << "[2] 1939\t" << endl;
					cout << "[3] 1933\t" << "        \t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 2)
					{
						cout << "correct answer is answer 2" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 2" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 2)
						{
							cout << "correct answer is answer 2" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 2" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 2)
					{
						cout << "correct answer is answer 2" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 2" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 8\n\n";
					cout << "\t" << "Начало 2-ой мировой войны\n";
					cout << "[1] 1941\t" << "[2] 1939\t" << endl;
					cout << "answer 2 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 2)
						{
							cout << "correct answer is answer 2" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 2" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 8\n\n";
					cout << "\t" << "Начало 2-ой мировой войны\n";
					cout << "         t" << "[2] 1939\t" << endl;
					cout << "[3] 1933\t" << "        \t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 2)
						{
							cout << "correct answer is answer 2" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 2" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 2)
					{
						cout << "correct answer is answer 2" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 2" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "placeholder\n\n";
					cout << "answer 2 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
	case 9:
		cout << "\t" << "Question 9\n\n";
		cout << "\t" << "Писатель-пацифист 30-ых и 40-ых годов\n\n";
		cout << "[1] Эрнст Юнгер\t" << "[2] Лавкрафт\t" << endl;
		cout << "[3] Джон Мур\t" << "[4] Эрих Ремарк\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 4)
		{
			cout << "correct answer is answer 4" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 4)
				{
					cout << "correct answer is answer 4" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 4" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 4)
						{
							cout << "correct answer is answer 4" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 4" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 9\n\n";
					cout << "\t" << "Писатель-пацифист 30-ых и 40-ых годов\n\n";
					cout << "[2] Лавкрафт\t" << endl;
					cout << "[4] Эрих Ремарк\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 4)
					{
						cout << "correct answer is answer 4" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 4" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 4)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 4)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 4" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 4)
					{
						cout << "correct answer is answer 4" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 4" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 9\n\n";
					cout << "\t" << "Писатель-пацифист 30-ых и 40-ых годов\n\n";
					cout << "[3] Джон Мур\t" << "[4] Эрих Ремарк\t" << endl << endl;
					cout << "answer 4 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 4)
						{
							cout << "correct answer is answer 4" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 4" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 9\n\n";
					cout << "\t" << "Писатель-пацифист 30-ых и 40-ых годов\n\n";
					cout << "[2] Лавкрафт\t" << endl;
					cout << "[4] Эрих Ремарк\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 4)
						{
							cout << "correct answer is answer 4" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 4" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 4)
					{
						cout << "correct answer is answer 4" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 4" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "Question 9\n\n";
					cout << "\t" << "Писатель-пацифист 30-ых и 40-ых годов\n\n";
					cout << "[1] Эрнст Юнгер\t" << "[2] Лавкрафт\t" << endl;
					cout << "[3] Джон Мур\t" << "[4] Эрих Ремарк\t" << endl << endl;
					cout << "answer 4 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
		case 10:
			cout << "\t" << "Question 10\n\n";
			cout << "\t" << "Когда изобрели телевиденье\n\n";
			cout << "[1] 1930\t" << "[2] 1940\t" << endl;
			cout << "[3] 1935\t" << "[4] 1952\t" << endl << endl;
			cout << "you have " << trysAmount << " trys" << endl << endl;
			cout << "Insert your answer. If you want to use your hint insert 5." << endl;
			cin >> answer;
			//Защита от дебила
			while (answer < 1 || answer > 5)
			{
				cout << "\nWrong button.\nTry again : ";
				cin >> answer;
			}//Правильный ответ
			if (answer == 1)
			{
				cout << "correct answer is answer 1" << "\n\n";
				correctAnswerPoints += 1;
				system("pause");
			}
			//подсказки
			else if (answer == 5)
			{
				//Нема подсказок
				if (firstHint == 0 && secondHint == 0)
				{
					cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 1)
					{
						cout << "correct answer is answer 1" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 1" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//Если есть только 50 на 50
				else if (firstHint == 1 && secondHint == 0)
				{
					cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
					cin >> quizHintChoise;
					if (quizHintChoise == 0)
					{
						//Ввод ответа вместо исп. подсказки
						cout << "Go and Insert your answer." << "\n\n";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
							while (answer < 1 || answer > 5)
							{
								cout << "\nWrong button.\nTry again : ";
								cin >> answer;
							}
							if (answer == 1)
							{
								cout << "correct answer is answer 1" << "\n\n";
								correctAnswerPoints += 1;
								system("pause");
							}
							else
							{
								cout << "You wrong" << "\n\n";
								cout << "correct answer is answer 1" << "\n\n";
								system("pause");
								trysAmount -= 1;
							}
						}
					}
					//Работа 50 на 50
					else if (quizHintChoise == 1)
					{
						cout << "\t" << "Question 10\n\n";
						cout << "\t" << "Когда изобрели телевиденье\n\n";
						cout << "[1] 1930\t" << "        \t" << endl;
						cout << "[3] 1935\t" << "        \t" << endl << endl;
						cout << "you have " << trysAmount << " trys" << endl << endl;
						cout << "Insert your answer. You dont have any hints now." << endl;
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
						firstHint -= 1;
						while (answer < 1 || answer > 3)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
							while (answer < 1 || answer > 5)
							{
								cout << "\nWrong button.\nTry again : ";
								cin >> answer;
							}
							if (answer == 1)
							{
								cout << "correct answer is answer 1" << "\n\n";
								correctAnswerPoints += 1;
								system("pause");
							}
							else
							{
								cout << "You wrong" << "\n\n";
								cout << "correct answer is answer 1" << "\n\n";
								system("pause");
								trysAmount -= 1;
							}
						}
					}
					//Не то число у того варианта
					else
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> quizHintChoise;
					}
				}
				//Только правильный ответ.
				else if (firstHint == 0 && secondHint == 1)
				{
					cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
					cin >> quizHintChoise;
					if (quizHintChoise == 0)
					{
						//Ввод ответа вместо исп. подсказки
						cout << "Go and Insert your answer." << "\n\n";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					//работа подсказки с верным ответом
					else if (quizHintChoise == 1)
					{
						cout << "\t" << "Question 10\n\n";
						cout << "\t" << "Когда изобрели телевиденье\n\n";
						cout << "[1] 1930\t" << "        \t" << endl;
						cout << "[3] 1935\t" << "        \t" << endl << endl;
						correctAnswerPoints += 1;
						cout << "you have " << trysAmount << " trys" << endl << endl;
						secondHint -= 1;
						system("pause");
						answer = 1;
					}
				}
				//Все подсказки в наличии
				else if (firstHint == 1 && secondHint == 1)
				{
					cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
					cin >> quizHintChoise;
					if (quizHintChoise == 0)
					{
						//Ввод ответа вместо исп. подсказки
						cout << "Go and Insert your answer." << "\n\n";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
							if (answer == 1)
							{
								cout << "correct answer is answer 1" << "\n\n";
								correctAnswerPoints += 1;
								system("pause");
							}
							else
							{
								cout << "You wrong" << "\n\n";
								cout << "correct answer is answer 1" << "\n\n";
								system("pause");
								trysAmount -= 1;
							}
						}
					} //использование 50/50
					else if (quizHintChoise == 1)
					{
						cout << "\t" << "Question 10\n\n";
						cout << "\t" << "Когда изобрели телевиденье\n\n";
						cout << "[1] 1930\t" << "        \t" << endl;
						cout << "[3] 1935\t" << "        \t" << endl << endl;
						cout << "you have " << trysAmount << " trys" << endl << endl;
						cout << "Insert your answer. You dont have any hints now." << endl;
						cin >> answer;
						firstHint -= 1;
						while (answer < 1 || answer > 3)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
							if (answer == 1)
							{
								cout << "correct answer is answer 1" << "\n\n";
								correctAnswerPoints += 1;
								system("pause");
							}
							else
							{
								cout << "You wrong" << "\n\n";
								cout << "correct answer is answer 1" << "\n\n";
								system("pause");
								trysAmount -= 1;
							}
						}
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}//использование 1 правильного ответа
					else if (quizHintChoise == 2)
					{
						cout << "\t" << "Question 10\n\n";
						cout << "\t" << "Когда изобрели телевиденье\n\n";
						cout << "[1] 1930\t" << endl;
						correctAnswerPoints += 1;
						cout << "you have " << trysAmount << " trys" << endl << endl;
						secondHint -= 1;
						system("pause");
						answer = 1;
					}
					else
					{
						trysAmount -= 1;
					}
					break;
				}
			}
			else
			{
				trysAmount -= 1;
			}
			break;
	case 11:
		cout << "\t" << "Question 11\n\n";
		cout << "\t" << "национальное животное Шотландии\n";
		cout << "[1] лошадь\t" << "[2] орёл\t" << endl;
		cout << "[3] единорог\t" << "[4] кит\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 3)
		{
			cout << "correct answer is answer 1" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 3)
				{
					cout << "correct answer is answer 3" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 3" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 11\n\n";
					cout << "\t" << "национальное животное Шотландии\n";
					cout << "[1]         \t" << "[2] орёл\t" << endl;
					cout << "[3] единорог\t" << "        \t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 3)
					{
						cout << "correct answer is answer 3" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 3" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 3)
					{
						cout << "correct answer is answer 3" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 3" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 11\n\n";
					cout << "\t" << "национальное животное Шотландии\n";
					cout << "[3] единорог\t" << "[4] кит\t" << endl << endl;
					cout << "answer 3 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 11\n\n";
					cout << "\t" << "национальное животное Шотландии\n";
					cout << "            \t" << "[2] орёл\t" << endl;
					cout << "[3] единорог\t" << "        \t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 3)
					{
						cout << "correct answer is answer 3" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 3" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "Question 11\n\n";
					cout << "\t" << "национальное животное Шотландии\n";
					cout << "[3] единорог\t" << "[4] кит\t" << endl << endl;
					cout << "answer 3 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
	case 12:
		cout << "\t" << "Question 12\n\n";
		cout << "\t" << "Что означает термин “пиано”?\n\n";
		cout << "[1] В бодром темпе\t" << "[2] В быстром темпе\t" << endl;
		cout << "[3] В умеренно медленном темпе\t" << "[4] В мягком темпе\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 4)
		{
			cout << "correct answer is answer 4" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 4)
				{
					cout << "correct answer is answer 4" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 4" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 4)
						{
							cout << "correct answer is answer 4" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 4" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 12\n\n";
					cout << "\t" << "Что означает термин “пиано”?\n\n";
					cout << "[1] В бодром темпе\t" << "                   \t" << endl;
					cout << "[3]                \t" << "[4] В мягком темпе\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 4)
					{
						cout << "correct answer is answer 4" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 4" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 4)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 4)
						{
							cout << "correct answer is answer 4" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 4" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 4)
					{
						cout << "correct answer is answer 4" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 4" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "placeholder\n\n";
					cout << "answer 4 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 4)
						{
							cout << "correct answer is answer 4" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 4" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 12\n\n";
					cout << "\t" << "Что означает термин “пиано”?\n\n";
					cout << "[1] В бодром темпе\t" << "                   \t" << endl;
					cout << "[3]                \t" << "[4] В мягком темпе\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 4)
						{
							cout << "correct answer is answer 4" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 4" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 4)
					{
						cout << "correct answer is answer 4" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 4" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "Question 12\n\n";
					cout << "\t" << "Что означает термин “пиано”?\n\n";
					cout << "[3]                \t" << "[4] В мягком темпе\t" << endl << endl;
					cout << "answer 4 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
	case 13:
		cout << "\t" << "Question 13\n\n";
		cout << "\t" << "Как называется маленький пластмассовый кусочек на конце шнурка?\n";
		cout << "[1] Аглет\t" << "[2] Чехол\t" << endl;
		cout << "[3] Строка\t" << "[4] наболдажник\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 1)
		{
			cout << "correct answer is answer 1" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 1)
				{
					cout << "correct answer is answer 1" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 1" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 13\n\n";
					cout << "\t" << "Как называется маленький пластмассовый кусочек на конце шнурка?\n";
					cout << "[1] Аглет\t" << "[2] Чехол\t" << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 1)
					{
						cout << "correct answer is answer 1" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 1" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 1)
					{
						cout << "correct answer is answer 1" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 1" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 13\n\n";
					cout << "\t" << "Как называется маленький пластмассовый кусочек на конце шнурка?\n";
					cout << "[1] Аглет\t" << "[2] Чехол\t" << endl;
					cout << "[3] Строка\t" << "[4] наболдажник\t" << endl << endl;
					cout << "answer 1 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 13\n\n";
					cout << "\t" << "Как называется маленький пластмассовый кусочек на конце шнурка?\n";
					cout << "[1] Аглет\t" << "[2] Чехол\t" << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 1)
					{
						cout << "correct answer is answer 1" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 1" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "Question 13\n\n";
					cout << "\t" << "Как называется маленький пластмассовый кусочек на конце шнурка?\n";
					cout << "[1] Аглет\t" << "[2] Чехол\t" << endl;
					cout << "[3] Строка\t" << "[4] наболдажник\t" << endl << endl;
					cout << "answer 1 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
	case 14:
		cout << "\t" << "Question 14\n\n";
		cout << "\t" << " Какая игрушка была первой, которую рекламировали по телевидению?\n";
		cout << "[1] Барби\t" << "[2] Ракетный Гонщик\t" << endl;
		cout << "[3] Мистер Картофельная Голова\t" << "[4] Матрёшка\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 3)
		{
			cout << "correct answer is answer 3" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				while (answer < 1 || answer > 5)
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> answer;
				}
				if (answer == 3)
				{
					cout << "correct answer is answer 3" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{
					cout << "You wrong" << "\n\n";
					cout << "correct answer is answer 3" << "\n\n";
					system("pause");
					trysAmount -= 1;
				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 14\n\n";
					cout << "\t" << " Какая игрушка была первой, которую рекламировали по телевидению?\n";
					cout << "[1] Барби\t" << endl;
					cout << "[3] Мистер Картофельная Голова\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 3)
					{
						cout << "correct answer is answer 3" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 3" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						while (answer < 1 || answer > 5)
						{
							cout << "\nWrong button.\nTry again : ";
							cin >> answer;
						}
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 3)
					{
						cout << "correct answer is answer 3" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 3" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 14\n\n";
					cout << "\t" << " Какая игрушка была первой, которую рекламировали по телевидению?\n";
					cout << "[1] Барби\t" << "[2] Ракетный Гонщик\t" << endl;
					cout << "[3] Мистер Картофельная Голова\t" << "[4] Матрёшка\t" << endl << endl;
					cout << "answer 3 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 14\n\n";
					cout << "\t" << " Какая игрушка была первой, которую рекламировали по телевидению?\n";
					cout << "[1] Барби\t" << endl;
					cout << "[3] Мистер Картофельная Голова\t" << endl << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 3)
						{
							cout << "correct answer is answer 3" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 3" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 3)
					{
						cout << "correct answer is answer 3" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 3" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "Question 14\n\n";
					cout << "\t" << " Какая игрушка была первой, которую рекламировали по телевидению?\n";
					cout << "[3] Мистер Картофельная Голова\t" << endl << endl;
					cout << "answer 3 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
	case 15:
		cout << "\t" << "Question 15\n\n";
		cout << "\t" << "В какой стране находится Прага?\n";
		cout << "[1] Чехия\t" << "[2] Словакия\t" << endl;
		cout << "[3] Польша\t" << "[4] Словения\t" << endl << endl;
		cout << "you have " << trysAmount << " trys" << endl << endl;
		cout << "Insert your answer. If you want to use your hint insert 5." << endl;
		cin >> answer;
		//Защита от дебила
		while (answer < 1 || answer > 5)
		{
			cout << "\nWrong button.\nTry again : ";
			cin >> answer;
		}//Правильный ответ
		if (answer == 1)
		{
			cout << "correct answer is answer 1" << "\n\n";
			correctAnswerPoints += 1;
			system("pause");
		}
		//подсказки
		else if (answer == 5)
		{
			//Нема подсказок
			if (firstHint == 0 && secondHint == 0)
			{
				cout << "\nRight now you have no tips. Go and Insert your answer." << "\n\n";
				cin >> answer;
				if (answer == 1)
				{
					cout << "correct answer is answer 1" << "\n\n";
					correctAnswerPoints += 1;
					system("pause");
				}
				else
				{

				}
			}
			//Если есть только 50 на 50
			else if (firstHint == 1 && secondHint == 0)
			{
				cout << "\nRight now you have 50/50 stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
				}
				//Работа 50 на 50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 15\n\n";
					cout << "\t" << "В какой стране находится Прага?\n";
					cout << "[1] Чехия\t" << "[2] Словакия\t" << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
				}
				//Не то число у того варианта
				else
				{
					cout << "\nWrong button.\nTry again : ";
					cin >> quizHintChoise;
				}
			}
			//Только правильный ответ.
			else if (firstHint == 0 && secondHint == 1)
			{
				cout << "\nRight now you have 1 correct answer stuff. If you wnat to use it press 1. If not press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
					}
					if (answer == 1)
					{
						cout << "correct answer is answer 1" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 1" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}
				//работа подсказки с верным ответом
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 15\n\n";
					cout << "\t" << "В какой стране находится Прага?\n";
					cout << "[1] Чехия\t" << "[2] Словакия\t" << endl;
					cout << "answer 1 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
			}
			//Все подсказки в наличии
			else if (firstHint == 1 && secondHint == 1)
			{
				cout << "\nRight now you have 2 hints. If you wnat to use 50/50 stuff press 1.\nIf you wnat to use correct answer press 2. If you dont want to use hints, press 0." << "\n\n";
				cin >> quizHintChoise;
				if (quizHintChoise == 0)
				{
					//Ввод ответа вместо исп. подсказки
					cout << "Go and Insert your answer." << "\n\n";
					cin >> answer;
					while (answer < 1 || answer > 5)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
				} //использование 50/50
				else if (quizHintChoise == 1)
				{
					cout << "\t" << "Question 15\n\n";
					cout << "\t" << "В какой стране находится Прага?\n";
					cout << "[1] Чехия\t" << "[2] Словакия\t" << endl;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					cout << "Insert your answer. You dont have any hints now." << endl;
					cin >> answer;
					firstHint -= 1;
					while (answer < 1 || answer > 3)
					{
						cout << "\nWrong button.\nTry again : ";
						cin >> answer;
						if (answer == 1)
						{
							cout << "correct answer is answer 1" << "\n\n";
							correctAnswerPoints += 1;
							system("pause");
						}
						else
						{
							cout << "You wrong" << "\n\n";
							cout << "correct answer is answer 1" << "\n\n";
							system("pause");
							trysAmount -= 1;
						}
					}
					if (answer == 1)
					{
						cout << "correct answer is answer 1" << "\n\n";
						correctAnswerPoints += 1;
						system("pause");
					}
					else
					{
						cout << "You wrong" << "\n\n";
						cout << "correct answer is answer 1" << "\n\n";
						system("pause");
						trysAmount -= 1;
					}
				}//использование 1 правильного ответа
				else if (quizHintChoise == 2)
				{
					cout << "\t" << "Question 15\n\n";
					cout << "\t" << "В какой стране находится Прага?\n";
					cout << "[1] Чехия\t" << "[2] Словакия\t" << endl;
					cout << "answer 1 is correct\t" << endl << endl;
					correctAnswerPoints += 1;
					cout << "you have " << trysAmount << " trys" << endl << endl;
					secondHint -= 1;
					system("pause");
					answer = 1;
				}
				else
				{
					trysAmount -= 1;
				}
				break;
			}
		}
		else
		{
			trysAmount -= 1;
		}
		break;
	}
}
//проверка на попытки
void trysCheck()
{
	if (trysAmount == 0)
	{
		clearAll();
		cout << "you lost" << "\n\n";
		cout << "Corect answers count " << correctAnswerPoints << "\n\n";
		system("pause");
	}
	else
	{
		clearAll();
		getQuestion();
		defQuestion();
	}
}
int main()
{
	setlocale(0, "");
	clearAll();
	mainMenu();
	switch (menuChoise)
	{
	case 1:
		while (amountOfQuestions > 0)
		{
			if (trysAmount != 0)
			{
				clearAll();
				getQuestion();
				//questionCheck();
				defQuestion();
				trysCheck(); 
				amountOfQuestions = amountOfQuestions - 2;
			}
		}
		clearAll();
		main();
	case 2:
		settingsMenu();
		clearAll();
		main();
	case 3:
		clearAll();
		Instructions();
		clearAll();
		main();
	case 4:
		cout << "0";
	}
}