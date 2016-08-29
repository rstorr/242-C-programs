#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/* for each element in array except the first one (key), find elements that are before key and are greater than it and shift them along and put
key before them.*/
   
void insertion_sort(int *a, int n) {
    int i, j, key;
    
    for (i = 1; i < n; i++){
        key = a[i];
        j = i - 1;
        
        while(a[j] > key){
            a[j + 1] = a[j];
            --j;
        }
        
        a[j + 1] = key;
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
    insertion_sort(my_array, count);
    end = clock();
    
    for (i=0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}