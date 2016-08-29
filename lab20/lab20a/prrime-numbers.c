#include <stdio.h>
#include <stdlib.h>

int is_prime(cand) {
    int i;
    
    for(i = 2; i < cand; i++){
        if (cand % i == 0){
            return 0;
        }
    }

    return 1;
}

int main(){
    int cand = 2;
    int num_print = 0;

    while(num_print < 200){
        if (is_prime(cand)){
            printf("%*d",5, cand);
            num_print++;
            if (num_print % 10 == 0){
                printf("\n");
            }
        }
        cand++;
    }
    return EXIT_SUCCESS;
}
