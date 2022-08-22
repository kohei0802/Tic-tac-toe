#include <stdio.h>
#include <stdlib.h> //system("cls");
#include <stdbool.h>

#define NOTHING_STILL 0
#define HAS_WINNER 1
#define DRAW 2
#define INVALID_INPUT 0
#define VALID_INPUT 1
#define XPLAYER 1
#define OPLAYER 2
#define BOARD_SIZE 9

void printBoard(char board[]); //print board
int validateInput(char board[], int choice);
int checkCurrentState(char board[], int current_player); //current_player is provided to avoid doubling of processing time

int main()
{
    int current_round;
    int current_player = XPLAYER;
    int choice;

    char board[9] = {'1', '2', '3',
                     '4', '5', '6',
                     '7', '8', '9'};
    for (current_round=0; current_round<9; ++current_round)
    {
        printf("          Tic Tac Toe \n");
        printf("Player 1 (x) = Player 2 (o) \n\n");
        printBoard(board);
        printf("Only enter integers!!!!!!!\n");
        printf("Player %d, enter a number: ", current_player); //be careful if input is char. might take escape sequence "space" as a char



        scanf("%d", &choice);
        while (INVALID_INPUT==validateInput(board, choice))
        {
            printf("Invalid move\n");
            printf("Enter again: ");
            scanf("%d", &choice);
        }
        if (current_player==XPLAYER)
        {
            board[choice-1] = 'x' ;
        }
        else
        {
            board[choice-1] = 'o' ;
        }



        if (checkCurrentState(board, current_player)==HAS_WINNER)
        {
            printf("**> Player %d win", current_player);
            break;
        }
        else if (checkCurrentState(board, current_player)==DRAW)
        {
            printf("It's a draw\n");
            break;
        }
        else
        {
        }

        if (current_player==XPLAYER)
            current_player=OPLAYER;
        else
            current_player=XPLAYER;

        system("cls");
    }


    return 0;
}



void printBoard(char board[])
{
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("   |   |   \n\n");
}



int validateInput(char board[], int choice) //return: INVALID_OUTPUT or VALID_OUTPUT
{
    int validity=INVALID_INPUT;
    int element;
    for (element=0; element<BOARD_SIZE; ++element)
    {
        if (board[element]=='x' || board[element]=='o')
        {
            continue;
        }
        if ( (board[element]-'0')==choice ) //it doesn't matter if choice is really an int because condition is false if input is not an int
        {
            validity=VALID_INPUT;
            break;
        }
    }

    return validity;
}



int checkCurrentState(char board[], int current_player) //return: HAS_WINNER (1) or DRAW (2) or NOTHING_STILL (0)
{
    int state=NOTHING_STILL;
    bool saturation = true;
    int element;

    for (element=0; element<BOARD_SIZE; ++element)
    {
        if (!(board[element]=='x' || board[element]=='o'))
        {
            saturation = false;
        }
    }

    if (board[0]==board[1]&& board[1]==board[2])
        state=HAS_WINNER;
    else if (board[3]==board[4] && board[4]==board[5])
        state=HAS_WINNER;
    else if (board[6]==board[7] && board[7]==board[8])
        state=HAS_WINNER;
    else if (board[0]==board[3] && board[3] ==board[6])
        state=HAS_WINNER;
    else if (board[1]==board[4] && board[4]==board[7])
        state=HAS_WINNER;
    else if (board[2]==board[5] && board[5]==board[8])
        state=HAS_WINNER;
    else if (board[0]==board[4] && board[4]==board[8])
        state=HAS_WINNER;
    else if (board[2]==board[4] && board[4]==board[6])
        state=HAS_WINNER;
    else if (saturation==true)
        state=DRAW;

    return state;
}
