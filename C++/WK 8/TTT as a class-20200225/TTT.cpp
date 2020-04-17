#include "TTT.h"
#include <iostream>
#include <iomanip>
using namespace std;

TTT::TTT()
{
    for(int i = 0 ; i < ROW; i++)
        for(int j = 0; j < COL; j++)
            board[i][j] = SPACE;
    numMoves = 0;
}
bool TTT::getMove(char player)
{
    const int BIG_NUM = 100;
    const char EOL = '\n';
    cout << "Your turn " << player << ": enter a row and a column " << endl;
    bool valid = true;
    int move_row, move_col;
    do {
        valid = true;
        cin >> move_row >> move_col;
        if ( move_row < 0 or move_row >= ROW
            or move_col < 0 or move_col >= COL )
        {
            valid = false;
            cout << "Need to make your move on the board " << endl;
            cin.clear();
            cin.ignore(BIG_NUM, EOL);
        }
        else
            if ( board[move_row][move_col] != SPACE )
            {
                valid = false;
                cout << "That space is occupied " << endl;
                cin.clear();
                cin.ignore(BIG_NUM, EOL);
            }
    } while (not valid);
    board[move_row][move_col] = player;
    numMoves++;
}
void TTT::instructions()
{
    cout << "Play TicTacToe" << endl;
}
void TTT::display()
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
            cout << '[' << board[i][j] << ']';
        cout << endl;
    }
    cout << endl;
}
bool TTT::isWin()
{
    return (   (board[0][0] != SPACE and board[0][0] == board[1][1] and board[1][1] == board[2][2])
            or (board[0][2] != SPACE and board[0][2] == board[1][1] and board[1][1] == board[2][0])
            or (board[0][0] != SPACE and board[0][0] == board[0][1] and board[0][1] == board[0][2])
            or (board[1][0] != SPACE and board[1][0] == board[1][1] and board[1][1] == board[1][2])
            or (board[2][0] != SPACE and board[2][0] == board[2][1] and board[2][1] == board[2][2])
            or (board[0][0] != SPACE and board[0][0] == board[1][0] and board[1][0] == board[2][0])
            or (board[0][1] != SPACE and board[0][1] == board[1][1] and board[1][1] == board[2][1])
            or (board[0][2] != SPACE and board[0][2] == board[1][2] and board[1][2] == board[2][2])  );
}
bool TTT::isTie()
{
    return !isWin() and numMoves == 9;
}
