//
//  main.c
//  PoweredFunciton
//
//  Created by 최경민 on 2022/09/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x;
    double y;
    x = 2;
    y = 3.0 * x * x + 7.0 * x + 9.0;
    printf("3x^2 + 7x + 9\nwhen x = 2; y is: %f\n", y);
}
