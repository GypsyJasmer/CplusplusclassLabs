/*
Websites used for reference
-http://www.cplusplus.com/forum/beginner/28714/
https://codereview.stackexchange.com/questions/203325/dungeon-crawl-game-for-the-terminal

*/
#include <iostream>
#include <cstdlib> // for random #include <ctime>
#include <limits>
#include <ctime>

using namespace std;


// global constants
const int MAX_ROW=10;
const int MAX_COL=12;
const char SPACE = '.';
const char TRAP = '#';
const char PLAY = '@';
const char CASH = '$';
const char UP = 'U';
const char DOWN = 'D';
const char LEFT = 'L';
const char RIGHT = 'R';
//const char WIN = 'C';
//const char LOSE = 'T';
const int NUM_TRAPS = 6;
const int NUM_CASH = 2;
const long BIGNUM = 2000;




// function declarations

// displays the instructions
void displayInstructions();
// sets up a dungeon with traps and treasure
void initDungeon(char dungeonArray[MAX_ROW][MAX_COL],int&playerRow, int&playerCol);
// display the current dungeon state
void displayDungeon(char dungeonArray[MAX_ROW][MAX_COL]);
// gets a valid move (L,R,U,D)
void getMove(char dungeonArray[MAX_ROW][MAX_COL],int playerRow, int playerCol, int&newRow, int&newCol);
// sees if move is onto checkCode object
bool checkMove(char dungeonArray[MAX_ROW][MAX_COL],  int newRow, int newCol);
//checking win and lose
char checkWin(char dungeonArray[MAX_ROW][MAX_COL], int newRow, int newCol);
// update the dungeon for next move
void updateDungeon(char dungeonArray[MAX_ROW][MAX_COL], int&playerRow, int&playerCol, int newRow, int newCol);
// do you want to play again?
bool repeat();


int main()
{
    int playerRow, playerCol, newRow, newCol;
    char dungeonArray [MAX_ROW][MAX_COL];
    char result=SPACE;
    srand(static_cast<int>(time(NULL))); // initialize random



//Main loop for play again
//displayInstructions
//initDungeon --- questions on variable passing through for function
do {
    char result=SPACE;
    displayInstructions();
    initDungeon(dungeonArray, playerRow, playerCol);

// game loop
    do {

        //displayDungeon
        //getMove
        //checkMove
        //checkWin
        //if the play is still active then update the board with the players requested spot
        //play until win or lose
        //repeat
        displayDungeon(dungeonArray);
        getMove(dungeonArray, playerRow, playerCol, newRow, newCol);


        if (checkMove(dungeonArray, newRow, newCol))
        {
            updateDungeon(dungeonArray, playerRow, playerCol, newRow, newCol);

        }
        else
            {
                result = checkWin(dungeonArray, newRow, newCol);
                //while statement will be if result = Win or Trap we end the game and repeat.
            }


        //updateDungeon();
} while (result == SPACE);

} while (repeat());

return 0;
}


// function definitions

// static bool instructions.
void displayInstructions()
{
   static bool first = true;
    if(first)
        {
            cout<< "Welcome to Dungeon Crawl!"<<endl;
            cout<<"The goal is to get to the exit of the" <<endl;
            cout<<"dungeon without hitting any of the traps. "<<endl;
            cout<<"Best of luck to you!"<< endl;
        }
    else
        cout << "You know how to play Dungeon Crawl, get crawling."<< endl;
    first=false;

}

// sets up a dungeon with traps and treasure
void initDungeon(char dungeonArray[MAX_ROW][MAX_COL], int&playerRow, int&playerCol)
{
    int row, col;
/*
1) createDungeon – initializes a new dungeon
a) pass in the dungeon and a number for how many traps to place
b) randomly place that many traps in the dungeon
c) randomly places treasure and player
d) make sure that each item
You create the dungeon in main, so you can pass it around as need be.
The initialization code sets all locations to a blank space, then randomly sets as many traps as you want, then randomly locates one treasure and finally randomly places the player.
If you have monsters, you set them up also. You can make sure that each new item is on its own space or you can allow later placed items to overwrite earlier placed ones. Your choice of how you want to proceed.
*/
    //sets board
    for(int i = 0; i<MAX_ROW; i++)
        for (int j=0; j<MAX_COL; j++)
        {
            dungeonArray[i][j]=SPACE;
        }
        //cout<< " Dungeon is set"<<endl;

    //sets random traps
    for(int i = 0; i < NUM_TRAPS; i++)
    {
        row = rand()% (MAX_ROW);
        col = rand()% (MAX_COL);
            if (dungeonArray[row][col]==SPACE) //want to know if space
                dungeonArray[row][col]=TRAP; //set trap w/ =
            else
                i--;
    }

    //cout<< " Traps are set"<<endl;

    //sets random cash
    for(int i = 0; i < NUM_CASH; i++)
    {
        row = rand()% (MAX_ROW);
        col = rand()% (MAX_COL);
            if (dungeonArray[row][col]==SPACE) //want to know if space
                dungeonArray[row][col]=CASH; //set CASH w/ =
            else
                i--;
    }
    //cout<< " CASH is set"<<endl;


    //sets player on empty spot
    do{
        playerRow = rand()% (MAX_ROW);
        playerCol = rand()% (MAX_COL);
        if (dungeonArray[playerRow][playerCol]== SPACE)
        {
            dungeonArray[playerRow][playerCol]=PLAY;
        }


    }while (dungeonArray[playerRow][playerCol] != PLAY);

    //cout<< " Player is set"<<endl;

}


