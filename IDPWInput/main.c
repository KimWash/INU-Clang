//
//  main.c
//  IDPWInput
//
//  Created by 최경민 on 2022/09/13.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int id, pw;
    printf("input\n");
    printf("id:\t____\b\b\b\b");
    scanf("%d", &id);
    
    printf("pw:\t____\b\b\b\b");
    scanf("%d", &pw);
    printf("inputed id: \"%d\", inputed pw: \"%d\"\n", id, pw);

}
