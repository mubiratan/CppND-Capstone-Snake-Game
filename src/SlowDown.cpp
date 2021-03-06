#include "SlowDown.h"
#include <memory>
#include "Coordinate.h"

SlowDown::SlowDown()
{
    // Initialising unique pointer
    _coordinates =
            std::unique_ptr<std::vector<Coordinate>>(new std::vector<Coordinate>);
}

void SlowDown::addCoordinate(const Coordinate &&coordinate)
{
    _coordinates->emplace_back(coordinate);
}

bool SlowDown::SlowDownCell(const Coordinate &&coordinate) const
{
    for (const Coordinate &_coordinate : *_coordinates)
    {
        if (_coordinate == coordinate)
        {
            return true;
        }
    }
    return false;
}

void SlowDown::deleteSlowDownCellAt(const Coordinate &&coordinate)
{
    /// Early exit.
    if (_coordinates->size() == 0)
    {
        return;
    }
    for (auto it = _coordinates->begin(); it != _coordinates->end();)
    {
        if (*it == coordinate)
        {
            it = _coordinates->erase(it);
        }
        else
        {
            ++it;
        }
    }
}

const std::vector<Coordinate> &SlowDown::getCoordinates() const
{
    return *_coordinates;
}

int SlowDown::count() const
{
    return _coordinates->size();
}
