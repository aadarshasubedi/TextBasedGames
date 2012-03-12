#include "StarShip.h"

int main () {
    StarShip vessels[3] = { StarShip(), StarShip("Voyager", 10), StarShip("Millennium Falcon", -10) };
    vessels[0].Status();
    vessels[1].Status();
    vessels[2].Status();

    system("pause");
}