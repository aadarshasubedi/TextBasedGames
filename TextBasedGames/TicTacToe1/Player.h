#pragma once
#include <iostream>

using namespace std;

class Board;

class Player {
public:
    Player ();
    ~Player ();

    char GetPiece () const { return m_piece; };
    void MakeMove (Board& board) const;

private:
    static const int NUM_PIECES = 2;
    static const char PIECES[NUM_PIECES];
    static int current;

    char m_piece;
};