#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void) {
    int item;
    flexarray my_flex = flexarray_new();

    while (1 == scanf("%d", &item)) {
        flexarray_append(my_flex, item);
    }

    flexarray_sort(my_flex);
    flexarray_print(my_flex);
    flexarray_free(my_flex);

    return EXIT_SUCCESS;
}
