//
//  main.c
//  FileCopier
//
//  Created by 최경민 on 2022/11/17.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *fp1, *fp2;
    char file1[100], file2[100];
    char charBuffer;
    char buffer[100];
    
    printf("org file name: ");
    scanf("%s", file1);
    
    printf("dst file name: ");
    scanf("%s", file2);
    
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "w");
    
    
    if (fp1 == NULL && fp2 == NULL) {
        while ((charBuffer = fgetc(fp1)) != EOF) // 문자별 카피
            fputc(charBuffer, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
