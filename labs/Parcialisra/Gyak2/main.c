
#include <stdio.h>

#include "ball.h"

int main(void) {
    printf("Hello, World!\n");
    Ball_Stack *red,*white,*rest;
    red = create_stack(20);
    white = create_stack(20);
    rest = create_stack(20);

    read_balls(red,white,rest);
    printf("%d red balls are signed\n",red->num_signed);
    printf("%d white balls are signed\n",white->num_signed);
    printf("%d other balls are signed\n",rest->num_signed);

    largest_top(red,white,rest);

    int count_red,count_white,count_rest;
    count_red = rm_balls(red);
    count_white =rm_balls(white);
    count_rest = rm_balls(white);

    printf("A piros ladabol %d labdat vettunk ki es %d labda maradt benne\n",count_red, red->top);
    printf("A feher ladabol %d labdat vettunk ki es %d labda maradt benne\n",count_white, white->top);
    printf("A harmadik ladabol %d labdat vettunk ki es %d labda maradt benne\n",count_rest, rest->top);

    destroy_stack(&red);
    destroy_stack(&white);
    destroy_stack(&rest);
    return 0;
}
