//
// Created by Bence on 4/4/2025.
//

#ifndef BALL_H
#define BALL_H
#define Nr_Balls = 20
#define Nr_Colors = 8
typedef enum{RED,WHITE,BLACK,YELLOW,GREEN,ORANGE,PURPLE,OTHER } Color;
static const char color_string[8][20] = {"RED","WHITE","BLACK","YELLOW", "GREEN","ORANGE","PURPLE","OTHER"};
typedef struct {
    int diameter;
    Color color;
    bool is_signed;
}Ball;

typedef struct {
    int top,capacity, num_signed;
    Ball* elements;

}Ball_Stack;

//functions
void create_stack(int capacity, Ball_Stack* stack);
void destroy_stack(Ball_Stack *stack);
void read_balls(Ball_Stack* red, Ball_Stack* white, Ball_Stack* rest);
void largest_top(Ball_Stack red, Ball_Stack white, Ball_Stack rest);
void print_stack(Ball_Stack stack);
int rm_balls(Ball_Stack *stack);

//HELPERS
Color string_to_enum(char* str);
char* enum_to_string(Color color);
void trim(char *str);
bool is_full(Ball_Stack stack);
bool is_empty(Ball_Stack stack);
void push(Ball_Stack*stack, Ball item);
Ball pop(Ball_Stack* stack);
Ball peek(Ball_Stack stack);

#endif //BALL_H
