//
//  main.c
//  Structure
//
//  Created by 최경민 on 2022/11/10.
//

#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};

int main(int argc, const char * argv[]) {
    struct point p1, p2;
    printf("p1의 좌표: ");
    scanf("%d,%d", &(p1.x), &(p1.y));
    printf("p2의 좌표: ");
    scanf("%d,%d", &(p2.x), &(p2.y));
    
    double distance = sqrt(pow(p2.x-p1.x, 2) + pow(p2.y-p1.y, 2));
    printf("두 점 사이의 거리는: %lf\n", distance);
}
