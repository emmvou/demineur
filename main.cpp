
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

void jeu(Grid& grid)
{
    do
    {
        displayGrid(grid);

        char mode;
        int i = 0;
        int j = 0;

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


        }
        else if (!grid.flag(i, j))
            std::cout << "instruction interdite" << std::endl;

    } while (!grid.checkWin());

    std::cout << "bravo" << std::endl;
}

int main()
{
    int x = 16;
    int y = 16;
    int nbMines = 30;

    Grid grid(x, y, nbMines);

    jeu(grid);

    return 0;
}
