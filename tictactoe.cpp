// TicTacToe.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include "board.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;


int main()
{
    srand(time(NULL));
    char playAgain;
    char response;
    Board *board;
    cout << "Welcome to ACM's Tic Tac Toe program.\n";

    do
    {
       cout << "You can either play against the AI yourself or test the AI.\n\n\t\"T\" tests the implemented AI\n\t\"P\" allows the user to play against the AI\n\t\"X\" exits the program\n\nSelect an Option: ";
       
       cin >> response;
       while (response != 'X' && response != 'P' && response != 'T' &&
           response != 'x' && response != 'p' && response != 't')
       {
          cout << "Please enter a valid option: ";
          cin >> response;
       }
       if (response == 'P' || response == 'p')
       {
          board = new Board();
          cout << "Xs or Os? ";
          cin >> response;
          while (response != 'O' && response != 'X' && response != 'o' && response != 'x')
          {
             cout << "Xs or Os? ";
             cin >> response;
          }
          if (response == 'X' || response == 'x')
          {
             cout << "You go first!\n";
             while (!board->checkXWin() && !board->checkOWin() && !board->isFull())
             {
                int spot;
                board->display();
                cout << "Your move: ";
                cin >> spot;
                while (!board->putX(spot))
                {
                    cin.ignore();
                    cout << "Choose an open space: ";
                    cin >> spot;
                }
                if(!board->isFull())
                   board->simulateMove(false);
             }
             if (board->checkXWin())
                cout << "You won!";
             else if (board->checkOWin())
                cout << "You Lost!";
             else
                cout << "It is a tie!";
          }
          else
          {
             cout << "You go second!\n";
             while (!board->checkXWin() && !board->checkOWin() && !board->isFull())
             {
                int spot;
                board->simulateMove(true);
                board->display();
                if (!board->isFull())
                {
                    cout << "Your move: ";
                    cin >> spot;
                    int timeOut = 0;
                    while (!board->putO(spot))
                    {
                       cin.ignore();
                       cout << "Choose an open space: ";
                       cin >> spot;
                    }
                }
             }
             if (board->checkOWin())
                cout << "You won!\n";
             else if (board->checkXWin())
                cout << "You Lost!\n";
            else
               cout << "It is a tie!\n";
          }
       }
       else if (response == 'T' || response == 't')
       {
          board = new Board();
          cout << "Running many tests against the implemented AI\n";
          bool fail = false;
          int i = 0;
          while (i < 1000 && !fail)
          {
             board->clear();
             if (rand() % 2 == 0)
            {
               while (!board->checkXWin() && !board->checkOWin() && !board->isFull())
               {
                  board->simulateTestAI(true);
                  if(!board->isFull())
                     board->simulateMove(false);
               }
               board->display();
               if (board->checkOWin())
                  fail = true;
            }
             else
             {
                while (!board->checkXWin() && !board->checkOWin() && !board->isFull())
               {
                  board->simulateMove(true);
                  if(!board->isFull())
                     board->simulateTestAI(false);
               }
                board->display();
                if (board->checkXWin())
                   fail = true;
            }
          }
          if (fail)
             cout << "The AI failed the task!!!!\n";
          else
             cout << "The AI passed the task!!!!\n";
       }
       
       cout << "\nPlay again? (Y/N)\n> ";
       cin >> playAgain;

       while (playAgain != 'Y' && playAgain != 'N' && playAgain != 'y' && playAgain != 'n')
       {
          cout << "Invalid input\nPlay again? (Y/N)\n> ";
          cin >> playAgain;
       }
    }
    while (playAgain == 'Y' || playAgain == 'y');
    
    cout << "\nExiting program...\n";

    return 0;
}

