//
//  main.c
//  FindInArray
//
//  Created by 최경민 on 2022/10/06.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // 1 ~ 100이 채워진 배열 만들기
    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = i+1;
    }
    
    int valueToFind;
    printf("찾을 값을 입력하세요: ");
    scanf("%d", &valueToFind);
    /* 완전탐색
    for (int i = 0; i < 100; i++) {
        if (arr[i] == valueToFind) {
            printf("탐색 성공 인덱스: %d\n", i);
            return 0;
        }
    }
    printf("찾는 값이 없습니다.");*/
    
    // 이진탐색
    int start = 0, mid = 50, end = 99;
    while (mid != valueToFind-1) {
        if (mid > valueToFind-1) { // 찾고자 하는 값이 더 작을 때
            end = mid;
            mid -= (end - start) / 2;
        } else if (mid < valueToFind-1) { // 찾고자 하는 값이 더 클때
            start = mid;
            mid += (end - start) / 2;
        }
    }
    printf("탐색 성공 인덱스: %d\n", mid);
    return 0;
}
