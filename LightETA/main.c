//
//  main.c
//  LightETA
//
//  Created by 최경민 on 2022/09/13.
//

#include <stdio.h>
#define LIGHT_SPEED 300000.
#define DISTANCE 149600000.

int main(int argc, const char * argv[]) {
    double time = DISTANCE / LIGHT_SPEED;
    printf("%lf minutes \n", time/60);
}

