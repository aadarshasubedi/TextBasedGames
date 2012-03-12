// ScoreRatings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int score = 0;

	cout << "Please enter a score: " << endl;

	cin >> score;

	string rating;

	if (score > 0 && score < 1000)
		rating = "Nothing to brag about";
	else if (score > 1000 && score < 10000)
		rating = "Good score.";
	else if (score > 10000)
		rating = "Very impressive!";
	else
		rating = "That's not a legal score!";

	cout << rating << endl;
	
	system("pause");

	return 0;
}

