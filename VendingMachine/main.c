//
//  main.c
//  VendingMachine
//
//  Created by 최경민 on 2022/09/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int inserted, price, change;
    
    printf("투입한 돈: ");
    scanf("%d", &inserted);
    printf("물건값: ");
    scanf("%d", &price);
    change = inserted - price;
    printf("거스름돈: %d 원 \n", change);
    printf("100원 동전의 개수: %d\n", change / 100);
    printf("10원 동전의 개수: %d\n", (change % 100) / 10);
}
