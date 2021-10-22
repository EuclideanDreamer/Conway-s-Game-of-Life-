#pragma once
#include <time.h>
#include <iostream>
//as ever for your convience 
using namespace std;
//the sides of the board
constexpr auto Xvalue = 50;
constexpr auto Yvalue = 150;

//functions 
void allFalse();
void show();
void set();
void wait();
void play();
void clearScreen();

//time to make a universe of T/F spaces
bool Universe[Xvalue][Yvalue];

//function definitions
//set all spaces to false to begin
void allFalse() {
    for (int i = 0; i < Xvalue; i++) {
        for (int j = 0; j < Yvalue; j++) {
            Universe[i][j] = false;
        }
    }
}

//clear the screen 
void clearScreen() {
    system("cls");
}
//show board
void show() {
    for (int i = 0; i < Xvalue; i++)
    {
        for (int j = 0; j < Yvalue; j++) {
            if (Universe[i][j]) {
                cout << "+";
            }
            else {
                cout << "-";
            }
        }
        cout << endl;
    }
}

//set some spaces alive to start the game
void set() {
    for (int i = 0; i < Xvalue; i++) {
        Universe[i][35] = true;
        Universe[i][36] = true;
    }
}

//time delay to stop CPU frying and to not induce seazure in user
void wait() {
    clock_t time = clock();
    clock_t limit = 1;
    clock_t elapsed = clock() - time;
    while (elapsed != limit) {
        elapsed = clock() - time; //just wait a couple milliseconds
    }
}

//okay here is the big boy this is conways game of life
void play() {
    for (int i = 0; i < Xvalue; i++) {
        for (int j = 0; j < Yvalue; j++) {
            //for each square
            // 1 2 3
            // 4 S 5
            // 6 7 8
            //search each space starting at 1, count the true and act accordingly
            int c = 0;
            //space 1
            if (Universe[i - 1][j + 1]) {
                c++;
            }
            //space 2
            if (Universe[i][j + 1]) {
                c++;
            }
            //space 3
            if (Universe[i + 1][j + 1]) {
                c++;
            }
            //space 4
            if (Universe[i - 1][j]) {
                c++;
            }
            //space 5
            if (Universe[i + 1][j]) {
                c++;
            }
            //space 6
            if (Universe[i - 1][j - 1]) {
                c++;
            }
            //space 7
            if (Universe[i][j - 1]) {
                c++;
            }
            //space 8
            if (Universe[i + 1][j - 1]) {
                c++;
            }

            //Any live cell with fewer than 2 live neighbors dies
            if (c < 2) {
                Universe[i][j] = false;
            }

            //Any live cell with two or three neighbors lives on
            if ((Universe[i][j]) && ((c == 2) || (c == 3))) {
                //nothing to do
            }

            //Any live cell with more than three neighbors dies
            if ((Universe[i][j]) && (c > 3)) {
                Universe[i][j] = false;
            }

            //Any dead cell with 3 live neighbors comes alive
            if ((!Universe[i][j]) && c == 3) {
                Universe[i][j] = true;
            }
        }
    }
}

