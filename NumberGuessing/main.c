//
//  main.c
//  NumberGuessing
//
//  Created by 최경민 on 2022/09/29.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int answer =59;
    int guess;
    int tries = 0;
    while (guess != answer) {
        printf("Enter what you think: ");
        scanf("%d", &guess);
        if (guess > answer) {
            printf("Too big!");
        } else {
            printf("Too small!");
        }
        printf("\n");
        tries++;
    }
    printf("You guessed right number! answer: %d\n", answer);
    
}
