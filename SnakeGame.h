#pragma once
// Controller class
#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include "Board.h"
#include "Drawable.h"
#include "Growth.h"
#include "Empty.h"

class SnakeGame 
{
public:
    SnakeGame(int height, int width) :growth(NULL)
    {
        board = Board(height, width);
        board.initialize();
        game_over = false;
        srand(time(NULL));
    }
    ~SnakeGame()
    {
        delete growth;
    }
    void processInput()
    {
        wchar_t input = board.getInput();
    }

    void updateState()
    {
        int y, x;
        board.getEmptyCoordinates(y, x);
        if (growth != NULL)
            board.add(Empty(growth->getY(), growth->getX()));
        growth = new Growth(y, x);
        board.add(*growth);
        board.add(Drawable(3, 3, '+'));
    }

    void redraw()
    {}

    bool isOver()
    {
        return game_over;
    }
private:
    Board board;
    Growth* growth;
    bool game_over;
};