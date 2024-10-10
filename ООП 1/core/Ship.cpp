#include "Ship.hpp"



Ship::ShipSegment::ShipSegment(Ship* owner, ShipSegmentCondition cond):owner_ship{ owner }, condition{ cond }{};

Ship* Ship::ShipSegment::getOwner(){
    return this->owner_ship;
}

void Ship::ShipSegment::takeDamage(){
     if (this->condition == ShipSegmentCondition::full) {
            this->condition = ShipSegmentCondition::damaged;
        }
        else if (this->condition == ShipSegmentCondition::damaged) {
            this->owner_ship->num_of_alive_segments--;
            this->condition = ShipSegmentCondition::broken;
        }
}


Ship::Ship(int lenght):size{ lenght }, num_of_alive_segments{ lenght } {
    for (int i = 0; i < lenght; i++) {
        ShipSegment* segment = new ShipSegment(this, ShipSegmentCondition::full);
        ship_segments.push_back(segment);
    }
}

int Ship::getSize(){
    return this->size;
}

std::vector<Ship::ShipSegment*> Ship::getSegments() {
    return this->ship_segments;
}


Ship::~Ship() {
    for (auto elem : this->ship_segments) {
        delete elem;
    }
}