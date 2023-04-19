//
//  main.c
//  ScholarShipChecker
//
//  Created by 최경민 on 2022/09/22.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int score;
    printf("성적을 입력하시오: ");
    scanf("%d", &score);
    if (score >= 60) printf("합격입니다.\n장학금도 받을 수 있습니다.\n");
    else printf("불합격입니다.\n장학금을 받으실 수 없습니다.\n");
    return 0;
}
