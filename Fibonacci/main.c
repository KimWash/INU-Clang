//
//  main.c
//  Fibonacci
//
//  Created by 최경민 on 2022/10/22.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n, x1=0, x2=1, x3, fibo;
    scanf("%d", &n);
    if (n == 0) {
        printf("%d", x1);
        return 0;
    }
    if (n == 1) {
        printf("%d", x2);
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        fibo = x1 + x2;
        x1 = x2;
        x2 = fibo;
    
    }
    printf("%d", fibo);

}
