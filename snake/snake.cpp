#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
char wall = '#', empt = '.';
const int horizontal = 50, vertical = 25;
char pole[vertical][horizontal];
int xsnake = horizontal / 2, ysnake = vertical / 2;
char snake = '@';
char direction;
int step;

void fill(char arr[][50], int horizontale, int vertical) {

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

void positionSnakestart(char arr[][50], int xsnake, int ysnake, char snake) {
        
    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontal; j++) {
            if (i == ysnake && j == xsnake) {
                arr[i][j] = snake;
            }
        }
    }

}

void positionSnake(char arr[][50], int xsnake, int ysnake, char snake) {
    
    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontal; j++) {
            if (i == ::ysnake && j == ::xsnake) {
                arr[i][j] = empt;
            }
        }
    }
    switch(direction) {
    case 'U':
    case'u': ::ysnake -= step;
        break;
    case 'D':
    case 'd': ::ysnake += step;
        break;
    case'L':
    case 'l': ::xsnake -= step;
        break;
    case 'R':
    case 'r': ::xsnake += step;
        break;
    }

    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontal; j++) {
            if (i == ::ysnake && j == ::xsnake) {
                arr[i][j] = snake;
            }
        }
    }

}

void print(char arr[][50], int horizontale, int vertical) {
    positionSnake(pole, xsnake, ysnake, snake);
    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontale; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}


int main()
{
    setlocale(LC_ALL, "ru");   
   
    int n = 1, score = 0;
    
    fill(pole, horizontal, vertical);
    print(pole, horizontal, vertical);
    positionSnakestart(pole, xsnake, ysnake, snake);
    while (n != 0) {        
        system("cls");        
        print(pole, horizontal, vertical);
        cout << "Ваш счет: " << score << endl;
        //Sleep(1000);        
        cout << "Выберите направление змейки (U - вверх, D- вниз, R - вправо, L - влево):";
        cin >> direction;
        cout << "На сколько переместится: ";
        cin >> step;
        //system("PAUSE >> VOID");
        
    }
    
    return 0;
}