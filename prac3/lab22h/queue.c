#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue {
    double *items;
    int head;
    int capacity;
    int num_items;
};

queue queue_new() {
    int default_size = 7;
    queue result = malloc(sizeof(*result));
    result->capacity = default_size;
    result->num_items = 0;
    result->head = 0;
    result->items = calloc(7, sizeof(double));
    return result;
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
/* print queue contents one per line to 2 decimal places */
    int i = 0;
    while(i != q->num_items){
        printf("%.2f\n", q->items[(q->head+i) % q->capacity]);
        i++;
    }
}

void queue_print_info(queue q) {
    int i;
    printf("capacity %d, num_items %d, head %d\n[", q->capacity, q->num_items, q->head);
    for (i = 0; i < q->capacity; i++) {
        printf("%s%.2f", i == 0 ? "" : ", ", q->items[i]);
    }
    printf("]\n");
}

int queue_size(queue q) {
    return q->num_items;
}

queue queue_free(queue q) {
    free(q->items);
    free(q);
    return q;
}