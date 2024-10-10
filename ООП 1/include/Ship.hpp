#ifndef SHIP
#define SHIP
#include <vector>


enum class ShipSegmentCondition {
    full,
    damaged,
    broken
};

enum class Orientation {
    vertical,
    horizontal
};


class Ship {
public:
    class ShipSegment {
    private:
        Ship* owner_ship = nullptr;
        ShipSegmentCondition condition = ShipSegmentCondition::full;
    public:
        ShipSegment(Ship* owner, ShipSegmentCondition cond);

        Ship* getOwner();

        void takeDamage();
    };
private:
    int size;
    std::vector<ShipSegment*> ship_segments;
    int num_of_alive_segments;
public:
    Ship(int lenght);

    int getSize();

    std::vector<ShipSegment*> getSegments();

    ~Ship();
};

#endif