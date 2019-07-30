/* ENCE260 Embedded Systems Assignment
 * Team138 - David Bredda & Aiman Hazashah - 16/10/17
 * The start screen module displays a scrolling meaage to welcome players
 * and waits for a button push to advance to the next mosule (through game.c)
 */
 
#include "startScreen.h"

#define PACER_RATE 300
#define MESSAGE_RATE 10
#define LOOP_RATE 350
#define BUTTON_INDEX 0
#define TRUE 1
#define FALSE 0

/* Display the opening text when starting the game*/
void startScreenDisplay(void)
{
    system_init();
    button_init();
    pacer_init(PACER_RATE);

    tinygl_init(LOOP_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    
    tinygl_text("PSR: START?"); //Display text on the starting screen
    
    uint16_t nextStage = FALSE; 
    /*User must press the R13 button to continue to the next phase */
    while (nextStage == FALSE) 
    {
        pacer_wait();
        tinygl_update();
        button_update();
        if (button_push_event_p(BUTTON_INDEX)) { 
            tinygl_clear();
            nextStage = TRUE;
        }
    }
    tinygl_update();
}
