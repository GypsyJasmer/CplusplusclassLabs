#ifndef TTT_H
#define TTT_H


const static char X = 'X';
const static char O = 'O';
class TTT{
private:
    const static int ROW = 3;
    const static int COL = 3;
    const static char SPACE = ' ';
    char board[ROW][COL];
    int numMoves;
public:
    TTT();
    bool getMove(char player);
    void instructions();
    void display();
    bool isWin();
    bool isTie();
};

#endif // TTT_H
