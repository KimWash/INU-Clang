//
//  main.c
//  Concentration
//
//  Created by 최경민 on 2022/09/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 3;
    int result;
    
    result = a+b * c / d; // b*c => (b*c) /d -> a+ ((b*c) /d)
    printf("연산값: %d\n", result);
    
    result = (a+b) *c / d;
    printf("연산값: %d\n", result);

    result = a=b=1;
    printf("연산값: %d\n", result);

}
