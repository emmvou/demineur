
#include <iostream>
#include <assert.h>
#include "Grid.h"

void displayGrid(Grid& grid)
{
    std::cout << "   ";
    for (int x = 0; x < grid.getWidth(); x++)
    {
        std::cout << " " << x;

        if (x < 10)
            std::cout << " ";
    }
    std::cout << std::endl;

    for (int y = 0; y < grid.getHeight(); y++)
    {
        std::cout << " " << y;

        if (y < 10)
            std::cout << " ";

        for (int x = 0; x < grid.getWidth(); x++)
        {
            switch (grid.at(x, y).getState())
            {
                case hidden:
                    std::cout << " . ";
                    break;

                case flagged:
                    std::cout << " ! ";
                    break;

                case displayed:
                    if (grid.at(x, y).isContainsMine())
                        std::cout << " X ";
                    else
                        std::cout << " " << grid.at(x, y).getNumber() << " ";
                    break;

                default:
                    assert(false);
            }
        }
        std::cout << std::endl;
    }

}

bool jeu(Grid& grid)
{
    bool exploded = false;
    do
    {
        char mode;
        int i = 0;
        int j = 0;

        std::cout << "Mines restantes : " << (signed int) grid.getNbMines() - grid.countFlag() << " / "
                  << grid.getNbMines() << std::endl;

        displayGrid(grid);

        do
        {
            std::cout << "play (p) or flag (f)" << std::endl;
            std::cin >> mode;
        } while (mode != 'p' && mode != 'f');

        do
        {
            std::cout << "x axis" << std::endl;
            std::cin >> i;
        } while (i < 0 || i > grid.getWidth());

        do
        {
            std::cout << "y axis" << std::endl;
            std::cin >> j;
        } while (j < 0 || j > grid.getHeight());

        if (mode == 'p')
        {
            if (!grid.play(i, j))
                std::cout << "instruction interdite" << std::endl;
            //check si c'est une mine
            if (grid.at(i, j).isContainsMine())
            {
                return false;
            }

        }
        else if (!grid.flag(i, j))
            std::cout << "instruction interdite" << std::endl;

    } while (!grid.checkWin());
    return true;
}

int main()
{
    int x = 4;
    int y = 4;
    int nbMines = 5;

    Grid grid(x, y, nbMines);

    if (jeu(grid))
    {
        displayGrid(grid);
        std::cout << "bravo" << std::endl;
    }
    else
    {
        grid.lost();
        displayGrid(grid);
        std::cout << "perdu" << std::endl;
    }

    return 0;
}
