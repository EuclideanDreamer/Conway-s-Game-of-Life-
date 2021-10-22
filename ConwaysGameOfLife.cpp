// ConwaysGameOfLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "universe.h"
int main()
{
    int gens;
    cout << "Welcome how many generations of life would you like to simulate: ";
    cin >> gens;
    //init and set to zero
    allFalse();
    set();

    //play the game
    play();
    //show the board
    show();
    //wait a second
    wait();

    //now clear the board
    clearScreen();
    //now loop that 
    for (int i = 0; i < gens; i++) {
        play();
        show();
        wait();
        clearScreen();
    }
    show();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
