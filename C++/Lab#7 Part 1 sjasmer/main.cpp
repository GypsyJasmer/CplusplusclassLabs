#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;

const long BIGNUM = numeric_limits <streamsize>::max();


//function parameters are listed below main
void RPS();
void RSPdisplayInstructions();
int RPSgetPlayerMove();
int RPSgetCompMove();
bool playAgain();
int chooseGame();
void GuessNum();
void numInstructions();
int getNumber();
int getMove();

int main()
{

//initialize random seed based off time
    srand(time(0));



        int choice = chooseGame();
        switch(choice)
        {
            case 1:
                RPS();
                break;
            case 2:
                GuessNum();
                break;
            default:
                cout<<"Pick a game"<<endl;
        }


    return 0;
}

//Rock paper scissors game play that calls RPS functions.
void RPS()
{
    RSPdisplayInstructions();

    const string name[4] = {" ", "rock", "paper", "scissors"};

    do //winner after moves are captured
    {
        RSPdisplayInstructions();
        int computerChoice = RPSgetCompMove();
        int playerChoice = RPSgetPlayerMove();


        if (computerChoice==playerChoice)
        {
            cout<<"I chose " << name[computerChoice]
                <<" too, so we tied." << endl;
        }
        else if ((playerChoice==1 && computerChoice==2) ||
                 (playerChoice==2 && computerChoice==3) ||
                 (playerChoice==3 && computerChoice==1))
        {
            cout << " I choose " <<name[computerChoice]<<" , so I win!"
                << name[playerChoice]<<endl;

        }
        else
        {
            cout << "I chose " << name[computerChoice]<< " , so you win! "
                << name[playerChoice]<< " beats "
                << name[computerChoice]<< endl;

    }}while(playAgain());
}

//first time displays instructions times played after display getting into the game.
void RSPdisplayInstructions()
{
    static bool first = true;
    if(first)
        {cout<< "We're going to play Rock, Paper, Scissors "<<
            "You will be playing with a computer and entering 1 for rock, 2 for paper, or 3 for scissors "<<
            "Let's get going"<< endl;
        }
    else
        cout << "You know how to play Rock Paper Scissors, get going"<< endl;
    first=false;
}

//player move
int RPSgetPlayerMove()
{
    bool valid = true;
    int  playerChoice;


        //data validation of player's choice
        do {
            cin >>playerChoice;
            valid =true;
            if (cin.fail() || playerChoice!=1 && playerChoice!=2 && playerChoice!=3 )
            {
                cin.clear();
                cin.ignore(BIGNUM, '\n');
                cout << "Computer says no, please pick 1, 2, or 3" << endl;
                valid = false;
            }
            } while (not valid);


    return playerChoice;
}

//computer move
int RPSgetCompMove()
{
    int computerChoice;

        //comp choice/random number
    computerChoice = 1+rand()%3;

    return computerChoice;
}

//only true or false so will be a bool function
bool playAgain()
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

//Choose Game is the function in main that sets off choice of game.
int chooseGame()
{
    bool valid = true;
    int choice;


    cout << "Enter 1 for Rock Paper Scissors or 2 for Guessing Number Game" <<endl;

        //data validation (outlined)
        do {
            cin >>choice;
            valid =true;
            if (cin.fail() || (choice !=1 && choice !=2))
            {
                cin.clear();
                cin.ignore(BIGNUM, '\n');
                cout << "Computer says no" << endl;
                valid = false;
            }
    } while (not valid);
    return choice;
}

//Guess Number game that calls all functions related to Guess Num game.
void GuessNum()
{
    numInstructions();
    int randomNumber = getNumber();
    int tries=0, guess;

  do {
  tries++;
  guess=getMove();

        if (guess < randomNumber)
            cout << " Your guess is lower than the secret number"<<endl;
        else if (guess > randomNumber)
            cout << "Your guess is higher than the secret number"<< endl;
        else
            cout<< "Correct guess! Your got it in " << tries<< " guess!"<<endl;

  }while (guess != randomNumber);

   playAgain();

}

//Number game instructions used the same outline as RPS w/ static bool.
void numInstructions()
{
    static bool first = true;
    if(first)
        cout<< "Guess Number Game! You'll pick a number between 1 - 99 "<<
            "You'll play until you pick the correct number and then you can play again if you want "<<endl;
    else
        cout << "You know what to do start guessing"<< endl;
    first=false;

}
//Generates random secret number
int getNumber()
{
    int randomNumber;

//Generating random integers between 1-99
    randomNumber=rand()%99+1;

return randomNumber;
}
//gets the guess of the player and lets them know if it is too high or low and how many guesses they took to get the correct #
int getMove()
{

    bool valid = true;
    int guess;


    cout<< "Guess a number between 1 - 99 "<<endl;

        //data validation (outlined)
        do {
            cin >>guess;
            valid =true;
            if (cin.fail() || guess<1 || guess>99)
            {
                cin.clear();
                cin.ignore(BIGNUM, '\n');
                cout << "Computer says no" << endl;
                valid = false;
            }
            } while (not valid);
return guess;

}
