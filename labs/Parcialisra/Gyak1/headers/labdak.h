//
// Created by Bence on 4/3/2025.
//

#ifndef LABDAK_H
#define LABDAK_H
#define NR_COLORS 9
#define NR_BALLS 10
#include <stdbool.h>
typedef enum  {RED, WHITE, BLACK, YELLOW, BLUE,PURPLE,ORANGE,GREEN, OTHER } Color;
static const char colorStrings[9][20] = {"RED", "WHITE", "BLACK", "YELLOW", "BLUE","PURPLE","ORANGE","GREEN","OTHER"};
typedef struct {
    int diameter;
    Color color;
    bool is_signed;
}Ball;

typedef struct {
    int capacity;
    int size;
    Ball *elements;

}Ball_Array;

Ball_Array* create_ball_array(int capacity);
void deallocate_ball_array(Ball_Array **pArray);
void read_balls(Ball_Array* balls);
void print_balls(Ball_Array *balls);
void rm_selected_diameter(Ball_Array* balls, int diameter );
int signed_balls(Ball_Array* balls);
void sort_by_diameter(Ball_Array* balls);

//Helpers
void trim(char* str);
Color string_to_enum(char* str);
const char* enum_to_string( Color color);
void rm_ball_at(Ball_Array* balls, int index);
bool is_full(Ball_Array *array);
bool is_empty(Ball_Array *array);
Ball get_item_at(Ball_Array *array, int position);
void insert_first(Ball_Array *balls, Ball item);
void insert_last(Ball_Array *balls, Ball item);
void insert_at(Ball_Array *balls, int position, Ball item);
bool update(Ball_Array* balls, int position, Ball newItem);
int cmp(const void* p, const void* q);
#endif //LABDAK_H
