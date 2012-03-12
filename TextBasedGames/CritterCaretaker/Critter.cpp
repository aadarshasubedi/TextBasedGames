#include "Critter.h"

const string Critter::TRICKS[Critter::NUM_TRICKS] = { "roll over", "jump", "do a backflip" };

Critter::Critter (int hunger, int boredom) : m_hunger(hunger), m_boredom(boredom) {}

string Critter::GetMood () const {
    string mood;

    if (m_hunger + m_boredom > MOOD_MAD)
        mood = "mad";
    else if (m_hunger + m_boredom > MOOD_FRUSTRATED)
        mood = "frustrated";
    else if (m_hunger + m_boredom > MOOD_OKAY)
        mood = "okay";
    else
        mood = "happy";

    return mood;
}

void Critter::PassTime (int time) {
    m_boredom += time;
    m_hunger += time;
}

void Critter::Talk () {
    cout << "I'm a critter and I feel " << GetMood() << "." << endl;

    PassTime();
}

void Critter::Eat (int food) {
    cout << "Brruppp." << endl;

    m_hunger -= food;
    if (m_hunger < 0)
        m_hunger = 0;

    PassTime();
}

void Critter::Play (int fun) {
    cout << "Whee!" << endl;

    m_boredom -= fun;
    if (m_boredom < 0)
        m_boredom = 0;

    PassTime();
}

void Critter::PerformTrick () {
    if (GetMood() != "happy") {
        cout << "I don't feel like doing a trick." << endl;
    }
    else {
        int choice = (rand() % NUM_TRICKS);
        string trick = TRICKS[choice];
        cout << "I " << trick << "." << endl;
    }

    PassTime();
}