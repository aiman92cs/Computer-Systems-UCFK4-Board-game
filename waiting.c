/* ENCE260 Embedded Systems Assignment
 * Team138 - David Bredda & Aiman Hazashah - 16/10/17
 * The waiting module controls all IR communication theoughout the game.
 * Consists of 2 parts; ensuring players are ready, and exchanging symbols
 */
 

#include "waiting.h"

#define TRUE 1
#define FALSE 0
#define READY 'Y'
#define ACK 'A'
#define PACER_RATE 300
#define PAPER 'P'
#define SCISSORS 'S'
#define ROCK 'R'

#define BUTTON_INDEX 0

/* To display a smiley face during the waiting phase */
void waitingWaitDisplay(void)
{
    tinygl_clear();
    tinygl_draw_box(tinygl_point(1,5), tinygl_point(3,3), TRUE);
    tinygl_pixel_set(tinygl_point(1,1), TRUE);
    tinygl_pixel_set(tinygl_point(3,1), TRUE);
}

/* Initialize both UCFK set before the selection phase */
void waitingWait(void)
{
    system_init();
    ir_uart_init();
    led_init();
    led_set(LED1, FALSE);
    pacer_init(PACER_RATE);
    uint16_t nextStage = FALSE; //determine if the UCFK's have been Initialized
    tinygl_init(PACER_RATE);
    button_init();

     while (nextStage == FALSE)
    {
        tinygl_update();
        waitingWaitDisplay();
        pacer_wait(); 
        if (ir_uart_read_ready_p()) {
            if (ir_uart_getc() == READY) {
                playerNum = 2;
                ir_uart_putc(ACK);
                nextStage = TRUE;
            }
        }
        button_update();
        if (button_push_event_p(BUTTON_INDEX)) {
            playerNum = 1;
            led_set(LED1, TRUE);
            ir_uart_putc(READY);
             while (ir_uart_getc() != ACK) {
                 ir_uart_putc(READY);
            }
            nextStage = TRUE;
        }
    }
    
}
/* Determine the Symbol of the opponent Choice and return the value */
int waitingComparison(char symbolChoice)
{
    system_init();
    ir_uart_init();
    pacer_init(PACER_RATE);
    
    uint16_t nextStage = FALSE; //determine if the process of sending and receiving had been completed


    if (playerNum == 2){
        symbolChoice = tolower(symbolChoice); //change the Symbol to lower case
    }
    char opponentChoice = symbolChoice; //Initialized the Opponent Choice 
    
    
    while (nextStage == FALSE)
    {
        pacer_wait();
        /* Receive IR from the Opponent */
        if (ir_uart_read_ready_p()) { 
            opponentChoice = ir_uart_getc(); //Get the Opponent choice
            if (opponentChoice != symbolChoice) { 
                ir_uart_putc(symbolChoice);
                nextStage = TRUE;
            }
        }
        button_update();
        /* Send the IR to the Opponent */
        if (button_push_event_p(BUTTON_INDEX)) {
            ir_uart_putc(symbolChoice);
            opponentChoice = ir_uart_getc();
             while (opponentChoice == symbolChoice) {
                 ir_uart_putc(symbolChoice);
                 pacer_wait();
                 opponentChoice = ir_uart_getc();
            }
            nextStage = TRUE;
        }
    }
    return comparison(symbolChoice,opponentChoice);
}

