//
// Created by Emmy on 03/05/2020.
//

#include "Cell.h"

State Cell::getState() const
{
    return state;
}

void Cell::setState(State state)
{
    Cell::state = state;
}

bool Cell::isContainsMine() const
{
    return containsMine;
}

void Cell::setContainsMine(bool containsMine)
{
    Cell::containsMine = containsMine;
}

int Cell::getNumber() const
{
    return number;
}

void Cell::setNumber(int number)
{
    Cell::number = number;
}

void Cell::incNumber()
{
    setNumber(getNumber() + 1);
}