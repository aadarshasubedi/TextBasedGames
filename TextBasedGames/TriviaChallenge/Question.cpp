#include "Question.h"

const string Question::CORRECT = "Correct!";
const string Question::WRONG = "Wrong!";

Question::Question (istream& episodeFile) {
    // read in the 8 lines that form a question
    getline(episodeFile, m_category);
    getline(episodeFile, m_question);

    for (int i = 0; i < NUM_ANSWERS; i++) {
        getline(episodeFile, m_answers[i]);
    }

    episodeFile >> m_correctAnswer;
    episodeFile.ignore();
    getline(episodeFile, m_explanation);

    for (size_t i = 0; i < m_question.length(); ++i) {
        if (m_question[i] == '/')
            m_question[i] == '\n';
    }

    for (size_t i = 0; i < m_explanation.length(); ++i) {
        if (m_explanation[i] == '/')
            m_explanation[i] == '\n';
    }
}

void Question::Ask () {
    // display question and 4 answers with numbers
    cout << m_category << endl;
    cout << m_question << endl;
    for (int i = 0; i < NUM_ANSWERS; i++) {
        cout << i+1 << ") " << m_answers[i] << endl;
    }
}

int Question::ScoreAnswer (int answer) {
    int score;

    // test if the answer is correct and respond appropriately
    if (answer == m_correctAnswer) {
        cout << CORRECT << endl;
        score = CORRECT_ANSWER_SCORE;
    }
    else {
        cout << WRONG << endl;
        score = 0;
    }

    cout << m_explanation << endl << endl;
    return score;
}