
#include <iostream>
#include <string>

using namespace std;

#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define GRAY   "\033[37m"      /* Gray */
#define WHITE   "\033[0m"      /* Reset? */
#define RESET   WHITE

enum Colors {
    Reset,
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White,
};

enum MainMenu {
    StartGame,
    GoSettings,
    PrintRules,
    Exit
};
enum SettingsMenu {
    SetColor,
    SetXTurn,
    SetFieldSize,
    ToggleBot,
    SExit,
};
enum FieldSize {
    Three,
    Four,
    Five,
};

struct Settings { //хаюшки
    string color[2] = { RED, BLUE };
    bool xTurn = true;
    int size = 4;
    bool useBot = false;
    char winner = 'W';
};

Settings globalSettings;

/**
 * @Return true для прекращения цикла.
 */
bool checkWin(char** field) {
    switch (globalSettings.size) {
    case 3:
        if ((field[0][0] == field[0][1] && field[0][1] == field[0][2] && field[0][0] == 'X')
            || (field[1][0] == field[1][1] && field[1][1] == field[1][2] && field[1][0] == 'X')
            || (field[2][0] == field[2][1] && field[2][1] == field[2][2] && field[2][0] == 'X')
            || (field[0][0] == field[1][0] && field[1][0] == field[2][0] && field[0][0] == 'X')
            || (field[0][1] == field[1][1] && field[1][1] == field[2][1] && field[0][1] == 'X')
            || (field[0][2] == field[1][2] && field[1][2] == field[2][2] && field[0][2] == 'X')
            || (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'X')
            || (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'X')) {
            globalSettings.winner = 'X';
            return true;
        }
        else if ((field[0][0] == field[0][1] && field[0][1] == field[0][2] && field[0][0] == '0')
            || (field[1][0] == field[1][1] && field[1][1] == field[1][2] && field[1][0] == '0')
            || (field[2][0] == field[2][1] && field[2][1] == field[2][2] && field[2][0] == '0')
            || (field[0][0] == field[1][0] && field[1][0] == field[2][0] && field[0][0] == '0')
            || (field[0][1] == field[1][1] && field[1][1] == field[2][1] && field[0][1] == '0')
            || (field[0][2] == field[1][2] && field[1][2] == field[2][2] && field[0][2] == '0')
            || (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == '0')
            || (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == '0')) {
            globalSettings.winner = '0';
            return true;
        }
        break;
    case 4: //TODO: разобраться в фейквине.
        if ((field[0][0] == field[0][1] && field[0][1] == field[0][2] && field[0][2] == field[0][3] &&
            field[0][0] == 'X')
            || (field[1][0] == field[1][1] && field[1][1] == field[1][2] && field[1][2] == field[1][3] &&
                field[1][0] == 'X')
            || (field[2][0] == field[2][1] && field[2][1] == field[2][2] && field[2][2] == field[2][3] &&
                field[2][0] == 'X')
            || (field[3][0] == field[3][1] && field[3][1] == field[3][2] && field[3][2] == field[3][3] &&
                field[3][0] == 'X')
            || (field[0][0] == field[1][0] && field[1][0] == field[2][0] && field[2][0] == field[3][0] &&
                field[0][0] == 'X')
            || (field[0][1] == field[1][1] && field[1][1] == field[2][1] && field[2][1] == field[3][1] &&
                field[0][1] == 'X')
            || (field[0][2] == field[1][2] && field[1][2] == field[2][2] && field[2][2] == field[3][2] &&
                field[0][2] == 'X')
            || (field[0][3] == field[1][3] && field[1][3] == field[2][3] && field[2][3] == field[3][3] &&
                field[0][0] == 'X')) {
            globalSettings.winner = 'X';
            return true;
        }
        else if ((field[0][0] == field[0][1] && field[0][1] == field[0][2] && field[0][2] == field[0][3] &&
            field[0][0] == '0')
            || (field[1][0] == field[1][1] && field[1][1] == field[1][2] && field[1][2] == field[1][3] &&
                field[1][0] == '0')
            || (field[2][0] == field[2][1] && field[2][1] == field[2][2] && field[2][2] == field[2][3] &&
                field[2][0] == '0')
            || (field[3][0] == field[3][1] && field[3][1] == field[3][2] && field[3][2] == field[3][3] &&
                field[3][0] == '0')
            || (field[0][0] == field[1][0] && field[1][0] == field[2][0] && field[2][0] == field[3][0] &&
                field[0][0] == '0')
            || (field[0][1] == field[1][1] && field[1][1] == field[2][1] && field[2][1] == field[3][1] &&
                field[0][1] == '0')
            || (field[0][2] == field[1][2] && field[1][2] == field[2][2] && field[2][2] == field[3][2] &&
                field[0][2] == '0')
            || (field[0][3] == field[1][3] && field[1][3] == field[2][3] && field[2][3] == field[3][3] &&
                field[0][0] == '0')) {
            globalSettings.winner = '0';
            return true;
        }
        break;
    case 5: //TODO: разобраться в фейквине.
        if ((field[0][0] == field[0][1] && field[0][1] == field[0][2] && field[0][2] == field[0][3] &&
            field[0][3] == field[0][4] && field[0][0] == 'X')
            || (field[1][0] == field[1][1] && field[1][1] == field[1][2] && field[1][2] == field[1][3] &&
                field[1][3] == field[1][4] && field[1][0] == 'X')
            || (field[2][0] == field[2][1] && field[2][1] == field[2][2] && field[2][2] == field[2][3] &&
                field[2][3] == field[2][4] && field[2][0] == 'X')
            || (field[3][0] == field[3][1] && field[3][1] == field[3][2] && field[3][2] == field[3][3] &&
                field[3][3] == field[3][4] && field[3][0] == 'X')
            || (field[4][0] == field[4][1] && field[4][1] == field[4][2] && field[4][2] == field[4][3] &&
                field[4][3] == field[4][4] && field[4][0] == 'X')
            || (field[0][0] == field[1][0] && field[1][0] == field[2][0] && field[2][0] == field[3][0] &&
                field[3][0] == field[4][0] && field[0][0] == 'X')
            || (field[0][1] == field[1][1] && field[1][1] == field[2][1] && field[2][1] == field[3][1] &&
                field[3][1] == field[4][1] && field[0][1] == 'X')
            || (field[0][2] == field[1][2] && field[1][2] == field[2][2] && field[2][2] == field[3][2] &&
                field[3][2] == field[4][2] && field[0][2] == 'X')
            || (field[0][3] == field[1][3] && field[1][3] == field[2][3] && field[2][3] == field[3][3] &&
                field[3][3] == field[4][3] && field[0][3] == 'X')
            || (field[0][4] == field[1][4] && field[1][4] == field[2][4] && field[2][4] == field[3][4] &&
                field[3][4] == field[4][4] && field[0][4] == 'X')
            || (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[2][2] == field[3][3] &&
                field[3][3] == field[4][4] && field[0][0] == 'X')
            || (field[0][4] == field[1][3] && field[1][3] == field[2][2] && field[2][2] == field[3][1] &&
                field[3][1] == field[4][0] && field[0][4] == 'X')) {
            globalSettings.winner = 'X';
            return true;
        }
        else if ((field[0][0] == field[0][1] && field[0][1] == field[0][2] && field[0][2] == field[0][3] &&
            field[0][3] == field[0][4] && field[0][0] == '0')
            || (field[1][0] == field[1][1] && field[1][1] == field[1][2] && field[1][2] == field[1][3] &&
                field[1][3] == field[1][4] && field[1][0] == '0')
            || (field[2][0] == field[2][1] && field[2][1] == field[2][2] && field[2][2] == field[2][3] &&
                field[2][3] == field[2][4] && field[2][0] == '0')
            || (field[3][0] == field[3][1] && field[3][1] == field[3][2] && field[3][2] == field[3][3] &&
                field[3][3] == field[3][4] && field[3][0] == '0')
            || (field[4][0] == field[4][1] && field[4][1] == field[4][2] && field[4][2] == field[4][3] &&
                field[4][3] == field[4][4] && field[4][0] == '0')
            || (field[0][0] == field[1][0] && field[1][0] == field[2][0] && field[2][0] == field[3][0] &&
                field[3][0] == field[4][0] && field[0][0] == '0')
            || (field[0][1] == field[1][1] && field[1][1] == field[2][1] && field[2][1] == field[3][1] &&
                field[3][1] == field[4][1] && field[0][1] == '0')
            || (field[0][2] == field[1][2] && field[1][2] == field[2][2] && field[2][2] == field[3][2] &&
                field[3][2] == field[4][2] && field[0][2] == '0')
            || (field[0][3] == field[1][3] && field[1][3] == field[2][3] && field[2][3] == field[3][3] &&
                field[3][3] == field[4][3] && field[0][3] == '0')
            || (field[0][4] == field[1][4] && field[1][4] == field[2][4] && field[2][4] == field[3][4] &&
                field[3][4] == field[4][4] && field[0][4] == '0')
            || (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[2][2] == field[3][3] &&
                field[3][3] == field[4][4] && field[0][0] == '0')
            || (field[0][4] == field[1][3] && field[1][3] == field[2][2] && field[2][2] == field[3][1] &&
                field[3][1] == field[4][0] && field[0][4] == '0')) {
            globalSettings.winner = '0';
            return true;
        }
        break;
    }
    return false;
}

