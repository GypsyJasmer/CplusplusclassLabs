/*
* Main.cpp
* Memory Lab CS 162
*
* Jim Bailey
*/


#include <iostream>
#include <iomanip>  // for output formatting
#include <cstdlib>  // for random numbers
#include <ctime>    // to initialize random
#include <cstdio>
#include <limits>

using namespace std;


// define game constants
const int ROW=4;
const int COL=4;
const int NUM_SYMS = 8;
const char SYMBOLS[NUM_SYMS] = {'!','@','#','$','%','^','&','*'};
const char SPACE = ' ';
const char UNKNOWN = 'X';
const char YES = 'Y';
const char NO = 'N';
const int BIGNUM = numeric_limits<streamsize>::max();
const char EOL = '/n';

// define global structure type
struct t_move{int row; int col;};

// function declarations, functions below
char* createBoard();
void displayInstructions();
void displayBoard(char* board);
void displayBoard(char* board, t_move move1);
void displayBoard(char* board, t_move move1, t_move move2);
t_move getMove();
void updateBoard(char* board, t_move move1, t_move move2);
int numSpaces(char* board);
bool repeat();

int main()
{

    // initialize random number generator
    srand(static_cast<int>(time(NULL)));

        // loop to play game again
    do {
        // get a new random board filled with symbols
        char* board = createBoard();

        // tell the user how to play the game
        displayInstructions();

        //counter for how many guesses
        int moveCount = 0;

            // game loop, ends when all symbols paired
        do {
                // show the board before they move
                displayBoard(board);
                t_move move1 = getMove();
                // show the board with that move displayed
                displayBoard(board, move1);
                t_move move2 = getMove();
                // show the board with both moves displayed
                displayBoard(board, move1, move2);
                // if symbols match, update board
                updateBoard(board, move1, move2);

                // skip some spaces before next round
                cout << endl << endl;

                // increment guess counter
                moveCount++;

        } while ( numSpaces(board) < 2 * NUM_SYMS );

        cout << "It took you " << moveCount << " guesses." << endl;

        // free up the memory from this itration
        delete [] board;
    } while ( repeat() );


    return 0;
}


//function is a pointer and will be similar to lab #4 //technically 2 arrays, symbols and X's
char* createBoard()
{
    int location;

    char*board=new char[ROW*COL]; //create new pointer array from memory allocation


    for(int i=0;i<(ROW*COL); i++) //do whiles 2x's to rotate symbols to fill the board/array
    {
        board[i] = SPACE;
    }

    for(int i=0;i<NUM_SYMS; i++)//linear search
    {
        do
        {
            location=rand()%(ROW*COL);

        }while(*(board+location)!=SPACE);

        *(board+location)=SYMBOLS[i];

        do
        {
            location=rand()%(ROW*COL);
        }while(*(board+location)!=SPACE);

        *(board+location)=SYMBOLS[i];
    }
    return board;

}

//static bool instructions for player to start faster in play again.
void displayInstructions()
{
    static bool first = true;
    if(first)
        {
            cout<< "Welcome to Memory game!"<<endl;
            cout<<"The goal is to match all cards." <<endl;
            cout<<"You will start by selecting a car to flip over,"<<endl;
            cout<<"now try to remember that card because you will select a second card to flip over."<<endl;
            cout<<"Best of luck to you!"<< endl;
        }
    else
        cout << "You know how to play Memory, get flipping."<< endl;
    first=false;
}

//display all x's or space
void displayBoard(char* board)
{
//passing in board array


    cout << "Here is what the board currently looks like" << endl;

    for(int i = 0; i<(ROW*COL); i++)
    {
        if(board[i] == SPACE)
        {
           cout <<SPACE;
        }
        else
        {
            cout<<UNKNOWN; //placing X's on top of non flipped symbols
        }
            if((i+1)%COL==0)
            {
                cout<<endl;
            }

    }

}


//display all except the one flipped
void displayBoard(char* board, t_move move1)
{
    int location1=move1.row*COL +move1.col;

    //cout << "Here is what the board currently looks like" << endl;
    for (int i=0;i<(ROW*COL); i++)
    {
        if(i==location1)
        {
            cout<<board[i];
        }
        else if (board[i]==SPACE)
        {
            cout<<SPACE;
        }
        else
        {
            cout<<UNKNOWN;
        }
            if((i+1)%COL==0)
            {
                cout<<endl;
            }

    }
}

//display all except the first and second card flipped if matched
void displayBoard(char* board, t_move move1, t_move move2)
{
    int location1=move1.row*COL +move1.col;
    int location2=move2.row*COL + move2.col;

     //cout << "Here is what the board currently looks like" << endl;


    for (int i=0;i<(ROW*COL); i++)
    {
        if(i==location1)
        {
            cout<<board[i];
        }
        else if(i==location2)
        {
            cout<<board[i];
        }
        else if (board[i]==SPACE)
        {
            cout<<SPACE;
        }
        else
        {
            cout<<UNKNOWN;
        }
            if((i+1)%COL==0)
            {
                cout<<endl;
            }
    }
}

//struct get move t is the data type not variable
t_move getMove() //has row & col
{

    t_move playerMove;//create a struct declared above but not created

    //fill struct w/ stuff
    cout<<"What card do you want to flip please enter row and column separated by a space"<<endl;

    //data validation of players choice for row
    do {
        cin>>playerMove.row;
        if (playerMove.row < 0 && playerMove.row >COL)
        {
            cin.clear();
            cin.ignore(BIGNUM, EOL);
            cout << "Computer says no, invalid move please " << endl;

        }
        } while (playerMove.row < 0 && playerMove.row >COL);

    //data validation of players choice for col
    do {
        cin>>playerMove.col;
        if (playerMove.col< 0&& playerMove.col>COL)
        {
            cin.clear();
            cin.ignore(BIGNUM, EOL);
            cout << "Computer says no, invalid move please " << endl;

        }
        } while (playerMove.col< 0 && playerMove.col>COL);

    return playerMove;
}

//update what was flipped or matched then a display after
void updateBoard(char* board, t_move move1, t_move move2)
{
    //Indexing => width * row + col
    int location1 = COL*move1.row+move1.col;
    int location2 = COL*move2.row+move2.col;

    if (board[location1]==board[location2] && location1 != location2)
    {
        board[location1]=SPACE;
        board[location2]=SPACE;
    }


}

//tracking number of empty spaces on the board = flipped/matched cards if all space it equals game is over
int numSpaces(char* board)
{
    int counter=0;

    for (int i =0; i<NUM_SYMS; i++)
    {
        if(board[i]==SPACE)
        {
            counter++;
        }
    }
    return counter;

}

//do while /data validation loop not switch
bool repeat()
{
    char repeat;
    bool valid = true;
        //data validation (outlined)
        do {
            cin >>repeat;
            valid =true;
            if (cin.fail() || repeat != 'y' && repeat !='n')
            {
                cin.clear();
                cin.ignore(BIGNUM, '\n');
                cout << "Computer says no" << endl;
                valid = false;
            }
            } while (not valid);

    return repeat;
}

