#include <stdio.h>
#include "array.h"
int main(void) {
    LabdaArray labda;
    createArray(20,&labda);
    readOsszesLabda(&labda);
    printOsszesLabda(&labda);
    labda_torol(&labda);
    szamol_alairt(labda);
    qsort(labda.elements,labda.size,sizeof(Labda),compare);
    printOsszesLabda(&labda);
    return 0;
}
