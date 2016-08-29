#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/*for each position except first one in array, find smallest element in array from pos i to size -1.
 Swap this smallest item with i.*/
void selection_sort(int *a, int n) {
    int i,j,key,swap;
    
    for (i = 0; i < n-1; i++){
        
        key = i;
        for(j = i + 1; j < n; j++){
            if(a[key] > a[j]){
                key = j;
            }
        }
        if (key != i){
            swap = a[i];
            a[i] = a[key];
            a[key] = swap;
        }
    }
}

int main(void) {
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;

    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }
    start = clock();
    selection_sort(my_array, count);
    end = clock();
    
    for (i=0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
