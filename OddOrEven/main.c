//
//  main.c
//  OddOrEven
//
//  Created by 최경민 on 2022/09/22.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num;
    printf("정수를 입력하시오: ");
    scanf("%d", &num);
    printf("입력된 정수는 %s 입니다.\n", num % 2 == 0 ? "짝수" : "홀수");
}
