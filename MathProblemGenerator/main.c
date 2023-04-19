//
//  main.c
//  MathProblemGenerator
//
//  Created by 최경민 on 2022/10/04.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>


int main(int argc, const char * argv[]) {
    printf("산수 문제를 자동으로 출제합니다.\n");
    int a,b,res;
    int correct = 0;
    int input;
    while (!correct) {
        srand((unsigned int)time(NULL));
        a = rand() % 99;
        b = rand() % 99;
        res = a+b;
        printf("%d + %d = ", a,b);
        scanf("%d", &input);
        if (res == input) {
            printf("맞았습니다.\n");
            break;
        } else {
            printf("틀렸습니다.\n");
        }
    }
}
