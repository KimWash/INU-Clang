//
//  main.c
//  BiggestNumber
//
//  Created by 최경민 on 2022/09/22.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a,b,c,tmp;
    printf("Input three integers: ");
    scanf("%d %d %d", &a,&b,&c);
    
    if (a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }if (b < c) {
        tmp = b;
        b = c;
        c = tmp;
    }if (a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    printf("%d %d %d\n", a,b,c);
    
    int cond = a > b ? ((b > c) ? a : c) : b > c ? b : c;
    
    
    printf("가장 큰 수: %d", cond);
}
