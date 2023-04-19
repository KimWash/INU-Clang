//
//  main.c
//  FileStream
//
//  Created by 최경민 on 2022/11/15.
//

#include <stdio.h>


int main(int argc, const char * argv[]) {
    FILE *fp = NULL;
    int c;
    
    fp = fopen("alphabet.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        return 1;
    }
    
    while((c = fgetc(fp)) != EOF)
        putchar(c);
    fclose(fp);
    return 0;
}
