#include <string>
#include <iostream>

#ifndef _STARSHIP_H
#define _STARSHIP_H

using namespace std;

class StarShip {
    public:
        StarShip (string name = "Enterprise", int fuel = 0, int maxFuel = 10);

        void Status ();
        void Move (int);
        void Refuel (int fuel);

    private:
        int m_maxFuel;
        string m_name;
        int m_fuel;
};

#endif // !_STARSHIP.H_