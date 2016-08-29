#include <stdio.h> /*for fprintf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include "mylib.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result){
        fprintf(stderr, "Memory allocation failed! \n");
        exit(EXIT_FAILURE);
    }
    return result;
}
