//
//  main.c
//  RecursiveStars
//
//  Created by 최경민 on 2022/10/18.
//

#include <stdio.h>

void secondaryStars(int i, int n) {
    printf("*");
    if (i < n) {
        secondaryStars(i+1, n);
    } else return;
}

void stars(int i, int n) {
    secondaryStars(0, i);
    printf("\n");
    if (i < n-1) {
        stars(i+1, n);
    } else return;
}

int main(int argc, const char * argv[]) {
    stars(0, 10);
    
}


