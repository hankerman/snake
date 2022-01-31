#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

const int horizontal = 50, vertical = 25;
char pole[vertical][horizontal];
int xsnake = horizontal / 2, ysnake = vertical / 2;
char snake = '@';

void fill(char arr[][50], int horizontale, int vertical) {

    char wall = '#', empt = ' ';

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

int xpositionSnake(int xsnake) {
    int position = xsnake, key = _getch();
    switch (key) {
    case 72: position++;
        break;
    case 80: position--;
        break;
    }

    return position;
}

int ypositionSnake(int ysnake) {
    int position = ysnake, key = _getch();
    switch (key) {
    case 77: position++;
        break;
    case 75: position--;
        break;
    }

    return position;
}
void positionSnake(char arr[][50], int xsnake, int ysnake, char snake) {
    xpositionSnake(xsnake);
    ypositionSnake(ysnake);
    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontal; j++) {
            if (i == ysnake && j == xsnake) {
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
    //print(pole, horizontal, vertical);

    while (n != 0) {        
        
        
        print(pole, horizontal, vertical);
        cout << "Ваш счет: " << score;
        Sleep(1000);
        system("cls");
    }
    
    return 0;
}