#include <stdlib.h>
#include <stdio.h>

int main(void){
    int winner = 0;
    double winScore = 0;
    double a,b,c;
    int n;
    
    while (4 == scanf("%d%lg%lg%lg", &n, &a, &b, &c)){
          
           double score;


           if (a < b && a < c){
               score = (b + c) / 2;
           } else if ( b < a && b < c){
               score = (a + c) / 2;
           } else {
               score = (a + b) / 2;
           }

           if (score > winScore){
               winScore = score;
               winner = n;
           }
    }

    printf("%d\n", winner);
    return EXIT_SUCCESS;
}

    
