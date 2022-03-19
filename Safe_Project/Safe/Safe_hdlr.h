/*
 * Safe_hdlr.h
 *
 *  Created on: Jan 5, 2022
 *      Author: Samaa Seif
 */

#ifndef SAFE_HDLR_H_
#define SAFE_HDLR_H_

typedef enum {
	New_passward=0,
	Safe_opened,
	Safe_closed,
	Old_passward,
	Your_passward,
	HARAMY,
	ADMIN
}Safe_STATE;

extern void Enter_New_Pass(void);
extern void Confirm_Pass(void);
extern void Confirm_Old_Pass(void);
extern void Welcome(void);
extern void Safe_Opened(void);
extern void Safe_Closed(void);
extern void Enter_Old_Pass(void);
extern void Call_Admin(void);
extern void Haramy(void) ;
extern uint8 Password_Data(void) ;
extern void Close(void);
extern void ENT_HARAMY(void);
extern void Confirmation(uint8 sum1, uint8 sum2);
extern void Call_Admin_Pass(void);

#endif /* SAFE_HDLR_H_ */
