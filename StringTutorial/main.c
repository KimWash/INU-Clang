//
//  main.c
//  StringTutorial
//
//  Created by 최경민 on 2022/11/03.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char result[] = "__ ___ _________ ____";
    char original[] = "at the beachwood cafe";
    char charToPredict;
    
    while (1) {
        printf("문자열: ", result);
        printf("문자: ");
        char ch = getchar();
        
        if (ch == "\n") {
            continue;

        }
        else getchar();
        for (int i = 0; i < strlen(original); i++) {
            if (original[i] == ch) result[i] = ch;
        }
        if (strcmp(original, result)) break;
    }
    
    
    
}
