#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disksAndPlayers.h"

/* Function to flip the opponent's disk to our own coloured disk if
 we have a valid move from the list of possible positons.
This is only possible if :
Criteria of a valid move is satisfied i.e player is able to play if and only if the move is valid.
If the player plays it's turn ; all the diks in the row are flipped to it's OWN colour.

*/
void playTurn(disk board[SIZE][SIZE], int row, int col, enum colour type)
{
    int row_adj = 0;                //To increment the row when searching
    int col_adj = 0;                //To increment the column when searching
    int pos_1 = 0;                  //Valid position for row
    int pos_2 = 0;                  //Valid position for column

    enum colour opponent;          //Adversary disk
  //checks for the player type and hence predicts the opponent

   if(type == BLACK)
   {
      opponent = WHITE;

   } else if( type == WHITE){

      opponent = BLACK;
   }

   //Assigns the space for valid move to the player's disk type
    board[row][col].type = type;

  // Find squares for the opponent's disk


    for(row_adj = -1; row_adj <= 1; row_adj++){
        for(col_adj = -1; col_adj <= 1; col_adj++)
        {
           /* Don't check off the board, or the current square */
            if(row + row_adj  < 0 || row + row_adj >= SIZE ||
                  col + col_adj < 0 || col + col_adj >= SIZE ||
                                       (row_adj ==0 && col_adj == 0))
                 continue;
                pos_1 = row + row_adj;
                pos_2 = col + col_adj;


           //If the opponent is found; we adjust positions to find the player's disk
           //To ensure that we have a valid move
            /* A valid move is when there is NONE space on the board  */
             /* and a squence is formed terminated by adversary disk */
            if(board[pos_1][pos_2].type == opponent)
            {
                 pos_1 += row_adj;
                 pos_2 += col_adj;

                 /* If we are off the board give up */
                   if(pos_1 < 0 || pos_1 >= SIZE || pos_2< 0 || pos_2 >= SIZE)
                     break;


                     //Now that we have ensured that condition
                    if(board[pos_1][pos_2].type == type)
                   {
                       //We go back and search for opponent's disk
                        pos_1 -= row_adj;
                        pos_2 -= col_adj;
                        //After opponents disk is found, we flip the disk
                        if(board[pos_1][pos_2].type == opponent){
                            board[pos_1][pos_2].type = type;


                    }

               }

            }

        }

    }


}


