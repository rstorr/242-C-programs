#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 2000000

void merge (int *array, int *workspace, int len){
    int i = array[0];
    int j = array[len/2];
    int k = 0;

    while (i < len/2 && j < len-1){
        if (i <= j) {
            workspace[k] = i;
            i++;
        } else {
            workspace[k] = j;
            j++;
        }
        k++;
    }

    while(i < len/2){
        workspace[k] = i;
        i++;
        k++;
    }

    while(j < len-1){
        workspace[k] = j;
        j++;
        k++;
    }
}

void merge_sort(int *a, int *w, int n){
    if (n < 2){
        return;
    }

    merge_sort(a, w, n / 2);
    merge_sort((a+(n/2)), w, (n-(n/2)));

    merge(a, w, n);
    
    a = w;
}

int my_array[ARRAY_MAX];
int workspace[ARRAY_MAX];


int main(void) {
    clock_t start, end;
    int i, count = 0;

    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }
    start = clock();
    merge_sort(my_array, workspace, count);
    end = clock();
    
    for (i=0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
