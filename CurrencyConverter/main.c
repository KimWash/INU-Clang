//
//  main.c
//  CurrencyConverter
//
//  Created by 최경민 on 2022/09/08.
//

#include <stdio.h>
#define WON_PER_DOLLAR 1370

int main(int argc, const char * argv[]) {
    int dollar;
    scanf("%d", &dollar);
    printf("%d USD => %d KRW\n",dollar, dollar * WON_PER_DOLLAR);
    return 0;
}
