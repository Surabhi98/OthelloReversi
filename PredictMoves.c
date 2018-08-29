#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disksAndPlayers.h"
#include "LinkedLists.h"

/* Function to predict the possible moves for the player :
 A possible move is when we have a NONE space followed by opponent's disk
 followed by our own disk: which forms a desired sequence
  */

int manageTurns(disk board[SIZE][SIZE], enum colour type, int moves[][SIZE]){
    int row_adj = 0;   //To increment row when searching
    int col_adj = 0;   //To increment column when searching
    int row = 0;             //row counter
    int col = 0;             //column counter
    int no_of_moves = 0;    //number of moves
    int pos_1 =0;           //x coordinate for posible position
    int pos_2 =0;          //y coordinate for possible position
    enum colour opponent;  //opponent's disk

//checks for the player type and hence predicts the opponent
     if( type == BLACK ){

        opponent = WHITE;

    } else if( type == WHITE )
    {
        opponent = BLACK;

    }

    //initialising the list position to null
    ListNodePtr position = NULL; //no node initially

    /* Find squares for valid moves.                           */
    /* A valid move is when there is NONE space on the board  */
    /* and a squence is formed terminated by adversary disk */

     /* Initialize moves array to zero */
   for(row = 0; row < SIZE; row++){
     for(col = 0; col < SIZE; col++)
       moves[row][col] = 0;

   }

   //Scans the entire board
    for(row = 0; row < SIZE; row++)
    {
        for(col = 0; col < SIZE; col++)
        {
             //Find the player type
              if( board[row][col].type == type)
              {
                 //9 cases to find the opponent
                  for(row_adj = -1; row_adj <= 1; row_adj++){
                      for(col_adj = -1; col_adj <= 1; col_adj++)
                      {
                           /* Don't check outside the array, or the current square */
                           if(row + row_adj < 0 || row + row_adj >= SIZE ||
                              col + col_adj < 0 || col + col_adj >= SIZE ||
                                                       (row_adj ==0 && col_adj ==0))
                             continue;
                          //Adjusts the rows and columns to find the opponent
                          pos_1 = row + row_adj;
                          pos_2 = col + col_adj;


                         //When opponent is found
                          while(board[pos_1][pos_2].type == opponent)
                          {
                              //Adjusting the positions to find none space
                              pos_1 += row_adj;
                              pos_2 += col_adj;
                              //check the square
                               if(pos_1 < 0 || pos_1 >= SIZE || pos_2 < 0 || pos_2 >= SIZE)
                               {
                                break;
                               }

                               if(board[pos_1][pos_2].type ==  NONE )
                               {
                               //when the none space is found we insert the possible positions in the list
                               insert( &position, pos_1, pos_2);
                               //print the list of possible positons
                               printList(position);
                               //free the node to make it work for player 2
                               delete( &position );

                               moves[row][col] = 1;   //hence mark the position as valid
                               no_of_moves++;         //thereby increments the moves counter


                             } else{

                             break; //breaks the loop

                             }



                           }



                      }



                  }



            }


        }



    }


    return no_of_moves; //returns the number of moves



}


