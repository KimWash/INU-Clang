//
//  main.c
//  ArrayAssignment
//
//  Created by 최경민 on 2022/10/04.
//

#include <stdio.h>
#define DAYS 16;

int main(int argc, const char * argv[]) {
    int assignment[16];
    for (int i = 0; i < 16; i++) {
        printf("%d 번째 강의에 출석하셨나요? (출석은 1, 결석은 0): ", i+1);
        int todayAssignment;
        scanf("%d", &todayAssignment);
        assignment[i] = todayAssignment;
    }
    int assignmentedDays = 0;
    for (int i = 0; i < 16; i++) {
        if (assignment[i] == 1) assignmentedDays++;
    }
    printf("%d", assignmentedDays);

    float assignmentRate = assignmentedDays / 16.0;
    if (assignmentRate < 0.3) {
        printf("출석일수 부족입니다. (%f%%)", assignmentRate * 100);
    }
}
