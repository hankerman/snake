#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
char wall = '#', empt = '.', snake = '@', apple = '$';
const int horizontal = 50, vertical = 25;
char pole[vertical][horizontal];
int xsnake = horizontal / 2, ysnake = vertical / 2, xapple = (rand() % horizontal-3) + 2, yapple = (rand() % vertical-3) + 2;
char direction;
int score = 0, n = 1;

void fill(char arr[][horizontal], int horizontale, int vertical) {

    //char wall = '#', empt = ' ';

    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontale; j++) {
            if (i == 0 || i == vertical - 1) {
                arr[i][j] = wall;
            }
            else if (j == 0 || j == horizontale - 1) {
                arr[i][j] = wall;
            }
            else {
                arr[i][j] = empt;
            }
        }
        
    }
}

void positionSnakestart(char arr[][horizontal], int xsnake, int ysnake, char snake) {
        
    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontal; j++) {
            if (i == ysnake && j == xsnake) {
                arr[i][j] = snake;
            }
        }
    }

}

void fruit(char arr[][horizontal]) {

    ::xapple = (rand() % horizontal - 3) + 2;
    ::yapple = (rand() % vertical - 3) + 2;
    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontal; j++) {
            if (i == ::yapple && j == ::xapple) {
                arr[i][j] = apple;
            }
        }
    }
}

char move(char direction) {
    if (_kbhit()) {
        direction = _getch();
        switch (direction) {
        
        case 72: direction = 'u';
            break;
        
        case 80: direction = 'd';
            break;
        
        case 75: direction = 'l';
            break;
        
        case 77: direction = 'r';
            break;
        }
        
    }
    return direction;
}

void positionSnake(char arr[][horizontal], int xsnake, int ysnake, char snake) {
    
    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontal; j++) {
            if (i == ::ysnake && j == ::xsnake) {
                arr[i][j] = empt;
            }
        }
    }
    direction = move(direction);
    switch(direction) {
    case 'U':
    case'u': ::ysnake --;
        break;
    case 'D':
    case 'd': ::ysnake ++;
        break;
    case'L':
    case 'l': ::xsnake --;
        break;
    case 'R':
    case 'r': ::xsnake ++;
        break;
    }

    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontal; j++) {
            if (i == ::ysnake && j == ::xsnake) {
                if (arr[i][j] == empt) {
                    arr[i][j] = snake;
                }
                else if (arr[i][j] == wall){
                    ::n = 0;

                }
                else if (arr[i][j] == apple) {
                    fruit(pole);
                    score += 10;
                }
            }
        }
    }

}

void print(char arr[][horizontal], int horizontale, int vertical) {
    positionSnake(pole, xsnake, ysnake, snake);
    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontale; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    Sleep(250);
}


int main()
{
    setlocale(LC_ALL, "ru");     
    srand(time(NULL));
    fill(pole, horizontal, vertical);    
    print(pole, horizontal, vertical);
    positionSnakestart(pole, xsnake, ysnake, snake);
    fruit(pole);

    while (::n != 0) {        
        system("cls");
        cout << "Ваш счет: " << score << endl;
        print(pole, horizontal, vertical);
        
        //Sleep(250);              
        //system("PAUSE >> VOID");
        if (score == 100) {
            n = 0;
        }
        
    }

    system("cls");

    cout << "Конец игры!!!" << endl;
    cout << "Ваш счет: " << score << endl;
    if (score == 100) {
        cout << "Вы победили!!!";
    }
    system("PAUSE");
    return 0;
}