// display the current dungeon state
void displayDungeon(char dungeonArray[MAX_ROW][MAX_COL])
{
    /*
a) pass in the dungeon
b) display the dungeon
c) return type should be void
Displaying the board should be simpler than in TTT, since you just output the dungeon array.
*/
    cout << "Here is what the dungeon currently looks like" << endl;

    for(int i = 0; i<MAX_ROW; i++)
    {
        for (int j=0; j<MAX_COL; j++)
        {
            cout<<dungeonArray[i][j];
        }
    cout<<endl;
    }

}

// gets a valid move (L,R,U,D)
void getMove(char dungeonArray[MAX_ROW][MAX_COL],int playerRow, int playerCol, int&newRow, int&newCol )
{
    cout << " Enter 'U' for Up, 'D' for Down, 'L' for Left, and 'R' for Right"<<endl;

    int row = playerRow,col= playerCol;
    bool valid = true;
    char playerMove;

        //data validation (outlined)
        do {
            row = playerRow;col= playerCol;
            cin >>playerMove;
            playerMove = toupper(playerMove);
            valid =true;
            if ( playerMove != 'U'&& playerMove!='D' && playerMove != 'L' && playerMove!= 'R')
            {
                cin.clear();
                cin.ignore(BIGNUM, '\n');
                cout << "Computer says no please enter U, D, L, or R" << endl;
                valid = false;
            }
            else
            {
                switch (playerMove) //actually checking where we need to move player
                {
                    case 'U':
                        row--;
                        break;
                    case 'D':
                        row++;
                        break;
                    case 'L':
                        col--;
                        break;
                    case 'R':
                        col++;
                        break;
                    default:
                        cout << "something went wrong if you see this message" << endl;
                        break;
                }
                //checking in inbounds
                if ((row>=0 && row<MAX_ROW) && (col>=0 && col<MAX_COL))
                {
                    valid = true;
                }
                else
                {
                    cout<<"Out of bounds"<<endl;
                    valid = false;
                }
            }

            } while (not valid);

    newRow=row;
    newCol = col;
}



//check move is scan the board not remembering where the player is
bool checkMove(char dungeonArray[MAX_ROW][MAX_COL],  int newRow, int newCol)
{

int row = newRow,col= newCol;


//return true if it is not on trap or CASH.
    if (dungeonArray[row][col]!= SPACE)
       {
           return false;
       }

return true;
}

char checkWin(char dungeonArray[MAX_ROW][MAX_COL], int newRow, int newCol)
{
    int row = newRow,col= newCol;

    //Switch for win=CASH and lose=TRAP
    char result = dungeonArray[row][col];

    switch (result)
    {
        case CASH:
            cout << " You landed on the treasure, you won"<<endl;
            break;
        case TRAP:
            cout << "You landed on a trap, you lose"<<endl;
            break;
        default:
            cout << "something went wrong if you see this message" << endl;
            break;
    }

       return result;
}

// shows board and moves the player corrdiants to the new position.
void updateDungeon(char dungeonArray[MAX_ROW][MAX_COL], int&playerRow, int&playerCol,int newRow, int newCol)
{
/*
a) pass in the dungeon and the move
b) update the dungeon moving the player marker (place a new player and clear the old spot)
c) return type should be void
*/

    dungeonArray[playerRow][playerCol]=SPACE;

    dungeonArray[newRow][newCol]= PLAY;

    playerRow=newRow;

    playerCol = newCol;

}

// do you want to play again?
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



