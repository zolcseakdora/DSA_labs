#include <stdio.h>

#include "balls.h"

int main(void) {
    printf("Hello, World!\n");
    Ball_Queue* black, *white;
    black = create_queue(20);
   white = create_queue(20);

    read_balls(black,white);
    printf("Black:\n");
    display(black);
    printf("White:\n");
    display(white);
    printf("%d db szines labda a fekete polcon\n",black->nr_colored_balls);
    printf("%d db szines labda a feher polcon\n",white->nr_colored_balls);
    Ball_Queue* colored = create_queue(20);
    select_colored(black,white,colored);
    printf("Colored:\n");
    display(colored);
    destroy_queue(&black);
    destroy_queue(&white);
    destroy_queue(&colored);
    return 0;
}
