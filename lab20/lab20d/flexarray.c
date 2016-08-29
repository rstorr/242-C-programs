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

void insertion_sort(int *a, int n){
    int i, j, print;
    int key;
    for(i=1; i<n;i++){
        key = a[i];
        j=i-1;
        /*while loop which runs back down to all values less than j*/
        while( j>=0 && key<a[j]){
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=key;
        if(i == (n-1)/2){
            for(print = 0; print < n; print++){
                fprintf(stderr,"%d\n", a[print]);
            }
        }
    }


}

void flexarray_sort(flexarray f) {
    insertion_sort(f->items, f->itemcount); 
}

void flexarray_free(flexarray f) {
    free(f->items);
}
