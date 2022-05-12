//
// Created by theresa🦄 on 2022/5/12.
//

#include "vittualAnt.h"
VirtualAnt* init_VirtualAnt(int max_num)
{
    VirtualAnt* va = (VirtualAnt*)malloc(sizeof(VirtualAnt));
    int steps[max_num];
    va->MAX_NUMBER_OF_STEPS = max_num;
    va->stack = &steps[0];
    return va;
}