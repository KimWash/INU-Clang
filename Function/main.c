//
//  main.c
//  Function
//
//  Created by 최경민 on 2022/10/13.
//

#include <stdio.h>

int getInt(void);
int getMax(int a, int b);

int main(int argc, const char * argv[]) {
    int a = getInt();
    int b = getInt();
    printf("Max value is: %d.\n", getMax(a,b));
}

int getInt() {
    int userInput;
    printf("Enter integer: ");
    scanf("%d", &userInput);
    return userInput;
}

int getMax(int a, int b) {
    return a > b ? a : b;
}
