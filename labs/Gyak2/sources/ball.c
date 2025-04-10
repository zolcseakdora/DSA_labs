//
// Created by Bence on 4/4/2025.
//

#include "ball.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void create_stack(int capacity, Ball_Stack* stack) {

    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> elements = (Ball*) malloc(capacity*sizeof(Ball));
    stack->num_signed = 0;
    if (!stack->elements) {
        exit(-2);
    }

}

void destroy_stack(Ball_Stack *stack) {
    if (stack) {
        free(stack->elements);
        stack=NULL;
    }
}

void read_balls(Ball_Stack *red, Ball_Stack *white, Ball_Stack *rest) {
    FILE* f = fopen("../input.txt", "r");
    if (!f) {
        printf("File not found\n");
        return;
    }

    int diameter;
    int is_signed;
    char color[21];

    for (int i = 0; i < 20; ++i) {



        if (fscanf(f, "%d", &diameter) != 1) break;
        fgetc(f);
        if (!fgets(color, 20, f)) break;
        trim(color);
        if (fscanf(f, "%d", &is_signed) != 1) break;


        if (strcmp(color, "RED") == 0) {
            if (is_signed) ++red->num_signed;
            push(red, (Ball){diameter, string_to_enum(color), is_signed});
        } else if (strcmp(color, "WHITE") == 0) {
            if (is_signed) ++white->num_signed;
            push(white, (Ball){diameter, string_to_enum(color), is_signed});
        } else {
            if (is_signed) ++rest->num_signed;
            push(rest, (Ball){diameter, string_to_enum(color), is_signed});
        }
    }

    fclose(f);
}



void largest_top(Ball_Stack red, Ball_Stack white, Ball_Stack rest) {

   int red_top,white_top,rest_top;
    red_top = peek(red).diameter;
    white_top = peek(white).diameter;
    rest_top = peek(rest).diameter;

    if (red_top == white_top && white_top == rest_top) {
        printf("Mindhaorm lada tetejen ugyanakkora labda van!\n");
        return;
    }

    if (red_top >= white_top && red_top >= rest_top) {
        printf("A piros lada tetejen van a legnagyobb labda!\n");
    }
    else if (white_top >= red_top && white_top >= rest_top) {
        printf("A feher lada tetejen van a legnagyobb labda!\n");
    }
    else {
        printf("A harmadik lada tetejen van a legnagyobb labda!\n");
    }

}

void print_stack(Ball_Stack stack) {
    if (is_empty(stack)) {
        printf("The stack is empty.\n");
        return;
    }

    printf("Ball Stack:\n");
    for (int i = 0; i <= stack.top; ++i) {
        Ball b = stack.elements[i];
        printf("Ball %d -> Diameter: %d, Color: %s, Signed: %s\n",
               i + 1, b.diameter, enum_to_string(b.color), b.is_signed ? "Yes" : "No");
    }
}

int rm_balls(Ball_Stack *stack) {
    if (is_empty(*stack)) return 0;
    int count = 0;
    while (!is_empty(*stack) && !peek(*stack).is_signed) {
        pop(stack);
        ++count;
    }
    return count;
}


//Helpers
Color string_to_enum(char *str) {
    int len = strlen(str);
    for (int i =0; i<len;++i) {
        if (strcmp(str,color_string[i]) == 0) return i;
    }
    return len-1;
}

char * enum_to_string(Color color) {
    if (color < strlen(color_string) ) return color_string[color];
    return "OTHER";
}
void trim(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') str[len-1] ='\0';
}
bool is_full(Ball_Stack stack) {
    if (stack.top == stack.capacity - 1) {
        return true;
    }
    return false;
}
bool is_empty(Ball_Stack stack) {
    if (stack.top == -1) {
        return true;
    }
    return false;
}
void push(Ball_Stack*stack, Ball item) {
    if (is_full(*stack)) {
        return;
    }
    stack->elements[++(stack->top)] = item;
}

Ball pop(Ball_Stack*stack) {
    if (is_empty(*stack)) {
        return (Ball) {0,7,0};
    }

    return  stack->elements[stack->top--] ;
}

Ball peek(Ball_Stack stack) {
    if (is_empty(stack)) {
        return (Ball) {0,7,0};
    }
    return  stack.elements[stack.top] ;
}
