//
//  main.c
//  SumOneToHundred
//
//  Created by 최경민 on 2022/09/27.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n, sum;
    sum = 0;
    printf("Enter N: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        sum += i+1;
    }
    printf("Sum of 1 to %d is: %d\n", n, sum);
}
