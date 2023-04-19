//
//  main.c
//  PointerSwap
//
//  Created by 최경민 on 2022/10/27.
//

#include <stdio.h>

void swap (int* x, int* y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
    printf("%d, %d\n", *x, *y);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 1;
    int b = 2;
    printf("%d, %d\n", a,b);
    swap(&a, &b);
    return 0;
}
