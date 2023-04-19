//
//  main.c
//  RockPaperScissors
//
//  Created by 최경민 on 2022/09/27.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    int randValue = rand() % 3;
    
    int userInput;
    printf("당신의 입력은? (0: 가위, 1: 바위, 2: 보): ");
    scanf("%d", &userInput);
    
    if (randValue == userInput) {
        printf("랜덤: %d, 무승부", randValue);
    } else if (randValue < userInput || (randValue == 2 && userInput == 0)) {
        printf("랜덤: %d, 승리", randValue);
    } else {
        printf("랜덤: %d, 패배", randValue);
    }
}
