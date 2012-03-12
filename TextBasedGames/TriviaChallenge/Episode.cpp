#include "Episode.h"

using namespace std;

Episode::Episode (const string& filename) {
    // attempt to open the file with the episode
    m_episodeFile.open(filename.c_str(), ios::in);

    if (m_episodeFile.fail()) {
        cout << "File " << filename << " could not be opened for reading." << endl;
        exit (1);
    }

    // read episode name
    getline(m_episodeFile, m_name);
}

void Episode::Introduce () {
    cout << "Get ready to play... " << m_name << endl << endl;
}

bool Episode::IsOn () {
    return m_episodeFile.good();
}

Question Episode::NextQuestion () {
    return Question(m_episodeFile);
}