int* getValidRandomIndex(char** i) {
    while (true) {
        int xRand = rand() % globalSettings.size;
        int yRand = rand() % globalSettings.size;
        if (i[xRand][yRand] == '#')
            return new int[2]{ xRand, yRand };
    }
}

void printAllField(char** field) {
    for (int x = 0; x < globalSettings.size; x++) {
        for (int y = 0; y < globalSettings.size; y++) {
            char i = field[x][y];
            if (i == 'X')
                printf("%s X", globalSettings.color[0].c_str());
            else if (i == '0')
                printf("%s 0", globalSettings.color[1].c_str());
            else
                printf("%s  ", RESET);
        }
        printf("\n");
    }
}

void gameTick(char** field) {
    string xColor = globalSettings.color[0];
    string yColor = globalSettings.color[1];
    int size = globalSettings.size;
    printf("\n\n------------Ход: %s%s------------\n",
        globalSettings.xTurn ? xColor.append("X").c_str() : yColor.append("0").c_str(), RESET);
    printAllField(field);
    printf("Введи индексы(x,y) поля, который хочешь занять:\n->");
    int x, y = -1;
    if (globalSettings.xTurn) {
        cin >> x;
        cin >> y;
    }
    else if (!globalSettings.xTurn && globalSettings.useBot) {
        int* i = getValidRandomIndex(field);
        x = i[0];
        y = i[1];
    }
    else {
        cin >> x;
        cin >> y;
    }
    printf("Выбор: x - %i, y - %i\n", x, y);
    if (x >= size || y >= size || field[x][y] != '#') {
        printf("%sВыбор не прошел проверку. Повтори попытку%s\n", RED, RESET);
        return;
    }
    field[x][y] = globalSettings.xTurn ? 'X' : '0';
    globalSettings.xTurn = !globalSettings.xTurn;
}


