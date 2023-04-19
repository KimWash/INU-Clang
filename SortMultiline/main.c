#include<stdio.h>
#include <time.h>
// bubble sort

#define SIZE 100
int main() {

    clock_t start = clock();
    
    int sort[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            sort[i][j] = i * SIZE + j;
        }
    }
    
    int flatten[SIZE * SIZE] = {};
    //int i,j,x,y;
    //int tmp1, tmp2;
    int tmp1;
    

    // Flatten
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            flatten[j + (i*SIZE)] = sort[i][j];
        }
    }
    
    for (int i = SIZE * SIZE; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (flatten[j] > flatten[j+1]) {
                tmp1 = flatten[j];
                flatten[j] = flatten[j+1];
                flatten[j+1] = tmp1;
            }
        }
    }
    
    for (int i = 0; i < SIZE * SIZE; i++) {
        sort[i / SIZE][i % SIZE] = flatten[i];
    }
    
     /*
    
    for (i = 0; i < SIZE * SIZE; i++) {
       for (x = 0; x < SIZE; x++) {
          for (j = 0; j < SIZE; j++) {
             for (y = 0; y < SIZE - 1; y++) {
                if (x != 0 && y == 0) {
                   if (sort[x - 1][SIZE - 1] > sort[x][y]) {
                      tmp1 = sort[x - 1][SIZE - 1];
                      sort[x - 1][SIZE - 1] = sort[x][y];
                      sort[x][y] = tmp1;
                   }
                }

                if (sort[x][y] > sort[x][y + 1]) {
                   tmp2 = sort[x][y];
                   sort[x][y] = sort[x][y + 1];
                   sort[x][y + 1] = tmp2;
                }
             }
          }
       }
    }*/
    clock_t end = clock();

    printf("The aligned values are: \n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", sort[i][j]);
        }
        printf("\n");
    }
    printf("time: %lf ms \n", (double)(end - start));
}
