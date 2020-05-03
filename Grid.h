//
// Created by Emmy on 03/05/2020.
//

#ifndef DEMINEUR_GRID_H
#define DEMINEUR_GRID_H


#include "Cell.h"

class Grid
{
public:
    Grid(size_t height, size_t width, size_t nbMines);

    ~Grid();

    Cell& at(size_t x, size_t y);

private:
    size_t nbMines;
    size_t height;
public:
    size_t getNbMines() const;

    size_t getHeight() const;

    size_t getWidth() const;

    bool play(int x, int y);

    bool flag(int x, int y);

    bool checkWin();

private:
    size_t width;
    Cell* array;

    void fill();

    bool valid_pos(int x, int y);
};

#endif //DEMINEUR_GRID_H
