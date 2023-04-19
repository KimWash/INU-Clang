//
//  main.c
//  WeatherIdentifier
//
//  Created by 최경민 on 2022/09/22.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int temp;
    printf("온도를 입력하시오: ");
    scanf("%d", &temp);
    printf("%s의 날씨입니다.\n현재 온도는 %d도입니다.\n", temp > 0 ? "영상" : "영하", temp);
}