void game() {
    //init
    int size = globalSettings.size;

    char crouch[size][size];
    char* field[size];

    for (size_t i = 0; i < size; ++i) {
        field[i] = crouch[i];
    }

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            field[x][y] = '#';
        }
    }
    printf("Игра началась\n");
    do {
        gameTick(field);
    } while (!checkWin(field));
    printAllField(field);
    printf("Победа игрока с символом %c\n\n", globalSettings.winner);
}


void rules() {
    printf("%s\n\n%s\n%s\n%s\n\n%s\n\n%s\n%s\n%s\n\n", "[] для одиночной игры:",
        "[1] Вы вводите координту(x и y) того места куда хотите поставить значёк",
        "[2] Компьютер ставит свой",
        "[3] Всё повторяеться до победы одной из сторон",
        "[] для двух игроков",
        "[1] Игрок 1 вводит координту(x и y) того места куда хочет поставить значёк",
        "[2] Игрок 2 вводит координту(x и y) того места куда хочет поставить значёк",
        "[3] Всё повторяеться до победы одной из сторон");
}

void selectColor() {
    //Выбор для крестика:
    printf("X выбирает цвет:\n"); //Выбор для крестика
    int colorNumber;
    cin >> colorNumber;
    switch (colorNumber) {
    case Reset:
        globalSettings.color[0] = RESET;
        break;

    case Black:
        globalSettings.color[0] = BLACK;
        break;

    case Red:
        globalSettings.color[0] = RED;
        break;

    case Green:
        globalSettings.color[0] = GREEN;
        break;

    case Yellow:
        globalSettings.color[0] = YELLOW;
        break;

    case Blue:
        globalSettings.color[0] = BLUE;
        break;

    case Magenta:
        globalSettings.color[0] = MAGENTA;
        break;

    case Cyan:
        globalSettings.color[0] = CYAN;
        break;

    case White:
    default:
        globalSettings.color[0] = WHITE;
    }

    //выбор для нолика:
    printf("0 выбирает цвет:\n"); //Выбор для нолика
    cin >> colorNumber;
    switch (colorNumber) {
    case Reset:
        globalSettings.color[1] = RESET;
        break;

    case Black:
        globalSettings.color[1] = BLACK;
        break;

    case Red:
        globalSettings.color[1] = RED;
        break;

    case Green:
        globalSettings.color[1] = GREEN;
        break;

    case Yellow:
        globalSettings.color[1] = YELLOW;
        break;

    case Blue:
        globalSettings.color[1] = BLUE;
        break;

    case Magenta:
        globalSettings.color[1] = MAGENTA;
        break;

    case Cyan:
        globalSettings.color[1] = CYAN;
        break;

    case White:
    default:
        globalSettings.color[1] = WHITE;
    }
    printf("Цвета установленны:\n -> %sX %s\n -> %s0\n%s", globalSettings.color[0].c_str(), WHITE,
        globalSettings.color[1].c_str(), WHITE);
}

