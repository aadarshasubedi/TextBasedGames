#ifndef QUESTION_H
#define QUESTION_H 1

#include <string>
#include <fstream>
#include <istream>
#include <iostream>

using namespace std;

class Question {
public:
    static const int NUM_ANSWERS = 4;               // number of possible answers
    Question (istream& episodeFile);               // reads the question from the stream
    void Ask ();                                    // displays the question and answers
    int ScoreAnswer (int answer);                   // scores an answer

private:
    static const string CORRECT;                    // text for a correct answer
    static const string WRONG;                      // text for a wrong answer
    static const int CORRECT_ANSWER_SCORE = 1000;   // score for a correct answer
    string m_category;                              // name of the category
    string m_question;                              // question text
    string m_answers[NUM_ANSWERS];                  // an array of the possible answers
    int m_correctAnswer;                            // index of correct answer
    string m_explanation;                           // reason why the answer is correct
};

#endif