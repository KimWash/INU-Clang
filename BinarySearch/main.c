//
//  main.c
//  NumberGuessing
//
//  Created by 최경민 on 2022/09/30.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int start = 0;
    int end = 100;
    int mid = 50;
    int userInput;
    int cnt = 1;
    while (userInput != 1) {
        printf("%d 보다 작으면 0, 같으면 1, 크면 2를 입력하세요: ", mid);
        scanf("%d", &userInput);
        if (userInput == 0) { // 작으면
            end = mid;
            mid -= ((end - start) / 2);
        } else if (userInput == 2) {
            start = mid;
            mid += ((end-start) / 2);
        } else if (userInput == 1) {
            printf("사용자는 %d를 생각했습니다. %d번 만에 답을 맞췄습니다.\n", mid, cnt);
            break;
        }
        cnt += 1;
    }
    return 0;
}
