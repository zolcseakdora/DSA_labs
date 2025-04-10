#include <stdio.h>

#include "sources/ball.h"

int main(void) {
    printf("Hello, World!\n");
    Ball_queue* white, *black;
    white = create_queue(20);
    black = create_queue(20);
    //printf("%d\n",is_empty(white));
    read_balls(white,black);
    printf("White:\n");
    display(white);
    printf("Black:\n");
    display(black);
    printf("%d szines labda a feher polcon\n",white->num_colored);
    printf("%d szines labda a fekete polcon\n",black->num_colored);
    Ball_queue* rest = create_queue(20);
    select_balls(white,black,rest);
    printf("Colored balls:\n");
    display(rest);
    destroy_queue(&white);
    destroy_queue(&black);
    destroy_queue(&rest);
    return 0;
}
