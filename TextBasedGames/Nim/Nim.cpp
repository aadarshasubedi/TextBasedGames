// Nim.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

int PickupSticks (int);
int TakePlayerTurn (bool, int);

int main () {
    const int maxSticks = 13;
    int remainingSticks = maxSticks;
    bool humansTurn = true;
    bool gameOver = false;
    bool humanWon = false;

    cout << "Welcome to Nim" << endl << endl;
    cout << "Nim is a game of sticks." << endl;
    cout << "Each player takes turns picking up 1 to 4 sticks in a pile of 13." << endl;
    cout << "The last player to pick up sticks is the winner." << endl << endl;

    system("pause");

    while (!gameOver) {
        while (remainingSticks > 0) {
            cout << endl << "There are " << remainingSticks << " remaining sticks." << endl << endl;
            
            remainingSticks -= TakePlayerTurn(humansTurn, remainingSticks);
            if (remainingSticks == 0)
                humanWon = humansTurn;

            humansTurn = !humansTurn;
        }

        cout << endl << "There are " << remainingSticks << " remaining sticks." << endl << endl;

        if (humanWon)
            cout << "Congratulations, you won!  You were a tough opponent." << endl;
        else
            cout << "Muwahaha, you'll never beat me!" << endl << endl;

        cout << "Press 1 to play again, or 2 to quit: ";
        int selection;
        cin >> selection;

        if (selection == 2) {
            gameOver = true;
        }
        else {
            humansTurn = !humansTurn;
            remainingSticks = maxSticks;
        }
    }

    system("pause");

    return 0;
}

int TakePlayerTurn (bool humanPlayer, int remainingSticks) {
    int sticksChosen = 0;

    if (humanPlayer) {
        cout << endl << "Please select how many sticks you'd like to pick up (1 to 4)   : ";

        // Player chooses sticks
        do {
            cin >> sticksChosen;

            cout << endl << "You chose " << sticksChosen << " sticks." << endl << endl;

            if (sticksChosen <= 0 || sticksChosen > 4) {
                cout << endl << "Please only enter a number 1 through 4: ";

                sticksChosen = 0;
            }
        } while (sticksChosen <= 0 || sticksChosen > 4);
    }
    else {
        // AI chooses sticks
        sticksChosen = PickupSticks(remainingSticks);
        
        cout << "I chose " << sticksChosen << " sticks." << endl << endl;
    }

    return sticksChosen;
}

int PickupSticks (int remainingSticks) {
    int sticksChosen = 0;
    int idealRemainder = remainingSticks - (remainingSticks - 1) % 4;

    if (idealRemainder == 1)                    // This means we've won, and can take all remaining sticks
        sticksChosen = remainingSticks;
    else if (remainingSticks == idealRemainder) // This means we can take the full 4 sticks, as we'll reach our next ideal remainder
        sticksChosen = 4;
    else
        sticksChosen = remainingSticks - idealRemainder;

    return sticksChosen;
}
