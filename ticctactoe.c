#include<stdio.h>
#include<string.h>

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void display_board() {
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);
    printf("     |     |     \n");
}

int checkwin() {
    // Checking all possible winning combinations
    if (board[1] == board[2] && board[2] == board[3]) return 1;
    if (board[4] == board[5] && board[5] == board[6]) return 1;
    if (board[7] == board[8] && board[8] == board[9]) return 1;
    if (board[1] == board[4] && board[4] == board[7]) return 1;
    if (board[2] == board[5] && board[5] == board[8]) return 1;
    if (board[3] == board[6] && board[6] == board[9]) return 1;
    if (board[1] == board[5] && board[5] == board[9]) return 1;
    if (board[3] == board[5] && board[5] == board[7]) return 1;

    // Checking for draw (if all cells are filled and no winner)
    for (int i = 1; i <= 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') return 0; // Game is still ongoing
    }
    return -1; // Draw
}

int main() {
    int player = 1, result = 0;
    display_board();
    int input;

    while (1) {
        player = (player % 2 == 1) ? 1 : 2;
        char mark = (player == 1) ? 'X' : 'O';

        printf("Enter position for player %d: ", player);
        scanf("%d", &input);

        // Check for valid input and unoccupied position
        if (input < 1 || input > 9 || board[input] == 'X' || board[input] == 'O') {
            printf("Invalid input, try again.\n");
            continue;
        }

        // Place the mark on the board
        board[input] = mark;
        display_board();

        // Check for a winner or a draw
        result = checkwin();
        if (result == 1) {
            printf("Player %d wins!\n", player);
            break;
        } else if (result == -1) {
            printf("It's a draw!\n");
            break;
        }

        // Switch player
        player++;
    }
    return 0;
}
