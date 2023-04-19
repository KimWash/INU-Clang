//
//  main.c
//  Calculator
//
//  Created by 최경민 on 2022/09/01.

#include <stdio.h>

int main(void) {
    double a, b;
    char operator;
    
    printf("실수를 입력하세요: ");
    scanf("%lf", &a);
    while (1) {
        printf("연산자와 실수를 입력하세요 ex) '+1':");
        scanf("\n%c", &operator);
        if (operator == 'q') break;
        scanf("%lf", &b);
        switch (operator) {
            case '+': {
                a += b;
                printf("%f\n", a);
                break;
            }
            case '-': {
                a -= b;
                printf("%f\n", a);
                break;
            }
            case '*': {
                a *= b;
                printf("%f\n", a);
                break;
            }
            case '/': {
                if (b != 0) {
                    a /= b;
                    printf("%f\n", a);
                } else {
                    printf("0으로 나눌 수 없습니다!\n");
                }
                break;
            }
        }
    }
}
