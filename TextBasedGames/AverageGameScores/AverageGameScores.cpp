// AverageGameScores.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	float scores[3];

	cout << "Please enter 3 consecutive game scores: " << endl;

	cin >> scores[0];
	cin >> scores[1];
	cin >> scores[2];

	float average = (scores[0] + scores[1] + scores[2]) / 3;
	cout << "The average of these scores is: " << average << endl;

	system("pause");

	return 0;
}

