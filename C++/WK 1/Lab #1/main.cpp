/*Used Jim's help too
website help
-http://www.cppforschool.com/project/tic-tac-toe-project.html
-https://www.daniweb.com/programming/software-development/threads/261887/array-tic-tac-toe-with-functions
-http://www.cplusplus.com/forum/beginner/99098/
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// global constants
const int SIZE = 9;
const char X = 'X';
const char O = 'O';
const char SPACE = ' ';
const long BIGNUM = numeric_limits <streamsize>::max();

//char player1, player2;
//int currentPlayer;


// function
void showInstructions();
int initBoard(char board[]);
void displayBoard(char board[]);
int getMove(char board[], char player);
void updateBoard(char board[], int move, char player);
bool checkWin(char board[]);
bool checkTie(char board[]);
bool repeat();



int main()
{
    char board[SIZE];
    int move;
    bool win, tie = false;
    char player = X;

do{
    showInstructions();
    initBoard(board);

    do{
        displayBoard(board);
        move=getMove(board, player);
        updateBoard(board, move, player);

        player=(player==X)?O:X;

        win=checkWin(board);
        tie=checkTie(board);


    }while(win!=true && tie!=true);


    displayBoard(board);

    if (win)

    {   player=(player==X)?O:X;
        cout << "Congratulations " <<player << " you won." << endl;
    }
    if (tie)
    {
        cout << "The game was a tie." << endl;
    }

}while(repeat());

//Process
//showInstructions();
//initBoard(char board[]);
//displayBoard(char board[]);
//getMove(char board[], char player);
//updateBoard(char board[], int move, char player);
//check for win & draw because it will only stop the game if true for win or tie.
//switch player
//start over from get move





    /*initBoard(board);
    move = getMove(board);
    updateBoard(board, move, player);

    if (checkWin(board))
        cout << "won" << endl;


*/


/*
if(player==X)
    player=O;
else
    player =X;
return player;

    return 0;
*/



}

// function definitions
//first time displays instructions times played after display getting into the game. Similar outline to RPS instructions.
void showInstructions()
{
static bool first = true;
    if(first)
        {cout<< "We're going to play Tic Tac Toe"<<
            "This is a 2 player game. Each player will choose from 0 to 8 to place X or O"<<
            "Let's get going"<< endl;
        }
    else
        cout << "You know how to play Tic Tac Toe, place your X or O Player 1"<< endl;
    first=false;

}


//initialize array to spaces
int initBoard(char board[])
{

    for(int i = 0; i<SIZE; i++)
        {
            board[i] = SPACE;
        }
}

//actually displaying the board, initialize creates the outline display to show, update moves and then display to show
void displayBoard(char board[])
{
cout << "Here is what the board currently looks like" << endl;

    for (int i=0;i<SIZE;i++)
    {
        cout << "["<<board[i]<<"]";
        if((i+1)%3 ==0)
            {
                cout<<endl;
            }
    }


}

//pass in board, return a move/player choice, data validation of move choice
int getMove(char board[], char player)
{

int move;
bool valid = true;

cout << "Enter a move between 0 and 8, to place an X or O for Tic Tac Toe" << endl;
    //data validation of player's choice
    do {
        cin >>move;
        valid =true;
        if (cin.fail() || move <0 || move>8|| board[move]!= SPACE)
        {
            cin.clear();
            cin.ignore(BIGNUM, '\n');
            cout << "Computer says no, invalid move" << endl;
            valid = false;
        }
        } while (not valid);

 return move;
}

void updateBoard(char board[], int move, char player)
{
    switch(move)
			{
				case 0: board[0] = player; break;
				case 1: board[1] = player; break;
				case 2: board[2] = player; break;
				case 3: board[3] = player; break;
				case 4: board[4] = player; break;
				case 5: board[5] = player; break;
				case 6: board[6] = player; break;
				case 7: board[7] = player; break;
				case 8: board[8] = player; break;
			}
}



//pass in board, return true if win
bool checkWin(char board[])
{

bool valid = true;
    //row wins
            //1st row win
    if (    (board[0] == board[1] && board[1] == board[2] && board[0] != SPACE)||
            //2nd row win
            (board[3] == board[4] && board[4] == board[5] && board[3] != SPACE)||
            //3rd row win
            (board[6] == board[7] && board[7] == board[8] && board[6] != SPACE)||
    //column wins
            //1st col win
            (board[0] == board[3] && board[3] == board[6] && board[0] != SPACE)||
            //2nd column win
            (board[1] == board[4] && board[4] == board[7] && board[1] != SPACE)||
            //3rd col win
            (board[2] == board[5] && board[5] == board[8] && board[2] != SPACE)||
    //Diagonal win
            //L to R win
            (board[0] == board[4] && board[4] == board[7] && board[0] != SPACE)||
            //R to L win
            (board[2] == board[4] && board[4] == board[6] && board[2] != SPACE)
        )
        return true;

    return false;
}

//pass in board, return true if draw tie?
bool checkTie(char board[])
{

    for(int i=0;i<SIZE; i++)
        if (board[i]==SPACE)
        return false;

return true;
}

//only true or false so will be a bool function
bool repeat()
{
    bool valid = true;
    char answer;
do
{
    cout << "Would you like to play again, y/ n?" << endl;
    cin >> answer;

    switch(answer)
{
        case 'y':
        answer = true;
        valid = true;
        break;
        case 'n':
        answer = false;
        valid = true;
        break;
        default:
        cout << "Incorrect, please enter y or n!" << endl;
        valid = false;
        break;
}
  }while ( !valid);

return answer;
}
