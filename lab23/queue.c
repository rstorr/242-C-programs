#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue {
        double *items;
        int head;
        int capacity;
        int num_items;
};

queue queue_new(int capacity) {
        queue q = malloc(sizeof(*q));
        q->capacity = capacity;
        q->num_items = 0;
        q->head = 0;
        q->items = calloc(7, sizeof(double));
        return q;
}

void enqueue(queue q, double item) {
        if (q->num_items < q->capacity) {
                q->items[(q->head + q->num_items++) % q->capacity] = item;
        }
}

double dequeue(queue q) {
        int i = q->head;
        q->num_items--;
        q->head++;
        q->head%=q->capacity;
        return q->items[i];
}

void queue_print(queue q) {
        int i = 0;
        while(i != q->num_items){
                printf("%.2f\n", q->items[(q->head+i++) % q->capacity]);
        }
}

int queue_size(queue q){
        return q->num_items;
}

queue queue_free(queue q){
        free(q->items);
        free(q);
        return q;
}
