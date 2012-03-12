#include "Critter.h"

int main () {
    srand(static_cast<unsigned int>(time(0)));

    Critter crit;

    int choice;

    do {
        cout << endl << "Critter Caretaker" << endl;
        cout << "-----------------" << endl << endl;
        cout << "0 - Quit" << endl;
        cout << "1 - Listen to your critter" << endl;
        cout << "2 - Feed your critter" << endl;
        cout << "3 - Play with your critter" << endl;
        cout << "4 - Ask your critter to perform a trick." << endl << endl;

        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Good-bye." << endl;
                break;
            case 1:
                crit.Talk();
                break;
            case 2:
                crit.Eat();
                break;
            case 3:
                crit.Play();
                break;
            case 4:
                crit.PerformTrick();
                break;
            default:
                cout << "Sorry, but " << choice << " isn't a valid choice." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}