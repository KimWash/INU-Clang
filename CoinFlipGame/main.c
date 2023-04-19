//
//  main.c
//  CoinFlipGame
//
//  Created by 최경민 on 2022/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    int coin;
    srand(time(NULL));
    coin = rand() % 2 == 0; // 난수를 2로 나눈 것이 2이면 참, 아니면 거짓
    printf("%s입니다.\n", coin ? "앞면" : "뒷면");
    return 0;
}
