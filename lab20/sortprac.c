#include <stdio.h>
#include <stdlib.h>
#include "20cprac.h"

int main(void){
    int num;

    flexarray f = flexarray_new();
    
    while(1 == scanf("%d", &num)){
        flexarray_append(f, num);
    }

    flexarray_sort(f);
    flexarray_print(f);
    flexarray_free(f);
    return EXIT_SUCCESS;
}
