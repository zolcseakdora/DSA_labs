//
// Created by Bence on 4/4/2025.
//

#ifndef BALLS_H
#define BALLS_H
#define NR_COLORS 8
typedef enum{RED,WHITE,BLACK,YELLOW,GREEN,ORANGE,PURPLE,OTHER } Color;
static const char color_string[8][20] = {"RED","WHITE","BLACK","YELLOW", "GREEN","ORANGE","PURPLE","OTHER"};
typedef struct {
    int diameter;
    Color color;
    int is_signed;
}Ball;
typedef struct {
    int front,rear, capacity;
    Ball *elements;
    int nr_colored_balls;

}Ball_Queue;

void create_queue(int capacity,Ball_Queue* queue);
void destroy_queue(Ball_Queue *queue);
void read_balls(Ball_Queue* black,Ball_Queue* white );
void select_colored(Ball_Queue* black,Ball_Queue* white, Ball_Queue* colored );
//helpers
Color string_to_enum(char* str);
char* enum_to_string(Color color);
void trim(char *str);
bool is_empty(const Ball_Queue queue);
bool is_full( const Ball_Queue queue);
void enqueue( Ball_Queue *queue, const Ball item);
Ball  dequeue(Ball_Queue *queue);
void display(Ball_Queue queue);
Ball peek(const Ball_Queue queue);
#endif //BALLS_H
