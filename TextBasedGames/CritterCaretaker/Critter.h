#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Critter {
    public:
        Critter (int hunger = 0, int boredom = 0);

        void Talk ();
        void Eat (int food = 5);
        void Play (int fun = 5);
        void PerformTrick ();


    private:
        // mood levels
        enum MOOD { MOOD_HAPPY, MOOD_OKAY = 5, MOOD_FRUSTRATED = 10, MOOD_MAD = 15 };

        // number of tricks
        static const int NUM_TRICKS = 3;
        static const string TRICKS[NUM_TRICKS];

        int m_hunger;
        int m_boredom;
        
        string GetMood () const;
        void PassTime (int time = 1);
};