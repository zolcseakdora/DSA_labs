//
// Created by Bence on 4/3/2025.
//

#include "labdak.h"

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

Ball_Array* create_ball_array(int capacity) {
    //allocate memory for the struct
    Ball_Array *pArray =(Ball_Array*)malloc(sizeof(Ball_Array));;

    if (!pArray) {
        return NULL;
    }
    pArray->capacity = capacity;
    pArray->size = 0;
    //allocate memory for the elements
    pArray->elements = (Ball*)calloc(capacity, sizeof(Ball));
    if (!pArray->elements) {
        free(pArray);
        return NULL;
    }

    return pArray;
}

void deallocate_ball_array(Ball_Array **pArray) {
    free((*pArray)->elements);
    free(*pArray);
    *pArray = nullptr;
}



void read_balls(Ball_Array *balls) {
    FILE* f = fopen("../input.txt", "r");
    if (!f) {
        printf("File not found!\n");
        return;
    }

    srand(time(0));

    int rightmost_red = -1;
    int leftmost_white = balls->capacity;

    while (balls->size < balls->capacity) {
        int diameter, is_signed;
        char color[21];


        if (fscanf(f, "%d", &diameter) != 1) break;
        fgetc(f);
        if (!fgets(color, 20, f)) break;
        trim(color);
        if (fscanf(f, "%d", &is_signed) != 1) break;



        if (strcmp(color, "RED") == 0) {
            insert_first(balls, (Ball){diameter, string_to_enum(color), is_signed});
            rightmost_red++;
        }
        else if (strcmp(color, "WHITE") == 0) {
            insert_last(balls, (Ball){diameter, string_to_enum(color), is_signed});
            leftmost_white = balls->size - 1;
        }
        else {

            if (rightmost_red + 1 < leftmost_white) {
                int index = (rightmost_red + 1) + rand() % (leftmost_white - rightmost_red - 1);
                insert_at(balls, index, (Ball){diameter, string_to_enum(color), is_signed});
            } else {
                insert_at(balls, rightmost_red + 1, (Ball){diameter, string_to_enum(color), is_signed});
            }
        }
    }

    fclose(f);
}


void print_balls(Ball_Array *balls) {
    if (is_empty(balls)) {
        printf("The ball array is empty.\n");
        return;
    }

    printf("Ball List:\n");
    for (int i = 0; i < balls->size; ++i) {
        Ball b = balls->elements[i];
        printf("Ball %d -> Diameter: %d, Color: %s, Signed: %s\n",
               i + 1, b.diameter, enum_to_string(b.color),
               b.is_signed ? "Yes" : "No");
    }
}

void rm_selected_diameter(Ball_Array *balls, int diameter) {
    if (is_empty(balls)) return;
    for (int i = 0; i< balls->size; ++i) {
        if (balls->elements[i].diameter >= diameter) {
            rm_ball_at(balls,i);
            --i;
        }
    }
}

int signed_balls(Ball_Array *balls) {
    if (is_empty(balls)) return 0;
    int count = 0;
    for (int i=0; i< balls->size; ++i) {
        if (balls->elements[i].is_signed) ++count;

    }
    return count;
}

void sort_by_diameter(Ball_Array *balls) {
    qsort(balls->elements,balls->size,sizeof(Ball),cmp);
}

//helpers
void trim(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') str[len-1] ='\0';
}

Color string_to_enum(char *str) {
    for (int i = 0; i < NR_COLORS; ++i) {
        if(strcmp(str, colorStrings[i]) == 0) {
            return i;
        }
    }
    return OTHER;
}

const char * enum_to_string(Color color) {
        if(color <= NR_COLORS) {
            return colorStrings[color];
        }
        return "UNDEFINED";
}
bool is_full(Ball_Array *array) {
    if (array->size == array->capacity) return true;
    return false;
}

bool is_empty(Ball_Array *array) {
    if (array->size < 1) return true;
    return false;
}

Ball get_item_at(Ball_Array *array, int position) {
    Ball empty_ball = {0};
    if (position >= array->size || position < 0) {
        printf("Invalid position!\n");
        return empty_ball;
    }
    return array->elements[position];
}
void insert_first(Ball_Array *balls, Ball item) {
    if (is_full(balls)) {
        printf("The array is full, no items can be added!\n");
        return;
    }
    // make room for the nex element
    ++balls->size;
    //shift elements by one
    for (int i = balls->size - 1; i > 0; --i) {
        balls->elements[i] =  balls->elements[i - 1];
    }
    //add new element
    balls->elements[0] = item;
}
void insert_last(Ball_Array *balls, Ball item) {
    //check if array is full
    if (is_full(balls)) {
        printf("The array is full, no items can be added!\n");
        return;
    }
    //add element and increasing size
    balls->elements[balls->size] = item;
    ++balls->size;
}
void insert_at(Ball_Array *balls, int position, Ball item) {
    // check if position is valid
    if (position < 0 ) {
        printf("Invalid position!\n");
        return;
    }
    //check if array is full
    if (is_full(balls)) {
        printf("The array is full!\n");
        return;
    }

    ++balls->size;
    for (int i = balls->size - 1; i > position; --i) {
        balls->elements[i] = balls->elements[i - 1];
    }
    balls->elements[position] = item;
}
bool update(Ball_Array* balls, int position, Ball newItem) {
    //check if array is empty
    if (is_empty(balls)) {
        return false;
    }
    // check if position is valid
    if (position < 0 || position > balls->size) {
        printf("Invalid position!\n");
        return false;
    }
    balls->elements[position] = newItem;
    return true;
}

int cmp(const void *p, const void *q) {
    Ball* pp = (Ball*)p;
    Ball* pq = (Ball*)q;
    return pp->diameter - pq->diameter;
}

void rm_ball_at(Ball_Array* balls, int index) {
    if (is_empty(balls)) return;
    for (int i = index; i < balls->size - 1; ++i) {
        update(balls,i,get_item_at(balls,i+1));
    }
    --balls->size;
}
