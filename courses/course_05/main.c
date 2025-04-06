#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(void) {
    Stack_t stack;
    createStack(20,&stack);
    if(!freopen("szamsor.txt","r",stdin))
    {
        printf("File not found");
        exit (-2);
    };
    int x;
    while(scanf("%i",&x) != EOF)
    {
        if(isEmpty(stack)){
            push(x, &stack);
            }
        else
        {
            while(peek(stack)<x && !isEmpty(stack))
            {
                pop(&stack);
            }
            push(x,&stack);
        }
    }
    printf("%i", size(stack));

    const char *filename = "stack_data.txt"; // Fájl neve, amiből beolvassuk az adatokat
    int capacity = 10;  // A verem maximális kapacitása

    // Verem létrehozása
    createStack(capacity, &stack);

    // Verem adatainak betöltése fájlból
    loadStackFromFile(&stack, filename);

    // Verem tartalmának kiírása (pop művelet végrehajtása)
    printf("Stack contents after loading from file:\n");
    while (!isEmpty(stack)) {
        printf("%d\n", pop(&stack)); // Pop és kiírás
    }

    // Verem felszabadítása
    destroyStack(&stack);

    return 0;
}
