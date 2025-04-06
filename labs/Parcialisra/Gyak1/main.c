#include <stdio.h>
#include<stdlib.h>
#include "labdak.h"

int main(void) {
    printf("Hello, World!\n");
   Ball_Array *balls = create_ball_array(20);
    read_balls(balls);
    print_balls(balls);
    rm_selected_diameter(balls,15);
    print_balls(balls);
    printf("%d balls are signed!\n",signed_balls(balls));
    sort_by_diameter(balls);
    print_balls(balls);
    deallocate_ball_array(&balls);

    return 0;
}