#pragma once

#include "Board.h"
#include "Player.h"

class Game {
public:
    Game ();
    ~Game ();

    bool IsPlaying () const;
    bool IsTie () const;
    void DisplayInstructions () const;
    void SetNextPlayer ();
    void AnnounceWinner () const;
    void Play ();

private:
    static const int NUM_PLAYERS = 2;
    static const int FIRST = 0;
    static const int SECOND = 1;

    Board m_board;
    Player m_players[NUM_PLAYERS];
    int m_current;
};