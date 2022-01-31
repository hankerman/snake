#include <iostream>
#include <windows.h>
using namespace std;

void fill(char arr[][100], int horizontale, int vertical) {

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

void print(char arr[][100], int horizontale, int vertical) {
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

    const int horizontal = 100, vertical = 25;
    char pole[vertical][horizontal];
    int n = 1;

    fill(pole, horizontal, vertical);
    //print(pole, horizontal, vertical);

    while (n != 0) {
        print(pole, horizontal, vertical);
        Sleep(500);
        system("cls");
    }
    
    return 0;
}