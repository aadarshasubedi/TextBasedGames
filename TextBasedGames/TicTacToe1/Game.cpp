#include "Game.h"


Game::Game () :
    m_current(FIRST)
{
}


Game::~Game () {

}

bool Game::IsPlaying() const {
    return (!m_board.IsFull() && 
        !m_board.IsWinner(m_players[FIRST].GetPiece()) &&
        !m_board.IsWinner(m_players[SECOND].GetPiece()));
}

bool Game::IsTie () const {
    return (m_board.IsFull() &&
        !m_board.IsWinner(m_players[FIRST].GetPiece()) &&
        !m_board.IsWinner(m_players[SECOND].GetPiece()));
}

void Game::DisplayInstructions () const {
    cout << "\tWelcome to the ultimate intellectual";
    cout << "showdown: Tic-Tac-Toe." << endl << endl;

    cout << "Make your move by entering a number, 0 - 8." << endl;
    cout << "The number corresponds with board position, as illustrated: " << endl << endl;

    cout << endl << "\t" << "0 | 1 | 2";
    cout << endl << "\t" << "---------";
    cout << endl << "\t" << "3 | 4 | 5";
    cout << endl << "\t" << "---------";
    cout << endl << "\t" << "6 | 7 | 8";

    cout << endl << endl;
    cout << "Prepare yourself.  The battle is about to begin.";
    cout << endl << endl;
}

void Game::SetNextPlayer () {
    // increment current player number by one
    // "wrap around" to 0, if necessary
    m_current = (m_current + 1) % NUM_PLAYERS;
}

void Game::AnnounceWinner () const {
    cout << "The raging battle has come to a final end." << endl;

    if (IsTie()) {
        cout << "Sadly, no player emerged victorious." << endl;
        return;
    }

    char winner;
    if (m_board.IsWinner(m_players[FIRST].GetPiece()))
        winner = m_players[FIRST].GetPiece();
    else
        winner = m_players[SECOND].GetPiece();

    cout << "The winner of this climatic confrontation is Player: " << winner << "!" << endl;

}

void Game::Play () {
    m_current = FIRST;
    m_board.Reset();

    while (IsPlaying()) {
        m_board.Display();
        m_players[m_current].MakeMove(m_board);
        SetNextPlayer();
    }

    m_board.Display();
    AnnounceWinner();
}