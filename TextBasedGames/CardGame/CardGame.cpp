// CardGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const int numOfCards = 52;
	int numOfPlayers;

	cout << "Enter the number of players: ";
	cin >> numOfPlayers;

	cout << "The number of cards per player is: " << numOfCards / numOfPlayers << endl;
	cout << "There are " << numOfCards % numOfPlayers << " card(s) left over." << endl;

	system("pause");

	return 0;
}