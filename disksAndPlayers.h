#include<stdbool.h>
#define SIZE 8

/* File containing the enums, structs and function prototypes used for:
Initialising players, boards and printing the boards.
possible moves: manageTurns function
flipping disks : playTurns function
Checking the moves: check whether move is true or false
printing the score: print score function
getting the score and printing to file : getScore function
*/


    enum colour{
        WHITE,
        BLACK,
        NONE
    };

    typedef struct position{
        int row;
        int col;
    } position;

	typedef struct possible_moves{

		int x;
		int y;

		//make self referencial structure
		struct possible_moves *node;

	}possible;

    typedef struct disk{
        enum colour type;
        position pos;
    } disk;

    typedef struct player{
        char name[20];
        enum colour type;
        int points;
    } player;

    void initializePlayers(player player1, player player2);

    void initializeBoard(disk board[SIZE][SIZE]);

    void printBoard(disk board [SIZE][SIZE]);

	void instructions();

    int manageTurns(disk board[SIZE][SIZE], enum colour type, int moves[][SIZE]);

    //bool checkMoves(disk board[SIZE][SIZE], enum colour type);

    bool checkMoves(disk board[SIZE][SIZE], enum colour type, int row, int col);

    void playTurn(disk board[SIZE][SIZE], int row, int col, enum colour type);

    void getScore( disk board[SIZE][SIZE], player player1, player player2);

    void printScore(disk board[SIZE][SIZE],player player1, player player2);



