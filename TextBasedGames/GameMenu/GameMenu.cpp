// GameMenu.cpp : Defines the entry point for the console application.

#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
	int choice = 0;

	cout << "\t" << "Game Menu" << endl;
	cout << "1. One Player" << endl;
	cout << "2. Two Players" << endl;
	cout << "3. Quit" << endl << endl;

	cout << "Enter Choice:" << endl;

	cin >> choice;
	if (choice <= 0 || choice > 3)
		return 1;

	cout << "You chose menu item: " << choice << endl << endl;

	system("pause");

	return 0;
}