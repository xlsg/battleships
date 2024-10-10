#include "ShipManager.hpp"


ShipManager::ShipManager(std::initializer_list<int> sizes) :num_of_ships{ (int)sizes.size() }, size_of_ships{ sizes } {
    for (int elem : sizes) {
        Ship* battleship = new Ship(elem);
        Ships.push_back({ battleship, false });
    }
};

void ShipManager::placeShip(Playfield& field, std::pair<int, int> coord, Orientation orientation, int index_ships) {
    if (this->Ships[index_ships].second == true)
        return;
    field.pushShip(coord, this->Ships[index_ships].first, orientation);
    this->Ships[index_ships].second = true;
}

std::vector<Ship*> ShipManager::getActiveShips() {
    std::vector<Ship*> activeShips;
    for (auto elem : this->Ships) {
        if (elem.second == true) {
            activeShips.push_back(elem.first);
        }
    }
    return activeShips;
}

std::vector<Ship*> ShipManager::getInactiveShips() {
    std::vector<Ship*> inactiveShips;
    for (auto elem : this->Ships) {
        if (elem.second == false) {
            inactiveShips.push_back(elem.first);
        }
    }
    return inactiveShips;
}

ShipManager::~ShipManager() {
    for (auto elem : this->Ships) {
        delete elem.first;
    }
}