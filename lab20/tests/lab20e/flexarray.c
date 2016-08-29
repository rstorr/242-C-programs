#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

void *emalloc (size_t s){
    void r = malloc(s);
    if (r == NULL){
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_SUCCESS);
    }

    return r;
}

    void *erealloc (void *a, size_t s){
        void r = realloc(a,s);
        if (r == NULL){
            fprintf(stderr, "Memory allocation failed");
            exit(EXIT_SUCCESS);
        }

        return r;
    }
    
struct flexarrayrec {
int capacity;
int itemcount;
    int *items;
};
    
flexarray flexarray_new() {
    /* initialise flexarray structure (including items array) */
    flexarray f = emalloc(sizeof *f);
    f->itemcount = 0;
    f->capacity = 2;
    f->items = emalloc(f->capacity * sizeof f->items[0]);
    return f;
}
    
void flexarray_append(flexarray f, int num) {
    /* add an item to the flexarray, expanding as necessary */
    if (f->itemcount == f->capacity){
        f->capacity += f->capacity;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }

    f->items[itemcount++] = num;
}
    
void flexarray_print(flexarray f) {
    /* a "for" loop to print out each cell of f->items */
    int i;

    for (i = 0; i < f->itemcount; i++){
        printf("%d\n",f->items[i]);
    }
}
    
void flexarray_sort(flexarray f) {
    /* sort into ascending order */
    int i,j,temp,min;

    int *a = f->items;
    for (i = 0; i < f->itemcount; i++){
        min = i;
        for(j = p + 1; j < f->itemcount; j++){
            if (a[j] < a[min]){
                min = j;
            }
        }
        temp = a[i];
        a[j] = a[min];
        a[min] = temp;

        if (i == (f->itemcount -1)/2){
            for(print = 0; print < n; print++){
                fprintf(stderr, "%d\n", a[print]);
            }
        }
    }
}
    
void flexarray_free(flexarray f) {
    /* free the memory associated with the flexarray */
    free(f->items);
    free(f);
}
