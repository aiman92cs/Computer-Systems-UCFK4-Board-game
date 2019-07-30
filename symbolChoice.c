/* ENCE260 Embedded Systems Assignment
 * Team138 - David Bredda & Aiman Hazashah - 16/10/17
 * Symbol choice module allows players to choose their symbol, then
 * records this and returns it for later sending and comparison
 */

#include "symbolChoice.h"


#define TRUE 1
#define FALSE 0
#define PACER_RATE 300
#define PAPER 'P'
#define SCISSORS 'S'
#define ROCK 'R'


char symbol = PAPER; //Initialize the symbol choice for player, we choose Paper as the starting choice 

/* Display the choice the user can pick */
void symbolChoiceDisplay(void)
{   //Paper
    if (symbol == PAPER) {
        tinygl_clear();
        tinygl_draw_box(tinygl_point(0,0), tinygl_point(4,6), TRUE);
        tinygl_draw_box(tinygl_point(2,4), tinygl_point(3,5), TRUE);
        tinygl_pixel_set(tinygl_point(3,6), FALSE);
        tinygl_pixel_set(tinygl_point(4,6), FALSE);
        tinygl_pixel_set(tinygl_point(4,5), FALSE);
    }
    //Scissors
    else if (symbol == SCISSORS) {
        tinygl_clear();
        tinygl_draw_box(tinygl_point(0,4), tinygl_point(1,5), TRUE);
        tinygl_draw_box(tinygl_point(3,4), tinygl_point(4,5), TRUE);
        tinygl_draw_line(tinygl_point(1,3), tinygl_point(4,0), TRUE);
        tinygl_draw_line(tinygl_point(0,0), tinygl_point(3,3), TRUE);
    }
    //Rock
    else if (symbol == ROCK) {
        tinygl_clear();
        tinygl_draw_box(tinygl_point(0,3), tinygl_point(4,5), TRUE);
        tinygl_draw_line(tinygl_point(1,4), tinygl_point(3,4), TRUE);
        tinygl_draw_line(tinygl_point(1,2), tinygl_point(3,2), TRUE);
        tinygl_pixel_set(tinygl_point(2,1), TRUE);
    }
}

/* Determines the Symbol chosen by the player and saves it */
char symbolChoiceChoose(void)
{
    system_init();
    tinygl_init(PACER_RATE);
    navswitch_init();
    pacer_init(PACER_RATE);
    
    uint16_t nextStage = FALSE;

    while (nextStage == FALSE)
    {
        tinygl_update();
        navswitch_update();
        /* Scroll to the left */
        if (navswitch_push_event_p(NAVSWITCH_EAST)){
            if (symbol == PAPER) {
                symbol = SCISSORS;
            } else if (symbol == SCISSORS) {
                symbol = ROCK;
            } else {
                symbol = PAPER;
            }
        }       
        /* Scroll to the right */
        if (navswitch_push_event_p(NAVSWITCH_WEST)) {
            if (symbol == PAPER) {
                symbol = ROCK;
            } else if (symbol == SCISSORS) {
                symbol = PAPER;
            } else {
                symbol = SCISSORS;
            }
        }
        /* Push button to save the choice */
        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            tinygl_clear();
            tinygl_update();
            return symbol;
        }
        
        symbolChoiceDisplay(); //Display the symbol choice
        pacer_wait();
    }
    return 0;
}
