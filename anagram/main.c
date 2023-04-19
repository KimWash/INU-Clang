//
//  main.c
//  anagram
//
//  Created by 최경민 on 2022/11/08.
//

#include <stdio.h>
#define SOL "apple"
#define LEN 5
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    char input[LEN];
    char anagramed[LEN] = SOL;
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < 10; i++) {
        int x = rand() % LEN;
        int y = rand() % LEN;
        int tmp;
        tmp = anagramed[x];
        anagramed[x] = anagramed[y];
        anagramed[y] = tmp;
    }
    
    do {
        printf("%s는 어떤 단어가 스크램블 된것일까요? ", anagramed);
        scanf("%s", input);
    } while(strcmp(input, SOL) != 0);
    
    printf("맞춤,,");
}
