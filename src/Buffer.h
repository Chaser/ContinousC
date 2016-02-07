#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>

#define BUFFER_SIZE 1000
#define BUFFER_ERROR_EMPTY   1
#define BUFFER_ERROR_FULL    2


int Buffer_Put(uint16_t);

int Buffer_Get(uint16_t *);


#endif //BUFFER_H