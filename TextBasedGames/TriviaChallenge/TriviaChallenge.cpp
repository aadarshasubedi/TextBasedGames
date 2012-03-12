// TriviaChallenge.cpp : Defines the entry point for the console application.
//

#include "Game.h"

int main(int argc, char* argv[])
{
    Game trivia;

    trivia.DisplayInstructions();
    trivia.Play();

    system("pause");
    return 0;
}

