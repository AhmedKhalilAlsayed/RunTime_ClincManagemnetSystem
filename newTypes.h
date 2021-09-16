#ifndef newTypes_h
#define newTypes_h


#include <stdio.h>
#define TEST_TYPES() \
do {\
	printf("u8   = %d \n",sizeof(u8)==1);\
	printf("u16  = %d \n",sizeof(u16)==2);\
	printf("u32  = %d \n",sizeof(u32)==4);\
	printf("s8   = %d \n",sizeof(s8)==1);\
	printf("s16  = %d \n",sizeof(s16)==2);\
	printf("s32  = %d \n",sizeof(u32)==4);\
	printf("f32  = %d \n",sizeof(f32)==4);\
	printf("f64  = %d \n",sizeof(f64)==8);\
	printf("f128 = %d \n",sizeof(f128)==16);\
	} while(0)

#define SET_BIT(VAR,BIT_NUM) VAR|=1<<BIT_NUM

#define CLR_BIT(VAR,BIT_NUM) VAR&=~(1<<BIT_NUM)

#define TOGGLE_BIT(VAR,BIT_NUM) VAR^=1<<BIT_NUM

#define GET_BIT(VAR,BIT_NUM) VAR>>BIT_NUM & 1


	typedef unsigned char u8;		//0 >> 255
	typedef unsigned short int u16;	//0 >> 65,535
	typedef unsigned int u32;		//0 >> 4,294,967,295
	
	typedef signed char s8;
	typedef signed short int s16;
	typedef signed int s32;
	
	typedef float f32;
	typedef double f64;
	typedef long double f128;
	
	
	
	#endif
