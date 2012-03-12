#ifndef EPISODE_H
#define EPISODE_H 1

#include <string>
#include <fstream>
#include <iostream>

#include "Question.h"

class Episode
{
public:
    Episode (const string& filename);   // reads episode data from the file with the given name
    void Introduce ();                  // displays episode introduction
    bool IsOn ();                       // tests if the episode is still on
    Question NextQuestion ();           // returns the next question

private:
    string m_name;                      // name of the episode
    ifstream m_episodeFile;             // episode data file
};

#endif