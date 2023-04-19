//
//  main.c
//  Calculator
//
//  Created by 최경민 on 2022/09/08.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b, sum, sub, mul;
    int div;
    printf("첫 번째 숫자를 입력하시오:");
    scanf("%d", &a);
    printf("두 번째 숫자를 입력하시오:");
    scanf("%d", &b);
    sum = a+b;
    sub = a-b;
    mul = a*b;
    div = a/b;
    printf("두수의 합= %d\n", sum);
    printf("두수의 차= %d\n", sub);
    printf("두수의 곱= %d\n", mul);
    printf("두수의 몫= %d\n", div);


    return 0;
}
