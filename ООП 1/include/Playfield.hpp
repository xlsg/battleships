#ifndef PLAYFIELD
#define PLAYFIELD

#include <vector>
#include "Ship.hpp"
#include <iostream>

enum class PlayfieldCellCondition {
    unknown,
    empty,
    ship_segment
};

const int MINIMAL_FIELD_SIZE = 8;


class Playfield {
private:
    class PlayfieldCell {
    private:
        Ship::ShipSegment* segment = nullptr;
        PlayfieldCellCondition cell_status = PlayfieldCellCondition::empty;
    public:
        void setCellStatus(PlayfieldCellCondition condition, Ship::ShipSegment* segment);

        PlayfieldCellCondition getCellStatus();

        Ship::ShipSegment* getSegment();
    };

    std::vector<std::vector<PlayfieldCell>> play_field;
    int size_x;
    int size_y;
public:
    Playfield(int size_x, int size_y);

    void pushShip(std::pair<int, int> coord, Ship* push_ship, Orientation orientation);

    void hit(std::pair<int, int> coord);

    Playfield(const Playfield& copy);

    Playfield(Playfield&& moved);

    void print();
};


#endif
