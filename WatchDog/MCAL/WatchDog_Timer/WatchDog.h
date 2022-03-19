/*
 * WatchDog.h
 *
 *  Created on: Jan 9, 2022
 *      Author: Samaa Seif
 */

#ifndef WATCHDOG_H_
#define WATCHDOG_H_

void WDG_Enable(void);
void WDG_Disable(void);
void WDG_Refresh(void);

#define W0  0
#define W1  1
#define W2  2
#define W3  3
#define W4  4

#endif /* WATCHDOG_H_ */
