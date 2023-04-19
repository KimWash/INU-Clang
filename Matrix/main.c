//
//  main.c
//  Matrix
//
//  Created by 최경민 on 2022/10/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]);

int main(int argc, const char * argv[]) {
    int matA[ROWS][COLS];
    int matB[COLS][ROWS];
    int resultMat[ROWS][COLS] = {{0,0,0}, {0,0,0}, {0,0,0}};
    
    srand((unsigned int)time(NULL));
    
    /*
    //Fill random numbers
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matA[i][j] = rand() % 10;
            matB[i][j] = rand() % 10;
        }
    }
     */
    printMatrix(matA);
    printf("\n");
    printMatrix(matB);
    
    for (int i = 0; i < ROWS; i ++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < ROWS; k++) {
                resultMat[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    printMatrix(resultMat);
}

void printMatrix(int matrix[ROWS][COLS] ) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