void setFieldSize() {
    printf("Выберите размер поля: \n"
        "0 - 3*3 (по умолчанию)\n"
        "1 - 4*4\n"
        "2 - 5*5\n");
    int act;
    cin >> act;
    switch (act) {
    case Three:
        globalSettings.size = 3;
        break;
    case Four:
        globalSettings.size = 4;
        break;
    case Five:
        globalSettings.size = 5;
        break;
    default:
        printf("Не знаю такого.");
        break;
    }
}

void settings() {
    while (true) {
        cout << "[0] Цвет крестика и нолика ->" << globalSettings.color[0] << " Test-X " << globalSettings.color[1]
            << "Test-0 " << RESET << endl;
        cout << "[1] Кто первый ходит -> " << globalSettings.xTurn << endl;
        cout << "[2] Размер поля -> " << globalSettings.size << endl;
        cout << "[3] Переключить бота -> " << globalSettings.useBot << endl;
        cout << "[4] Выход в меню\n";
        int act;
        cin >> act;
        switch (act) {
        case SetColor:
            selectColor();
            break;
        case SetXTurn:
            globalSettings.xTurn = !globalSettings.xTurn;
            printf("Первым ходит крестик: %i\n", globalSettings.xTurn);
            break;
        case SetFieldSize:
            setFieldSize();
            break;
        case ToggleBot:
            globalSettings.useBot = !globalSettings.useBot;
            printf("Бот включен: %i", globalSettings.useBot);
        case SExit:
        default:
            return;
        }
    }
}

int menu() {

    while (true) {
        cout << "[0] Начало игры\n";
        cout << "[1] Настройки игры\n";
        cout << "[2] Правила игры\n";
        cout << "[3] Выход из программы\n";
        int act;
        cin >> act;
        switch (act) {
        case StartGame:
            game();
            break;
        case GoSettings:
            settings();
            break;
        case PrintRules:
            rules();
            break;
        case Exit:
        default:
            return 0;
        }
    }

}

int main() {
    struct Settings settings;
    globalSettings = settings;
    menu();
}
