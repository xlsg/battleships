#ifndef SHIP_MANAGER
#define SHIP_MANAGER

#include <vector>
#include "Ship.hpp"
#include "Playfield.hpp"


class ShipManager {
private:
    int num_of_ships;
    std::vector<int> size_of_ships;
    std::vector<std::pair<Ship*, bool>> Ships;
public:
    ShipManager(std::initializer_list<int> sizes);

    void placeShip(Playfield& field, std::pair<int, int> coord, Orientation orientation, int index_ships);

    std::vector<Ship*> getActiveShips();

    std::vector<Ship*> getInactiveShips();

    ~ShipManager();
};


#endif