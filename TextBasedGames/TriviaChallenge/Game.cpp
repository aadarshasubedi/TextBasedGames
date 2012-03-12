#include "Game.h"

Game::Game () : m_episode("trivia.txt") { }

void Game::DisplayInstructions () const {
    cout << "\t" << "Welcome o Trivia Challenge!" << endl << endl;

    cout << "Correctly answer as many questions as possible." << endl;
    cout << "You earn 1,000 points for each one you get right." << endl << endl;
}

int Game::GetMenuResponse (int numChoices) {
    int response;

    // read the user's choice (must be valid)
    do {
        cout << "Enter your choice: ";
        cin >> response;
    } while (cin.good() && (response < 1 || response > numChoices));

    if (cin.fail()) {
        cout << endl << "Goodbye!" << endl;
        exit(1);
    }
    cout << endl;

    return response;
}

double Game::AskQuestion (Question& question) {
    int response;
    question.Ask();
    response = GetMenuResponse(Question::NUM_ANSWERS);

    return question.ScoreAnswer(response);
}

void Game::SendScore (ostream& os) {
    os << "Your final score is " << m_score << "." << endl;
}

void Game::Play () {
    m_score = 0;
    m_episode.Introduce();

    while (m_episode.IsOn()) {
        Question question = m_episode.NextQuestion();
        m_score += AskQuestion(question);
    }

    SendScore(cout);

    ofstream scoreFile("trivia_scores.txt", ios::out | ios::app);
    SendScore(scoreFile);
    scoreFile.close();
}