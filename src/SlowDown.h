#ifndef SLOWDOWN_H
#define SLOWDOWN_H

#include <memory>
#include <vector>
#include "Coordinate.h"

class SlowDown
{
    public:
    // Constructor
    SlowDown();

    void addCoordinate(const Coordinate &&coordinate);
    bool SlowDownCell(const Coordinate &&coordinate) const;
    void deleteSlowDownCellAt(const Coordinate &&coordinate);

    // Getter
    const std::vector<Coordinate> &getCoordinates() const;
    int count() const;

    private:
    std::unique_ptr<std::vector<Coordinate>> _coordinates;
};

#endif // SLOWDOWN_H
