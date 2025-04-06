//
// Created by Bence on 4/4/2025.
//

#include "balls.h"
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string.h>

Ball_Queue* create_queue(int capacity) {
    Ball_Queue * queue = (Ball_Queue* ) malloc(sizeof(Ball_Queue) );
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
    queue->nr_colored_balls = 0;
    return queue;

}

void destroy_queue(Ball_Queue **queue) {
    if (!queue) return;
    free((*queue)->elements);
    free(*queue);
}

void read_balls(Ball_Queue *black, Ball_Queue *white) {
    FILE* f = fopen("../input.txt","r");
    if (!f) {
        printf("File not found!\n");
        return;
    }
    srand(time(0));

    for (int i = 0; i < 20; ++i ) {
        int diameter, is_signed;
        char color[21];

        if (fscanf(f,"%d",&diameter) != 1) {
            break;
        }
        fgetc(f);
        if (! fgets(color,20,f)) {
            break;
        }
        trim(color);
        if (fscanf(f,"%d",&is_signed) != 1) {
            break;
        }

        if (strcmp(color,"BLACK") == 0) {

            enqueue(black,(Ball){diameter,string_to_enum(color),is_signed});
            continue;
        }
        if (strcmp(color,"WHITE") == 0) {

            enqueue(white,(Ball){diameter,string_to_enum(color),is_signed});
            continue;
        }

        int rand_queue = 1 + rand() % 2;
        if (rand_queue == 1) {
            dequeue(black);
            enqueue(black,(Ball){diameter,string_to_enum(color),is_signed});
            ++black->nr_colored_balls;
            continue;
        }
        dequeue(white);
        enqueue(white,(Ball){diameter,string_to_enum(color),is_signed});
        ++white->nr_colored_balls;
    }
    fclose(f);
}

void select_colored(Ball_Queue *black, Ball_Queue *white, Ball_Queue *colored) {
    while (!is_empty(black)) {
        Ball tmp = dequeue(black);
        if (tmp.color != WHITE && tmp.color != BLACK) enqueue(colored,tmp);
    }
    while (!is_empty(white)) {
        Ball tmp = dequeue(white);
        if (tmp.color != WHITE && tmp.color != BLACK) enqueue(colored,tmp);
    }
}

//helpers
Color string_to_enum(char *str) {
    int len = strlen(str);
    for (int i =0; i<len;++i) {
        if (strcmp(str,color_string[i]) == 0) return i;
    }
    return len-1;
}

char * enum_to_string(Color color) {
    if (color < NR_COLORS ) return color_string[color];
    return "OTHER";
}
void trim(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') str[len-1] ='\0';
}

bool is_empty(const Ball_Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

bool is_full( const Ball_Queue *queue) {
    return (queue->rear == queue->capacity -1);
}

void enqueue( Ball_Queue *queue, const Ball item) {
    if (is_full(queue)) return;

    if (is_empty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear++;
    }

    queue->elements[queue->rear] = item;
}

Ball  dequeue(Ball_Queue *queue) {
    if (is_empty(queue)) return (Ball){0,OTHER,0};
    Ball res = queue->elements[queue->front];
    if (res.color != WHITE && res.color != BLACK) --queue->nr_colored_balls;

    ++queue->front;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return res;

}

void display(Ball_Queue* queue){
    if (is_empty(queue)) {
        return;
    }
    for (int i=queue->front; i<=queue->rear; i++) {
        printf("%d\n%s\n%d\n ", queue->elements[i].diameter,enum_to_string(queue->elements[i].color),queue->elements[i].is_signed);
    }
    printf("\n");
}

Ball peek(const Ball_Queue* queue) {
    if (is_empty(queue)){
        return (Ball){0,OTHER,0};
    }
    return queue->elements[queue->front];
}