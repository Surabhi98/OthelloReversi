#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "disksAndPlayers.h"

/* Function of type boolean: exactly like function for possible moves but this one returns a boolean
 value; used for ending the game */


bool checkMoves(disk board[SIZE][SIZE], enum colour type, int row, int col)
{
    int row_adj = 0;   //To increment row when searching
    int col_adj = 0;   //To increment column when searching
    int pos_1 =0;           //valid position row
    int pos_2 =0;           //valid positon column
    bool found = false;     //valid posn found
    enum colour opponent;
 //checks for the player type and hence predicts the opponent
     if( type == BLACK ){

         opponent = WHITE;

    } else if(type == WHITE)
    {
        opponent = BLACK;

    }


     /* Find squares for valid moves.                           */
    /* A valid move is when there is NONE space on the board  */
    /* and a squence is formed terminated by adversary disk */

     /* Initialize moves array to zero */


             //Checks if none
              if( board[row][col].type == NONE)
              {
                 //9 cases to find the opponent
                  for(row_adj = -1; row_adj <= 1; row_adj++){
                      for(col_adj = -1; col_adj <= 1; col_adj++)
                      {
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
                              if(board[pos_1][pos_2].type ==  type )
                              {
                               //when the none space is found we insert the possible positions in the list
                                  found = true;
                              }



                           }



                        }



                    }



                }








      return found;



    }








