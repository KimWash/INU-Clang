//
//  main.c
//  BuyCandy
//
//  Created by 최경민 on 2022/09/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int currentMoney;
    int candyPrice;
    
    printf("현재 가진 돈: ");
    scanf("%d", &currentMoney);
    printf("캔디 가격: ");
    scanf("%d", &candyPrice);
    printf("최대 살 수 있는 캔디 수: %d\n", currentMoney / candyPrice);
    printf("구입 후 남은 돈: %d\n", currentMoney % candyPrice);
}
