//
//  main.c
//  InterestCalculator
//
//  Created by 최경민 on 2022/09/20.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int initialAsset = 24;
    double interest = 0.06;
    int years = 382;
    double finalAsset = initialAsset * pow(1 + interest, years);
    printf("24 USD로 6%의 복리로 382년 납입하면 최종 수익은: %f USD\n", finalAsset);
}
