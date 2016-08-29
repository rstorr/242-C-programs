#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
#include "mylib.h"

struct bstnode {
    char *key;
    bst right;
    bst left;
};

bst bst_new(){
    return NULL;
}

bst bst_insert(bst b, char *str){
    if (b == NULL){
        b = emalloc(sizeof(*b));
        b->left = b->right = NULL;
        b->key = emalloc(sizeof(str[0]) * (strlen(str) + 1));
        strcpy(b->key, str);
        
    }else if (strcmp(b->key, str) > 0){
        b->left = bst_insert(b->left, str);
    }else if (strcmp(b->key, str) < 0){
        b->right = bst_insert(b->right,str);
    }
    return b;
}

void bst_preorder(bst b, void f(char *str)){
    if (b == NULL) return;
    f(b->key);
    bst_preorder(b->left, f);
    bst_preorder(b->right, f);
}

void bst_inorder(bst b, void f(char *str)){
    if (b == NULL) return;
    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);
}

int bst_search(bst b, char *str){
    if (b == NULL)return 0;
    if (!strcmp(b->key, str)) return 1;
    if (strcmp(b->key, str) > 0){
        return bst_search(b->left, str);
    }else{
        return bst_search(b->right, str);
    }
    return 0;
}
  
bst bst_free(bst b){
    if (b == NULL)return b;
    bst_free(b->left);
    bst_free(b->right);
    free(b->key);
    free(b);
    return b;
}
