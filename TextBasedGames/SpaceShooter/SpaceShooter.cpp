// SpaceShooter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const unsigned int savedCivilianScore = 100;
	const unsigned int destroyedAlienScore = 50;

	int numOfCivSaved = 7;
	int numOfAlienDest = 24;
	int totalScore = (numOfCivSaved * savedCivilianScore) + (numOfAlienDest * destroyedAlienScore);

	cout << "Congratulations, you saved 7 civilians, earning you " << savedCivilianScore * numOfCivSaved << " points!" << endl;
	cout << "You also destroyed " << numOfAlienDest << " aliens, earning you " << destroyedAlienScore * numOfAlienDest << " points." << endl;
	cout << "Your total score: " << totalScore << endl;

	system("pause");
	
	return 0;
}

