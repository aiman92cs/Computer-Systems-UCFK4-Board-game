/* ENCE260 Embedded Systems Assignment
 * Team138 - David Bredda & Aiman Hazashah - 16/10/17
 * This display module displayes wehter each player has won or lost (or drew)
 * on their respective screens. This module progresses on a button press
 */

#include "displayWinLoss.h"

#define PACER_RATE 300
#define MESSAGE_RATE 10
#define LOOP_RATE 350
#define TRUE 1
#define FALSE 0
#define BUTTON_INDEX 0

/* 0 means LOST
 * 1 means DRAW
 * 2 means WIN
 */

uint16_t nextStage = FALSE;

/* Display is the user lose */
void loseDisplay(void)
{
    //displays loss and waits until the button is pressed to continue
    tinygl_text("LOSE");
    while (nextStage == FALSE) {
        pacer_wait();
        tinygl_update();
        button_update();
        if (button_push_event_p(BUTTON_INDEX)) {
            nextStage = TRUE;
        }
    }
}

/* Display is the user draw */
void drawDisplay(void)
{
    //displays draw and waits until the button is pressed to continue
    tinygl_text("DRAW");
    while (nextStage == FALSE) {
        pacer_wait();
        tinygl_update();
        button_update();
        if (button_push_event_p(BUTTON_INDEX)) {
            nextStage = TRUE;
        }
    }
}
/* Display is the user win */
void winDisplay(void)
{
    //displays win and waits until the button is pressed to continue
    tinygl_text ("WIN");
    while (nextStage == FALSE) {
        pacer_wait();
        tinygl_update();
        button_update();
        if (button_push_event_p(BUTTON_INDEX)) {
            nextStage = TRUE;
        }
    }
}

/* Compare both value and determine the results */
void displayWinLoss(int winLoss)
{
    system_init();
    tinygl_init(LOOP_RATE);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    pacer_init(PACER_RATE);

    while (nextStage == FALSE) {
        if(winLoss == 0) {
            loseDisplay();
        } else if(winLoss == 1) {
            drawDisplay();
        } else if(winLoss == 2) {
            winDisplay();
        }
    }
}
