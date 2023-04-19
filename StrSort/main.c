//
//  main.c
//  StrSort
//
//  Created by 최경민 on 2022/11/08.
//

#include <stdio.h>
#include <string.h>
#define size 6

int main(int argc, const char * argv[]) {
    char words[size][10] = {"pineapple", "banana", "apple", "tomato", "pear", "avocado"};
    for (int i = size - 1; i > 0; i --) {
        for (int j = 0; j < i; j++) {
             // 첫번째 argument가 더 크면.
            if (strcmp(words[j], words[j+1]) > 0) {
                char tmp[10];
                strcpy(tmp, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], tmp);
            }
        }
    }
    for (int i = 0; i < size; i++) {
        printf("%s\n", words[i]);
    }
}
