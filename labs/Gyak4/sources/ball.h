//
// Created by Bence on 4/5/2025.
//

#ifndef BALL_H
#define BALL_H
#define NR_BALLS 20
#define NR_COLORS 9
typedef enum {RED,WHITE,BLACK,BLUE,GREEN ,YELLOW,PURPLE,ORANGE,OTHER} Color;
static char color_string [NR_COLORS][15] = {"RED","WHITE","BLACK","BLUE","GREEN", "YELLOW","PURPLE","ORANGE","OTHER"};

typedef struct {
    int diameter, is_signed;
    Color color;
}Ball;

typedef struct {
    int front,rear, capacity;
    Ball *elements;
    int num_colored;
}Ball_queue;

Ball_queue* create_queue(int capacity);
void destroy_queue(Ball_queue **queue);
void read_balls(Ball_queue* white, Ball_queue* black);
void select_balls(Ball_queue* white, Ball_queue* black, Ball_queue* rest);
//helpers
char* enum_to_string(Color color);
Color string_to_enum(char* str);
void trim(char* str);
bool is_empty(const Ball_queue* queue);
bool is_full( const Ball_queue *queue);
void enqueue( Ball_queue *queue, const Ball item);
Ball  dequeue(Ball_queue *queue);
void display(Ball_queue* queue);
Ball peek(const Ball_queue* queue);

#endif //BALL_H
