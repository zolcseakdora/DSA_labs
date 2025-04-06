//
// Created by Bence on 4/5/2025.
//

#include "ball.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

Ball_queue* create_queue(int capacity) {
    Ball_queue * queue = (Ball_queue* ) malloc(sizeof(Ball_queue) );
    if (!queue) {
        printf("Memory allocation for queue faied!\n");
        return NULL;
    }

    queue->elements = (Ball *)calloc(capacity,sizeof(Ball));
    if (!queue->elements) {
        printf("Memory allocation for elements failed!\n");
        free(queue);
        return NULL;
    }

    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->num_colored = 0;
    return queue;
}

void destroy_queue(Ball_queue **queue) {
    if (!queue) return;
    free((*queue)->elements);
    free(*queue);
}

void read_balls(Ball_queue* white, Ball_queue* black) {
    FILE* f = fopen("../input.txt","r");
    if (!f) {
        printf("File not found!\n");
        return;
    }
    srand(time(0));
    for (int i = 0; i < NR_BALLS; ++i) {
        int diameter,is_signed;
        char color[17];
        if (fscanf(f,"%d",&diameter) != 1) break;
        fgetc(f);
        if (!fgets(color,15,f)) break;
        trim(color);
        if (fscanf(f,"%d",&is_signed) != 1) break;

        if (strcmp(color,"WHITE") == 0) {
            enqueue(white,(Ball){diameter,is_signed,string_to_enum(color)});
            continue;
        }
        if (strcmp(color,"BLACK") == 0) {
            enqueue(black,(Ball){diameter,is_signed,string_to_enum(color)});
            continue;
        }
        int rand_queue = rand();
        if ((rand_queue & 1)) {
            enqueue(white,(Ball){diameter,is_signed,string_to_enum(color)});
            continue;
        }
        enqueue(black,(Ball){diameter,is_signed,string_to_enum(color)});
    }

}

void select_balls(Ball_queue* white, Ball_queue* black, Ball_queue* rest) {
    while (!is_empty(white)) {
        Ball ball = dequeue(white);
        if (ball.color != WHITE) enqueue(rest,ball);
    }
    while (!is_empty(black)) {
        Ball ball = dequeue(black);
        if (ball.color != BLACK) enqueue(rest,ball);
    }
}

//helpers
char * enum_to_string(Color color) {
    if (color < NR_COLORS ) return color_string[color];
    return "OTHER";
}

Color string_to_enum(char *str) {
    for (int i = 0; i < NR_COLORS; ++i) {
        if(strcmp(str, color_string[i]) == 0) {
            return i;
        }
    }
    return OTHER;

}

void trim(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') str[len-1] ='\0';
}

bool is_empty(const Ball_queue* queue) {
    return (queue->front == -1 || (queue->front == queue->rear & queue->front != 0)) ;
}

bool is_full( const Ball_queue *queue) {
    return (queue->front == (queue->rear + 1) % queue->capacity);
}

void enqueue( Ball_queue *queue, const Ball item) {
    if (is_full(queue)) return;

    if (is_empty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }

    queue->elements[queue->rear] = item;
    if (item.color != WHITE && item.color != BLACK) ++ queue->num_colored;
}

Ball  dequeue(Ball_queue *queue) {
    if (is_empty(queue)) {
        queue->front = -1;
        queue->rear = -1;
        return (Ball){0,0,OTHER};
    }
    Ball res = queue->elements[queue->front];

    queue->front = (queue->front + 1) % queue->capacity;
    if (res.color != WHITE && res.color != BLACK) -- queue->num_colored;
    return res;

}
void display(Ball_queue* queue){
    if (is_empty(queue)) {
        return;
    }
    int i = queue->front;
    while (i!= (queue->rear + 1) % queue->capacity) {
        printf("%d\n%s\n%d\n ", queue->elements[i].diameter,enum_to_string(queue->elements[i].color),queue->elements[i].is_signed);
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

Ball peek(const Ball_queue* queue) {
    if (is_empty(queue)){
        return (Ball){0,0,OTHER};
    }
    return queue->elements[queue->front];
}
