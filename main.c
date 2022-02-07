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

    // Info-dump!
    printf("   Welcome to the Caverns. Try to escape with as high a health as possible.\n\n");
    printf("You can roll 1, 2, or 3 dice. Dots are empty, exclamation marks remove 1 health,\n");
    printf("and plus signs add 1 health. Good luck! \n\n");

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
    int playerHealth = 2;
    int roll = 0;
    int result = 0;
    while(playerLocation < BOARD_LENGTH){
        if(playerHealth == 0){
            break;
        }
        printf("\nYou currently have %i health.\n\n@ ",playerHealth);
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
    if(playerHealth == 0){
        printf("\nYou didn't survive the Cavern...\n");
    }else{
        printf("\nCongratulations! You escaped the Cavern with %i health!\n",playerHealth);
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
    switch(rand() % 5){
        case 0:
            printf("You stepped on a spike!\n");
            break;
        case 1:
            printf("You tripped on an inconvenient gizmo!\n");
            break;
        case 2:
            printf("You drank a glass of milk! Expired milk!\n");
            break;
        case 3:
            printf("You fell, and you couldn't get up!\n");
            break;
        case 4:
            printf("You stepped on broken glass!\n");
            break;
    }
}

void printRandomHeal(){
    switch(rand() % 5){
        case 0:
            printf("You found a spare band-aid!\n");
            break;
        case 1:
            printf("You drank a glass of milk!\n");
            break;
        case 2:
            printf("You accidentally swallowed a fairy!\n");
            break;
        case 3:
            printf("You microwaved leftover chicken tikka!\n");
            break;
        case 4:
            printf("Your mother brought you dinner!\n");
            break;
    }
}