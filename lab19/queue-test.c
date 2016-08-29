#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

struct queue {
    double *items;
    int head;
    int capacity;
    int num_items;
}

queue queue_new(){
    queue result = emalloc(sizeof *result);
    result->head = 0;
    result->capacity = 5;
    result->num_items = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    for( i = 0; i < result->capacity; i++){
        result->items[i] = NULL;
    }
    return result;
}

void enqueue(queue q, double item){
    if (q->num_items < q->capacity){
        q->items[head + num_items % capacity] = item;
        q->num_items++;
    }
}

double dequeue(queue q){
    if (q->num_items > 0){
        *items = q->items[head];
        q->head++;
        q->num_items--;
    }
}


void queue_print(queue q){
    int i;
    for(i = 0; i < q->num_items; i++){
        printf("%lg\n", q->items[i]);
    }
}


int queue_size(queue q){
    return q->num_items;
}

queue queue_free(queue q){
    int i;
    for(i = 0; i < q->num_items; i++){
        free(q->items[i]);
    }
    free(q->items);
    free(q);
}
