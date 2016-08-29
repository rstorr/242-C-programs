#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

void *emalloc(size_t s){
    void *res = malloc(s);

    if (res == NULL){
        fprintf(stderr, "Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    return res;
}

void *erealloc(void *a, size_t s){
    void *res = realloc(a, s);

    if (res == NULL){
        fprintf(stderr, "Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    return res;
}
    
struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};
    
flexarray flexarray_new() {
    /* initialise flexarray structure (including items array) */
    flexarray f = emalloc(sizeof *f);
    f->capacity = 2;
    f->itemcount = 0;
    f->items = emalloc(f->capacity * sizeof f->items[0]);
    return f;
}
    
void flexarray_append(flexarray f, int num) {
    /* add an item to the flexarray, expanding as necessary */
    if (f->itemcount == f->capacity){
        f->capacity += f->capacity;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }

    f->items[f->itemcount++] = num;
}
    
void flexarray_print(flexarray f) {
    /* a "for" loop to print out each cell of f->items */

    int i;
    for (i = 0; i < f->itemcount ; i++){
        printf("%d\n", f->items[i]);
    }
}
    
void flexarray_sort(flexarray f) {
    /* sort into ascending order */
    int i, j, key;

    int *a = f->items;

    for (i = 1; i < f->itemcount; i++){
        key = a[i];
        j = i -1;

        while(j >= 0 && key < a[j]){
            a[j+1] = a[j];
            --j;
        }

        a[j+1] = key;

        if (i == (f->itemcount -1)/2){
            int print;
            for (print = 0; print < f->itemcount ; print++){
                fprintf(stderr,"%d\n", f->items[print]);
            }
        }
    }
        
}
    
void flexarray_free(flexarray f) {
    /* free the memory associated with the flexarray */
    free(f->items);
    free(f);
}
