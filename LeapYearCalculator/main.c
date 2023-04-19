//
//  main.c
//  LeapYearCalculator
//
//  Created by 최경민 on 2022/09/22.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int year;
    printf("연도를 입력하시오: ");
    scanf("%d", &year);
    
    int leapYearConditionFirst = year % 4 == 0;
    int leapYearConditionThird = year % 4 == 0 && year % 100 == 0 && year % 400 == 0;
    
    printf("%d년은 %s입니다.\n", year, leapYearConditionFirst || leapYearConditionThird ? "윤년" : "평년");
}
