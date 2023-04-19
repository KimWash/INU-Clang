//
//  main.c
//  BubbleSort
//
//  Created by 최경민 on 2022/10/06.
//

#include <stdio.h>
#define SIZE 5

int main(int argc, const char * argv[]) {
    int arr[10] = {1,45,7,3,6,3,34,1236,56,43};
    int tmp, cnt = 0;
    for (int i = 10; i > 0; i--) {
        for (int j = 0; j < i-1; j++) {
            cnt++;
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                
            }
        }
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n%d 번 비교\n", cnt);

    return 0;
    
}
