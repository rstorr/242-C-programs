#include <stdlib.h>

int main (int argc, char *argv[]) {
    int i = 0;

    srand(time(NULL));
    
    while (atoi(argv[1]) > i){
        int r = rand();
        printf("%d\n", r);
        i++;
    }
    
    return EXIT_SUCCESS;
}
