//
//  main.c
//  DaysPerMonth
//
//  Created by 최경민 on 2022/09/27.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int month;
    printf("일수를 알고 싶은 달을 입력하시오: ");
    scanf("%d", &month);
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("%d월은 31일입니다.\n", month);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("%d월은 30일입니다.\n", month);
            break;
        case 2:
            printf("2월은 윤년일 떄 29일, 아닐때 28일입니다.\n");
            break;
        default:
            printf("잘못된 입력입니다.\n");
    }
}
