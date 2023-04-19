//
//  main.c
//  TicTacToe
//
//  Created by 최경민 on 2022/10/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3

void printBoardAndCheckWhoWon(void);
void playWithAI(void);
void printBoard(char board[SIZE][SIZE]);
int isWon(char board[SIZE][SIZE]);
int countSymbolInRow(int i, char symbol);
int countSymbolInColumn(int i, char symbol);
int countSymbolInDiagonal(char symbol);
int countSymbolInReverseDiagonal(char symbol);
int considerTwoBingo(char symbol, char symbolToPlace);
int considerAnyOneExist(char symbol, char symbolToPlace);
void placeAnywhere(void);
void aiTurn(void);
int playerTurn(void);

char board[SIZE][SIZE];
int trial;

int main(int argc, const char * argv[]) {
    srand((unsigned int) time(NULL));
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            board[x][y] = ' ';
        }
    }
    playWithAI();
    
    return 0;
}

void printBoardAndCheckWhoWon() {
    printBoard(board);
    if (isWon(board)) {
        printf("%s won\n", trial % 2 == 0 ? "AI" : "Player");
        exit(0);
    }
}

// 짝수는 사람, 홀수는 AI입니다.
void playWithAI() {
    while (trial < 9) {
        if (!playerTurn()) continue;
        printf("Tried %d times, PlayerTurn: \n", trial);
        printBoardAndCheckWhoWon();
        aiTurn();
        printf("Tried %d times, AITurn: \n", trial);
        printBoardAndCheckWhoWon();
    }
    printf("비김");
    return;
}

int playerTurn() {
    int input[2];
    scanf("%d, %d", &input[0], &input[1]);
    if (board[input[0]][input[1]] == ' ') {
        board[input[0]][input[1]] = 'X';
        trial++;
        return 1;
    } else {
        printf("Not empty!\n");
        return 0;
    }
}

int countSymbolInRow(int i, char symbol) {
    int horizontalCnt = 0;
    for (int j = 0; j < SIZE; j++) {
        if (board[i][j] == symbol) horizontalCnt++;
    }
    return horizontalCnt;
}
/**
 @param i i열을 대상으로 진행합니다.
 @param symbol 이 심볼을 찾습니다.
 */
int countSymbolInColumn(int i, char symbol) {
    int verticalCnt = 0;
    for (int j = 0; j < SIZE; j++) {
        if (board[j][i] == symbol) verticalCnt++;
    }
    return verticalCnt;
}

int countSymbolInDiagonal(char symbol) {
    int diagonalCnt = 0;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][i] == symbol) diagonalCnt++;
    }
    return diagonalCnt;
}

int countSymbolInReverseDiagonal(char symbol) {
    int reverseDiagonalCnt = 0;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][SIZE-1 - i] == symbol) reverseDiagonalCnt++;
    }
    return reverseDiagonalCnt;
}


int considerTwoBingo(char symbol, char symbolToPlace) {
    // 행, 열, 대각선으로 두개가 채워져 있으면 빈칸 찾아 넣기
    for (int i = 0; i < SIZE; i++) {
        if (countSymbolInRow(i, symbol) == SIZE - 1) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    return 1;

                }
            }
        }
        if (countSymbolInColumn(i, symbol) == SIZE - 1) {
            for (int j = 0; j < SIZE; j++) {
                if (board[j][i] == ' ') {
                    board[j][i] = 'O';
                    return 1;
                }
            }
        }
        if (countSymbolInDiagonal(symbol) == SIZE - 1) {
            for (int i = 0; i < SIZE; i++) {
                if (board[i][i] == ' ')  {
                    board[i][i] = 'O';
                    return 1;

                }
            }
        }
        if (countSymbolInReverseDiagonal(symbol) == SIZE - 1) {
            for (int i = 0; i < SIZE; i++) {
                if (board[i][SIZE-1 - i] == ' ') {
                    board[i][SIZE-1 - i] = 'O';
                    return 1;
                }
            }
            
        }
    }
    return 0;
}

int considerAnyOneExist(char symbol, char symbolToPlace) {
    // 아무데나 하나라도 있으면 거기 둘게요,,
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // 심볼을 찾으면
            if (board[i][j] == symbol)  {
                // 그 행/열/대각선에 대해 비어있는 곳에 놓는다.
                for (int k = 0; k < SIZE; k++) {
                    if (board[i][k] == ' ')  {
                        board[i][k] = symbolToPlace;
                        return 1;
                    }
                    if (board[k][i] == ' ') {
                        board[k][i] = symbolToPlace;
                        return 1;
                    }
                    if (board[k][k] == ' ') {
                        board[k][k] = symbolToPlace;
                        return 1;
                    }
                    if (board[k][SIZE-1 - k] == ' ') {
                        board[k][SIZE-1 - k] = symbolToPlace;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void placeAnywhere() {
    int i = rand() % SIZE;
    int j = rand() % SIZE;
    // 비어있지 않으면
    while (board[i][j] != ' ') {
        
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

void aiTurn() {
    // 두줄이 채워져 있는 곳에 넣기.
    int placed = considerTwoBingo('O', 'O');
    if (!placed) placed = considerTwoBingo('X', 'O');
    if (!placed) placed = considerAnyOneExist('O', 'O');
    if (!placed) placed = considerAnyOneExist('X', 'O');
    if (!placed) placeAnywhere();
    trial++;
}

int isWon() {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] && board[0][i] != ' ')) return 1;
    }
    
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') ||
        (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')) return 1;

    return 0;
}
 
void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    }
    printf("---|---|---\n");
}
