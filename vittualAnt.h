//
// Created by theresa🦄 on 2022/5/12.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef ESE_124_VA_H
#define ESE_124_VA_H
typedef struct{
   int* stack;
   int MAX_NUMBER_OF_STEPS;
}VirtualAnt;
VirtualAnt* init_VirtualAnt(int max_num);

#endif //ESE_124_VA_H
