#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disksAndPlayers.h"

/* Function used for getting the score and printing it to text files
As well as displaying the score when the game ends */

void getScore( disk board[SIZE][SIZE], player player1, player player2)
{

    FILE *fptr;

    fptr = fopen("OthelloReversiScore.txt", "a");

    if( fptr != NULL)
    {

    int row;
    int col;

    for(row = 1; row <= SIZE; row++)
    {
        for(col = 1; col <=SIZE; col++)
        {

            if(board[row][col].type == player1.type)
            {
                player1.points++; //FOR PLAYER 1

            }

            else if(board[row][col].type == player2.type)
            {
                player2.points++;  //FOR PLAYER 2

            }



        }
    }

   //To predict who won or lost the game
    if(player1.points > player2.points)
        {
            fprintf(fptr,"Winner:%s; Points:%d\n",player1.name,player1.points);
            fprintf(fptr,"Loser:%s; Points:%d\n\n",player2.name,player2.points);

        }
        else if(player1.points < player2.points)
        {
            fprintf(fptr,"Winner:%s; Points:%d\n",player2.name,player2.points);
            fprintf(fptr,"Loser:%s; Points:%d\n\n",player1.name,player1.points);
        }
        else{
                fprintf(fptr,"Tie\n\n");

         }
    }


         fclose(fptr);
}


//To print the result on the console
void printScore(disk board[SIZE][SIZE],player player1, player player2)
{
    int row;
    int col;

    for(row = 1; row <= SIZE; row++)
    {
        for(col = 1; col <=SIZE; col++)
        {
            if(board[row][col].type == player1.type)
            {
                player1.points++;

            }

            else if(board[row][col].type == player2.type)
            {
                player2.points++;

            }
        }
    }
    if(player1.points > player2.points)
        printf("YOU WON : %s with POINTS: %d\n",player1.name, player1.points);
    else if(player1.points < player2.points)
       printf("YOU WON : %s with POINTS: %d\n",player2.name, player2.points);
    else
        printf("Tie\n");
}






