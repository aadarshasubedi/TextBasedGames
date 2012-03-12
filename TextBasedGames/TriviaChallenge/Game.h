#ifndef GAME_H
#define GAME_H 1

#include <istream>
#include <iostream>
#include <iomanip>
#include "Episode.h"

using namespace std;

class Game
{
public:
    Game ();
    void DisplayInstructions () const;          // displays game instructions
    int GetMenuResponse (int numChoices);       // receives input from the player
    double AskQuestion (Question& question);    // asks and scores the question
    void SendScore (ostream& os);               // sends score to stream
    void Play ();                               // plays a game

private:
    Episode m_episode;                          // episode for this game
    int m_score;                                // current score
};

#endif