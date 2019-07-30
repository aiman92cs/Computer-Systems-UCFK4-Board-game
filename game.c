/* ENCE260 Embedded Systems Assignment
 * Team138 - David Bredda & Aiman Hazashah - 16/10/17
 * This game.c file is the highest level module and runs the overall game,
 * making calls to otehr modules as the game runs
 */

#include "system.h"
#include "startScreen.h"
#include "waiting.h"
#include "symbolChoice.h"
#include "comparison.h"
#include "displayWinLoss.h"
#include "button.h"

#define BUTTON_INDEX 0
#define PACER_RATE 300

int main(void)
{
    system_init();
    button_init();
    char symbolChoice; //User Choice selection
    int winLoss = 0; //Determine the results of the match. LOSE = 0, DRAW = 1, WIN = 2 
 
    while (1)
    {
        startScreenDisplay(); //Display start screen display
        waiting_wait();  //initialize connection between two UCFK
        symbolChoice = symbolChoice_Choose(); //symbol choice options
        winLoss = waiting_comparison(symbolChoice);   //comparison wait
        displayWinLoss(winLoss);  //Display results
        button_update();
    }
    return 0;
}
