#include <stdio.h>
#include <stdlib.h>
void arrayShuffle(char *array, size_t n);

int main(){
    // Initialize various important variables
    char NOTHING = '.';
    char DANGER = '!';
    char HEALING = '+';
    int BOARD_LENGTH = 200;

    // Generate the game board
    char boardPieces[10] = {'.', '.', '!', '!', '.', '.', '+', '+', '.', '.'};
    arrayShuffle(boardPieces, 10);

    char board[BOARD_LENGTH];
    board[0] = '.';
    board[1] = '.';
    board[2] = '+';
    for(int i = 3; i < BOARD_LENGTH; i++){
        board[i] = boardPieces[i % 10];
        if(i % 10 == 0){
            arrayShuffle(boardPieces, 10);
        }
    }

    for(int i = 0; i < BOARD_LENGTH; i++){
        printf("%c ",board[i]);
    }

    return 0;
}

// this is stolen code :D
// Didn't want to reinvent the wheel, after all.
void arrayShuffle(char *array, size_t n){
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          char l = array[j];
          array[j] = array[i];
          array[i] = l;
        }
    }
}