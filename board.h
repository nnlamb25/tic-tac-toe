#pragma once
#include <array>
#include <tuple>
#include <iostream>
using namespace std;
class Board
{
public:
    void simulateMove(bool isX);
    void simulateTestAI(bool isX);
    Board();
    ~Board();
    bool spotOpen(int spot);
    bool isFull(void);
    bool putX(int spot);
    bool putO(int spot);
    bool checkXWin(void);
    bool checkOWin(void);
    void clear(void);
    void display(void);
private:
    std::array<int, 9> oSpots;
    std::array<int, 9> xSpots;
};

void Board::simulateMove(bool isX) 
{
    /**************************************
     TODO: Implement the AI that cannot
     lose a game of tic-tac-toe in here
     The AI will be tested against 1000 games
     against the test AI, whos moves are random.
     Those who pass the test AI will have to play against
     humans to further test their fortitude.
     ***************************************/
    
    // TODO: Remove this line when new AI is implemented
    simulateTestAI(isX);
    // TODO: Remove this line when new AI is implemented
}

void Board::simulateTestAI(bool isX) 
{
    int spot;
    if (isX) 
    {
        do 
        {
            spot = rand() % 9;
        }
        while (!putX(spot));
    }
    else 
    {
        do 
        {
            spot = rand() % 9;
        } 
        while (!putO(spot));
    }
    
}

Board::Board(void) 
{
    oSpots.fill(false);
    xSpots.fill(false);
}

bool Board::spotOpen(int spot) 
{
    return spot >= 0 && spot < 9 && oSpots.at(spot) == false && xSpots.at(spot) == false;
}

bool Board::isFull(void) 
{
    for (int i = 0; i < 9; i++) 
    {
        if (spotOpen(i))
            return false;
    }
    return true;
}

bool Board::putX(int spot) 
{
    if (spotOpen(spot)) 
    {
        xSpots[spot] = true;
        return true;
    }
    return false;
}

bool Board::putO(int spot) 
{
    if (spotOpen(spot)) 
    {
        oSpots.at(spot) = true;
        return true;
    }
    return false;
}

bool Board::checkXWin(void) 
{
    return ((xSpots[0] && xSpots[1] && xSpots[2]) || (xSpots[3] && xSpots[4] && xSpots[5]) || (xSpots[6] && xSpots[7] && xSpots[8]) || (xSpots[0] && xSpots[3] && xSpots[6]) || (xSpots[1] && xSpots[4] && xSpots[7]) || (xSpots[2] && xSpots[5] && xSpots[8]) || xSpots[0] && xSpots[4] && xSpots[8] || xSpots[2] && xSpots[4] && xSpots[6]);
}

bool Board::checkOWin(void) 
{
    return ((oSpots[0] && oSpots[1] && oSpots[2]) || (oSpots[3] && oSpots[4] && oSpots[5]) || (oSpots[6] && oSpots[7] && oSpots[8]) || (oSpots[0] && oSpots[3] && oSpots[6]) || (oSpots[1] && oSpots[4] && oSpots[7]) || (oSpots[2] && oSpots[5] && oSpots[8]) || oSpots[0] && oSpots[4] && oSpots[8] || oSpots[2] && oSpots[4] && oSpots[6]);
}

void Board::clear(void) 
{
    oSpots.fill(false);
    xSpots.fill(false);
}

void Board::display(void) 
{
    cout << "\n";
    for (int i = 0; i < 3; i++) 
    {
        cout << "\t-------------\n";
        cout << "\t";
        for (int j = 0; j < 3; j++) 
        {
            cout << "| ";
            int spot;
            if (i == 0) {
                if (j == 0)
                    spot = 0;
                else if (j == 1)
                    spot = 1;
                else if (j == 2)
                    spot = 2;
            }
            else if (i == 1) 
            {
                if (j == 0)
                    spot = 3;
                else if (j == 1)
                    spot = 4;
                else if (j == 2)
                    spot = 5;
            }
            else if (i == 2) 
            {
                if (j == 0)
                    spot = 6;
                else if (j == 1)
                    spot = 7;
                else if (j == 2)
                    spot = 8;
            }
            if (oSpots.at(spot))
                cout << "O";
            else if (xSpots.at(spot))
                cout << "X";
            else
                cout << spot;
            cout << " ";
        }
        cout << "|\n";
        cout << "\t-------------\n";
    }
}
