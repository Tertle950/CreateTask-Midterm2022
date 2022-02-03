#include <stdio.h>
#include <stdlib.h>
void arrayShuffle(char *array, size_t n);
int rollDice(int amnt);
void printRandomHurt();
void printRandomHeal();

int main(){
    // Initialize various important variables
    char NOTHING = '.';
    char DANGER = '!';
    char HEALING = '+';
    int BOARD_LENGTH = 50;

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

    /*
    for(int i = 0; i < BOARD_LENGTH; i++){
        printf("%c ",board[i]);
    }
    */

    // Now for the actual game...
    int playerLocation = 0;
    int playerHealth = 5;
    int roll = 0;
    int result = 0;
    while(playerLocation < BOARD_LENGTH){
        printf("You currently have %i health.\n@ ",playerHealth);
        for(int i = playerLocation + 1; i < BOARD_LENGTH; i++){
            printf("%c ",board[i]);
        }

        printf("\nRoll how many dice? (1-3): ");
        scanf("%i",&roll);
        result = rollDice(roll);
        playerLocation+=result;

        switch(board[playerLocation]){
            case '.': break;
            case '!':
                playerHealth--;
                printRandomHurt();
                break;
            case '+':
                playerHealth++;
                printRandomHeal();
                break;
        }
    }
    printf("\nYou ended the game with %i health.\nCongrats! Now try for higher!",playerHealth);
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

// This, however, is NOT stolen code :)
int rollDice(int amnt){
    // Constrain
    if(amnt < 1){amnt = 1;}
    if(amnt > 3){amnt = 3;}
    printf("Rolling %i dice...",amnt);
    int returner = 0;
    int roll = 0;

    for(int i = 0; i < amnt; i++){
        roll = (rand() % 3) + 1;
        printf("%i, and ",roll);
        returner += roll;
    }
    printf("done!\nYou rolled %i total.\n",returner);
    return returner;
}

void printRandomHurt(){
    switch(rand() % 2){
        case 0:
            printf("You stepped on a spike!\n");
            break;
        case 1:
            printf("You tripped on an inconvenient gizmo!\n");
            break;
        case 2:
            printf("You found a glass of milk! Expired milk!\n");
            break;
    }
}

void printRandomHeal(){
    switch(rand() % 2){
        case 0:
            printf("You found a spare band-aid!\n");
            break;
        case 1:
            printf("You found a glass of milk!\n");
            break;
        case 2:
            printf("You accidentally swallowed a fairy!\n");
            break;
    }
}