//
//  main.c
//  PrintStars
//
//  Created by 최경민 on 2022/09/27.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int n;
    while (1) {
        printf("Enter n: ");
        scanf("%d", &n); // Enter n;
        
        // 별로 한줄 깔기
        for (int i = 1; i <= n; i++) {
            printf("*");
        }
        printf("\n");

        // 맨위층부터..
        if (n % 2 == 0) {
            for (int h = 1; h < n-2; h++) {
                char charToPrint;
                if (h % 2 == 0) {
                    charToPrint = '*';
                } else {
                    charToPrint = '&';
                }
                for (int i = 0; i < n; i++) {
                    if (i == h || i == n-h-2) {
                        printf("%c", charToPrint);
                        if (i == n/2 - 1) {
                            printf("%c", charToPrint);
                        }
                    }
                    printf(" ");
                }
                printf("\n");
            }
        }

        else {
            for (int h = 1; h < n-1; h++) {
                char charToPrint;
                if (h % 2 == 0) {
                    charToPrint = '*';
                } else {
                    charToPrint = '&';
                }
                for (int i = 0; i < n; i++) {
                    if (i == h || i == n-h-1) {
                        printf("%c", charToPrint);
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
        
        // 별로 한줄 깔기
        for (int i = 1; i <= n; i++) {
            printf("*");
        }
        printf("\n");


    }
    
    
}

