/* ENCE260 Embedded Systems Assignment
 * Team138 - David Bredda & Aiman Hazashah - 16/10/17
 * The comnparison module takes the 2 players' symbols and decides which
 * player is the winner. This is then returned to later display the result
 */

#include "comparison.h"

#define LOST 0
#define DRAW 1
#define WIN 2

#define PAPER 'P'
#define SCISSORS 'S'
#define ROCK 'R' 

/* Compare both value and determine the results */
int comparison(char ourChoice, char opponentChoice)
{
    ourChoice = toupper(ourChoice);
    opponentChoice = toupper(opponentChoice);
    
    //if both have same symbol
    if(ourChoice == opponentChoice){
        return DRAW;
    }
    
    //ROCK
    if(ourChoice == ROCK){
        if(opponentChoice == SCISSORS){
            return WIN;
        }
        else if (opponentChoice == PAPER){
            return LOST;
        }
    }
    //PAPER
    if(ourChoice == PAPER){
        if(opponentChoice == ROCK){
            return WIN;
        }
        else if (opponentChoice == SCISSORS){
            return LOST;
        }
    }
    //SCISSORS
    if(ourChoice == SCISSORS){
        if(opponentChoice == PAPER){
            return WIN;
        }
        else if (opponentChoice == ROCK){
            return LOST;
        }
    }
    return 0;
}
