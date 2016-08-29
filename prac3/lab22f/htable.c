#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

struct htablerec {
    int capacity;
    int num_keys;
    char **keys;
};

static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;

    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}

static unsigned int htable_hash(htable h, unsigned int i_key) {
    return i_key% h->capacity;
}

htable htable_new(int capacity){
    int i;
    htable result = emalloc(sizeof *result);
    result->capacity = capacity;
    result->num_keys = 0;
    result->keys = emalloc(capacity * sizeof(char*));
    for(i = 0; i < result->capacity; i++){
        result->keys[i] = NULL;
    }

    return result;
}

void htable_free(htable h){
    int i;
    for(i = 0; i < h->num_keys; i++){
        if (h->keys[i] != NULL){
            free(h->keys[i]);
        }
    }
    
    free(h->keys);
    free(h);
}

int htable_insert(htable h, char *key) {
    int i = htable_word_to_int(key) % h->capacity;
    int x = i;

    do{
        if(h->keys[i] == NULL){
            h->keys[i] = emalloc(sizeof key[0]*(strlen(key)+1));
            strcpy(h->keys[i],key);
            break;
        }else if (!strcmp(h->keys[i], key)){
            break;
        }
        i = (i+1)%h->capacity;
    }while(i != x);
}


void htable_print(htable h, FILE *stream){
    int i;
    for(i = 0; i < h->capacity; i++){
        fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "": h->keys[i]);
    }
}
