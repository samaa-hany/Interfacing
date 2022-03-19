/*
 * BIT_MATH.h
 *
 *  Created on: Dec 17, 2021
 *      Author: Samaa Seif
 */

#ifndef BIT_MATH_H_  //FIle guard
#define BIT_MATH_H_

#define SET_BIT(REG,BIT) ((REG)|=(1<<BIT))
#define CLR_BIT(REG,BIT) ((REG)&=(~(1<<BIT)))
#define TOG_BIT(REG,BIT) ((REG)^=(1<<BIT))
#define GET_BIT(REG,BIT) ((((REG)>>(BIT))&0x01))
//#define GET_BIT(REG,BIT) (REG) &=(1<<BIT)?1:0)


#endif /* BIT_MATH_H_ */
