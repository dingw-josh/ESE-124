#include <stdio.h>
#include "vittualAnt.h"
int main() {
    printf("Hello, World!\n");
    VirtualAnt* ant = (VirtualAnt *) init_VirtualAnt(100);
    printf("%d",ant->MAX_NUMBER_OF_STEPS);
    return 0;
}
