#include "Player.h"
#include "Board.h"

const char Player::PIECES[Player::NUM_PIECES] = {'X', 'O'};
int Player::current = 0;

Player::Player () {
    m_piece = PIECES[current];
    current = (current + 1) % NUM_PIECES;
}

Player::~Player () { }

void Player::MakeMove (Board& board) const {
    int move;

    do {
        cout << "Player " << GetPiece();
        cout << ", where would you like to move? (0-8): ";
        cin >> move;
    } while (!board.IsLegalMove(move));

    board.ReceiveMove(GetPiece(), move);    
}