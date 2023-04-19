//
//  main.c
//  99Dan
//
//  Created by 최경민 on 2022/09/29.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    for (int i = 1; i <= 9; i ++) {
        for (int j = 1; j <= 9; j++) {
            printf("%d x %d = %d\n",i,j,i*j);
        }
    }
}
