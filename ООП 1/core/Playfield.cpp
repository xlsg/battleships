#include "Playfield.hpp"


void Playfield::PlayfieldCell::setCellStatus(PlayfieldCellCondition condition, Ship::ShipSegment* segment) {
    this->cell_status = PlayfieldCellCondition::ship_segment;
    this->segment = (segment == nullptr) ? nullptr : segment;
}

PlayfieldCellCondition Playfield::PlayfieldCell::getCellStatus() {
    return this->cell_status;
}

Ship::ShipSegment* Playfield::PlayfieldCell::getSegment() {
    return this->segment;
}

Playfield::Playfield(int x, int y):size_x{size_x}, size_y{size_y}{
    x = (x > MINIMAL_FIELD_SIZE) ? x : MINIMAL_FIELD_SIZE;
    y = (y > MINIMAL_FIELD_SIZE) ? y : MINIMAL_FIELD_SIZE;
    for (int i = 0; i < x; i++) {
        std::vector<PlayfieldCell> line;
        play_field.push_back(line);
        for (int j = 0; j < y; j++) {
            play_field[i].push_back(PlayfieldCell());
        }
    }
}

void Playfield::pushShip(std::pair<int, int> coord, Ship* push_ship, Orientation orientation) {
    if (this->play_field.size() < coord.first || coord.first < 0 || this->play_field[0].size() < coord.second || coord.second < 0 || (*push_ship).getSize() == 0 || this->play_field.size() < (coord.first + (*push_ship).getSize()) || this->play_field[0].size() < (coord.second + (*push_ship).getSize())) {
        return;
    }

    switch (orientation) {
    case Orientation::horizontal:
        for (int i = 0; i < (*push_ship).getSize(); i++) {
            this->play_field[coord.first][coord.second + i].setCellStatus(PlayfieldCellCondition::ship_segment, (*push_ship).getSegments()[i]);
        }
        break;
    case Orientation::vertical:
        for (int i = 0; i < (*push_ship).getSize(); i++) {
            this->play_field[coord.first + i][coord.second].setCellStatus(PlayfieldCellCondition::ship_segment, (*push_ship).getSegments()[i]);
        }
        break;
    }
}

void Playfield::hit(std::pair<int, int> coord) {
    if (this->play_field[coord.first][coord.second].getCellStatus() == PlayfieldCellCondition::ship_segment)
        this->play_field[coord.first][coord.second].getSegment()->takeDamage();
}

Playfield::Playfield(const Playfield& copy){
    size_x = copy.size_x;
    size_y = copy.size_y;
}

Playfield::Playfield(Playfield&& moved){
    play_field=std::move(moved.play_field);
}


void Playfield::print(){
    for (int i = 0; i < this->play_field.size(); i++){
        for (int j = 0; j < this->play_field[0].size(); j++){
            switch (this->play_field[i][j].getCellStatus()){
                case PlayfieldCellCondition::empty:
                    std::cout << 0 << ' ';
                    break;
                case PlayfieldCellCondition::ship_segment:
                    std::cout << 1 << ' ';
                    break;
                default:
                    std::cout << '*' << ' ';
            }
        }
        std::cout << '\n';
    }
}
