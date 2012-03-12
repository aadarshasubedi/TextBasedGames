// GuessMyNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
    srand(static_cast<unsigned int>(time(0)));

    const int maxNumber = 100;
    int secretNumber = (rand() % maxNumber) + 1;
    
    int tries = 0;
    int maxTries = 5;
    int guess;

    bool guessedCorrect = false;

    cout << endl << "Welcome to Guess My Number" << endl << endl;
    cout << "Guess my secret number between 1 and " << maxNumber << "." << endl;
    cout << "You have " << maxTries << " tries." << endl;

    for (int i = tries; i < maxTries; i++) {
        cout << "Enter a guess: ";
        cin >> guess;

        if (guess > secretNumber)
            cout << "Too high!" << endl << endl;
        if (guess < secretNumber)
            cout << "Too low!" << endl << endl;
        if (guess == secretNumber) {
            guessedCorrect = true;
            break;
        }
    }

    if (guessedCorrect)
        cout << "You guessed correct!" << endl;
    else 
        cout << "You are out of tries." << endl;

    cout << "The number was " << secretNumber << "." << endl << endl;

    system("pause");

    return 0;
}

