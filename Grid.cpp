//
// Created by Emmy on 03/05/2020.
//
#include <random>
#include <assert.h>
#include <iostream>
#include "Grid.h"

void Grid::fill()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distX(0, width - 1), distY(0, height - 1);

    for (size_t i = 0; i < this->nbMines; i++)
    {
        int x;
        int y;
        do
        {
            x = distX(rng);
            y = distY(rng);
        } while (this->at(x, y).isContainsMine());

        this->at(x, y).setContainsMine(true);

        for (int dy = -1; dy <= 1; dy++)
            for (int dx = -1; dx <= 1; dx++)
                if (!(dx == 0 && dy == 0) && valid_pos(x + dx, y + dy))
                    at(x + dx, y + dy).incNumber();
    }
}

Grid::Grid(size_t height, size_t width, size_t nbMines)
{
    assert(height * width >= nbMines);

    this->height = height;
    this->width = width;
    this->array = new Cell[this->height * this->width];
    this->nbMines = nbMines;
    this->fill();
}

Grid::~Grid()
{
    delete[] this->array;
}

bool Grid::valid_pos(int x, int y)
{
    return 0 <= x && x < width && 0 <= y && y < height;
}

size_t Grid::getNbMines() const
{
    return nbMines;
}

size_t Grid::getHeight() const
{
    return height;
}

size_t Grid::getWidth() const
{
    return width;
}

bool Grid::play(int x, int y)
{
    if (this->at(x, y).getState() == displayed)
        return false;
    if (this->at(x, y).isContainsMine())
    {
        //le truc quand il a perdu
        this->at(x, y).setState(displayed);
        return true;
    }
    else
    {
        this->at(x, y).setState(displayed);

        if (this->at(x, y).getNumber() == 0)
            for (int dy = -1; dy <= 1; dy++)
                for (int dx = -1; dx <= 1; dx++)
                    if (!(dx == 0 && dy == 0) && valid_pos(x + dx, y + dy))
                        play(dx + x, dy + y);
    }
    return true;
}

bool Grid::flag(int x, int y)
{
    if (this->at(x, y).getState() == displayed)
        return false;
    if (this->at(x, y).getState() == hidden)
        this->at(x, y).setState(flagged);
    else if (this->at(x, y).getState() == flagged)
        this->at(x, y).setState(hidden);
    return true;
}

bool Grid::checkWin()
{
    for (int y = 0; y < this->getHeight(); y++)
        for (int x = 0; x < this->getWidth(); x++)
        {
            if (!this->at(x, y).isContainsMine() && this->at(x, y).getState() != displayed)
                return false;
        }
    return true;
}

Cell& Grid::at(size_t x, size_t y)
{
    return array[y * width + x];
}