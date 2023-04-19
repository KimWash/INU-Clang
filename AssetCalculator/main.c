//
//  main.c
//  AssetCalculator
//
//  Created by 최경민 on 2022/09/13.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int amountPerMonth;
    int totalAsset;
    printf("매달 저축 금액을 입력하시오: ");
    scanf("%d", &amountPerMonth);
    totalAsset = amountPerMonth * 12 * 30;
    printf("30년 후의 재산: %d\n", totalAsset);
    return 0;
}

