//
//  main.c
//  RecursiveFactorial
//
//  Created by 최경민 on 2022/10/13.
//

#include <stdio.h>

long factorial(int n){
    if (n <= 1) return 1;
    return n * factorial(n-1);
}

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, factorial(n));
}
