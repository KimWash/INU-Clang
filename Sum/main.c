//
//  main.c
//  Sum
//
//  Created by 최경민 on 2022/10/18.
//

#include <stdio.h>

int sum(int i, int n, int sums);

int main(int argc, const char * argv[]) {
    int n;
    int sums = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    
    // 1. for loop
    for (int i = 1; i <= n; i++) {
        sums += i;
    }
    // 2. while loop
    int i = 1;
    while (i <= n) {
        sums += i;
        i++;
    }
    // 3. recursive function
    printf("sum: %d\n", sum(1, 10, 0));
}

int sum(int i, int n, int sums) {
    sums += i;
    if (i <= n) {
        return sum(i+1, n, sums);
    } else return sums;
}

// i < n 이면 자기 자신을 다시 호출
// 이상이면 리턴
