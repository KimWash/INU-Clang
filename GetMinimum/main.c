//
//  main.c
//  GetMinimum
//
//  Created by 최경민 on 2022/10/04.
//

#include <stdio.h>
#define SIZE 10

int main(int argc, const char * argv[]) {
    int prices[SIZE] = {12,3,19,6,18,8,12,4,2,19};
    int minima = prices[0];
    int maxima = prices[0];
    for (int i = 1; i < SIZE; i ++) {
        if (prices[i] < minima) {
            minima = prices[i];
        }
        if (prices[i] > maxima) {
            maxima = prices[i];
        }
    }
    printf("Minina is: %d and Maxima is: %d\n", minima, maxima);
}
