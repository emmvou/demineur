//
// Created by Emmy on 03/05/2020.
//

#ifndef DEMINEUR_CELL_H
#define DEMINEUR_CELL_H

enum State
{
    hidden,
    flagged,
    displayed
};

class Cell
{
public:
    State getState() const;

    void setState(State state);

    bool isContainsMine() const;

    void setContainsMine(bool containsMine);

    int getNumber() const;

    void setNumber(int number);

    void incNumber();

private:
    State state = hidden;
    bool containsMine = false;
    int number = 0;
};


#endif //DEMINEUR_CELL_H
