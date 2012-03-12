#include "Board.h"

const int Board::WINNING_COMBOS[Board::NUM_COMBOS][Board::NUM_IN_COMBO] =  {   
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 8} 
};

Board::Board(void)
{
    Reset();
}

Board::~Board(void) { }

bool Board::IsFull () const {
    bool full = true;
    int i = 0;

    while (full && i < NUM_SQUARES) {
        if (m_squares[i] == EMPTY)
            full = false;

        ++i;
    }

    return full;
}

bool Board::IsLegalMove (int move) const {
    return (move >= 0 && move < NUM_SQUARES && m_squares[move] == EMPTY);
}

bool Board::IsWinner (char piece) const {
    bool winner = false;
    int i = 0;

    while (!winner && i < NUM_COMBOS) {
        int piecesInCombo = 0;

        for (int j = 0; j < NUM_IN_COMBO; ++j) {
            if (m_squares[WINNING_COMBOS[i][j]] == piece)
                ++piecesInCombo;
        }

        if (piecesInCombo == NUM_IN_COMBO)
            winner = true;

        ++i;
    }

    return winner;
}

void Board::Display () const {
    cout << endl << "\t" << m_squares[0] << " | " << m_squares[1] << " | " << m_squares[2];
    cout << endl << "\t" << "---------";
    cout << endl << "\t" << m_squares[3] << " | " << m_squares[4] << " | " << m_squares[5];
    cout << endl << "\t" << "---------";
    cout << endl << "\t" << m_squares[6] << " | " << m_squares[7] << " | " << m_squares[8];
    cout << endl << endl;
}

void Board::Reset () {
    for (int i = 0; i < NUM_SQUARES; ++i) {
        m_squares[i] = EMPTY;
    }
}

void Board::ReceiveMove (char piece, int move) {
    m_squares[move] = piece;
}