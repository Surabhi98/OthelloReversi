/* Othello Reversi Game written by:
Surabhi Agarwal : 17203535
Lorand Neculae  : 17720105
*/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "disksAndPlayers.h"
#include "LinkedLists.h"
#include<stdlib.h>

int main()
{
    // Variables declaration

    player player1= {"player1", NONE,0};
    player player2= {"player2", NONE,0};
    disk board[SIZE][SIZE];
    int moves[SIZE][SIZE] = { 0 };    //valid moves
    int no_of_moves = 0;              //counter for total moves
    int play1 = 0;                    //counter for turn management
    int choice;                       //choice to play or not
    int x=0;                          //position for row
    int y=0;                          //position for column
	bool gamePlay = false;            //initialising game play to zero



    instructions(); //displays the instructions

    scanf("%d",&choice);
    getchar();
    initializePlayers(player1, player2); //initialises the both players

    while(choice != 0)
  {

    no_of_moves = 4;  //initially we have number of moves as 4
    initializeBoard(board);
    play1 = 0; //turn management counter is zero initially


      do{

        printBoard(board); //prints the board for the first time

        //FOR PLAYER 1 TURN
        if( play1%2 == 0)
        {
         player1.type = BLACK;
         //Calls the function to print the possible moves
         manageTurns(board, player1.type,moves);


        //asks the user to input the move
         printf("\nPlease enter your move :");
         scanf("%d%d", &x, &y);

         //plays the turn for black
        if(checkMoves(board, player1.type, x, y)){

         playTurn(board, x, y, player1.type);
         //prints the board
         printBoard(board);
         play1++; //increments the counter to move to player two
          no_of_moves++;              //increments the number of moves
          moves[x][y] = 1;


      }
        else
               printf("Not a valid move, try again.\n");
        }

      //FOR PLAYER 2 TURN
       if(play1%2 == 1)
        {
            player2.type = WHITE;
            //Calls the function to print the possible positions for player 2
            manageTurns(board,player2.type,moves);

            //Asks for user input
            printf("\nPlease enter your move :");
            scanf("%d%d", &x, &y);
            //Plays the turn for white
            if(checkMoves(board, player2.type, x, y))
           {

             playTurn(board, x, y, player2.type);
             no_of_moves++;   //increments the move count
             play1++;
             moves[x][y] = 1;

        }
            else
               printf("Not a valid move, try again.\n");

       }

      if(no_of_moves == 64)
      {
        gamePlay = true;
        getScore(board, player1, player2);
        printScore(board, player1, player2);

        break;

      }



 }while(x>=0 && y>=0 && x< SIZE && y< SIZE && (moves[x][y] != 0) ); //terminating condition

 printf("GAME OVER!!! FINAL BOARD:");
 printBoard(board);
 printf("\n");
 getScore(board, player1, player2);
 printScore(board, player1, player2);

 printf("Do you want to play again?\n");
        printf("1: Play again \n");
        printf("0: Exit \n");
        scanf("%d",&choice);
        getchar();

}



}






