/* ENCE260 Embedded Systems Assignment
 * Team138 - David Bredda & Aiman Hazashah
 * 16/10/17
 */

#ifndef DISPLAYWINLOSS_H
#define DISPLAYWINLOSS_H

#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "button.h"

void lose_display(void);

void draw_display(void);

void win_display(void);

void displayWinLoss(int winLoss);

#endif
