#include "Buffer.h"
#include "MK20DX256.h"

#define ACTUAL_BUFFER_SIZE  (BUFFER_SIZE + 1)

uint16_t Buffer[ACTUAL_BUFFER_SIZE];
uint16_t ReadIndex = 0;
uint16_t WriteIndex = 0;


int Buffer_Put(uint16_t Val)
{
	uint16_t NextWriteIndex = (WriteIndex + 1) % ACTUAL_BUFFER_SIZE;
	if (NextWriteIndex == ReadIndex)
		return BUFFER_ERROR_FULL;

	Buffer[WriteIndex] = Val;
	WriteIndex = (WriteIndex + 1) % ACTUAL_BUFFER_SIZE;
	return 0;
}


int Buffer_Get(uint16_t *Val)
{
	if(ReadIndex == WriteIndex)
		return BUFFER_ERROR_EMPTY;

	*Val = Buffer[ReadIndex];
	ReadIndex = (ReadIndex + 1) % ACTUAL_BUFFER_SIZE;
	return 0;	
}


/*
0		1 		2		3		4   
R             
W0		W1		W2		W3      
*/

