// GuessMyNumber2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

enum EGuess { none, tooHigh, tooLow, correct };

int _tmain(int argc, _TCHAR* argv[]) {
    srand(static_cast<unsigned int>(time(0)));

    const int maxNumber = 100;

    int maxTries = 5;
    int curTry = 0;
    int guess = 50;
    int lowest = 1;
    int highest = maxNumber;

    bool guessedCorrect = false;

    cout << "Welcome to Guess My Number 2!" << endl;
    cout << "I'll try to guess any number you enter between 1 and 100 in " << maxTries << " tries." << endl << endl;
    cout << "Please think of a number between 1 and 100." << endl << endl;

    system("pause");

    cout << endl << "Thanks.  I'll now try to guess the number." << endl << endl;

    for (int i = curTry; i < maxTries; i++) {
        cout << "Is the number " << guess << "?" << endl << endl;
        cout << "1. \t Too High" << endl;
        cout << "2. \t Too Low" << endl;
        cout << "3. \t Correct!" << endl;

        int answer;
        cin >> answer;
        cout << endl << endl;

        EGuess eval = none;
        eval = (EGuess)answer;

        switch (eval) {
            case tooHigh:
                highest = guess - 1;
                break;
            case tooLow:
                lowest = guess + 1;
                break;
            case correct:
                guessedCorrect = true;
                break;
        }

        if (guessedCorrect == true)
            break;

        guess = (highest - lowest) / 2 + lowest;
    }

    if (guessedCorrect == false)
        cout << "My last ditch guess is " << guess << ", but congratulations you win! I'll get you next time." << endl << endl;
    else
        cout << "Woot, I got it!!" << endl << endl;

    system("pause");

    return 0;
}

