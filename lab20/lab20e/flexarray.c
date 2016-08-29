/*flexarray.c*/
#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

void *emalloc(size_t s) {
void *result = malloc(s);
if (NULL == result) {
fprintf(stderr, "Memory allocation failed!\n");
exit(EXIT_FAILURE);
}
return result;
}

void *erealloc(void *p, size_t s) {
void *result = realloc(p,s);
if(NULL == result){
fprintf(stderr, "Memory allocation failed!\n");
exit(EXIT_FAILURE);
}
return result;
}



struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};
flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}
void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity) {
        f->capacity += f->capacity;
        f->items = erealloc(f->items,f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num;
}
void flexarray_print(flexarray f) {
    int i;
    for(i = 0; i < f->itemcount; i++){
    printf("%d\n", f->items[i]);
    }
}
void selection_sort(int *a, int n) {
    /*variable declaration.*/
    int p, j, temp, min;
    int print;
    /*nested for-loop to itterate each element in the array and sort accordingly. */
    for(p = 0; p < n; p++){
        min = p;
        for(j = p + 1; j < n; j++){
            /*if statement which handles the interchanging of positions.*/
            if (a[j] < a[min]){
                min = j;
            }
            
        }
        temp = a[p];
        a[p] = a[min];
        a[min] = temp;

        if(p == (n-1)/2){
            for(print = 0; print < n; print++){
                fprintf(stderr, "%d\n", a[print]);
            }
        }
    }
}


void flexarray_sort(flexarray f) {
    selection_sort(f->items, f->itemcount); 
}

void flexarray_free(flexarray f) {
    free(f->items);
}
