#include "Playfield.hpp"
#include "Ship.hpp"
#include "ShipManager.hpp"

int main(){

    Playfield battlefield(8, 8);
    ShipManager manager({4, 3, 2, 1});

    manager.placeShip(battlefield, {2,2}, Orientation::horizontal, 0);
    battlefield.print();



    return 0;
}