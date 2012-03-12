#include "StarShip.h"

StarShip::StarShip (string name, int fuel, int maxFuel) : m_name(name), m_fuel(fuel), m_maxFuel(maxFuel) {
    if (fuel < 0)
        m_fuel = 0;
}

void StarShip::Status () {
    cout << "This ship is the " << m_name << endl;
    cout << "It's remaining fuel is: " << m_fuel << endl;
}

void StarShip::Move (int distance) {
    if (distance < 0)
        return;
    
    cout << m_name << " moved " << distance;

    m_fuel -= distance;
    cout << "Fuel remaining: " << m_fuel;
}

void StarShip::Refuel (int fuel) {
    if (m_fuel < m_maxFuel)
        m_fuel += fuel;
}