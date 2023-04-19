//
//  main.c
//  SphereAreaCalculator
//
//  Created by 최경민 on 2022/09/13.
//

#include <stdio.h>
#define PI 3.141592

int main(int argc, const char * argv[]) {
    double radius, area;
    printf("원의 반지름을 입력하시오:");
    scanf("%lf", &radius);
    area = radius * radius * PI;
    printf("원의 면적: %lf\n", area);
}
