/* ENCE260 Embedded Systems Assignment
 * Team138 - David Bredda & Aiman Hazashah
 * 16/10/17
 */

#ifndef WAITING_H
#define WAITING_H

#include "system.h"
#include "ir_uart.h"
#include "led.h"
#include "tinygl.h"
#include "navswitch.h"
#include "pacer.h"
#include "comparison.h"
#include "button.h"
#include <ctype.h>

void waiting_wait(void);

void loading_display(void);

int waiting_comparison(char symbolChoice);
int playerNum;

#endif
