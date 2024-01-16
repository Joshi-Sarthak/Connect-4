#include <iostream>

using namespace std;

const int row = 6;
const int col = 7;
char token = 'X';
int counter = 0;

// Function for names of players
void players(char player1[], char player2[])
{
    cout << "Enter name of player 1: ";
    cin.getline(player1, 20);

    cout << "Enter name of player 2: ";
    cin.getline(player2, 20);

    cout << "\n\nX is assigned to " << player1 << "\n";
    cout << "O is assigned to " << player2 << "\n";
}

// Function to declare rules
void rules()
{
    cout << "\n\nBefore you can start playing Connect Four, make sure to understand the rules.\n";
    cout << "To win, a player must get four checkers of their symbol in a row horizontally, vertically, or diagonally.\n\n\n";
}

// Actual layout of the game
void ShowBoard(char board[][col])
{
    cout << "  1   2   3   4   5   6   7  \n";
    cout << "|---|---|---|---|---|---|---|\n";
    for (int i = 0; i < row; i++)
    {
        cout << "| " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " | " << board[i][3] << " | " << board[i][4] << " | " << board[i][5] << " | " << board[i][6] << " |\n";
        cout << "|---|---|---|---|---|---|---|\n";
    }
}
// Function to enter moves of the users
int moves(char board[][col], int &input)
{
    cin >> input;

    // Check if the user's input is a valid position on the game board
    if (input < 1 || input > 7)
    {
        // Input is not a valid position, display an error message
        cout << "Invalid move!\n";
        return 0;
    }

    counter++;
    // This part works its way up from bottom and replaces when it finds a 'blank space' with the user's token
    for (int i = (row - 1); i >= 0; i--)
    {
        if (board[i][input - 1] == ' ')
        {
            board[i][input - 1] = token;
            break;
        }
    }
    if (token == 'X')
    {
        token = 'O';
    }
    else
    {
        token = 'X';
    }

    return 1;
}

int CheckWin(char board[][col])
{
    // Checking for row wins
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col - 3; j++)
        {
            if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3] && board[i][j] != ' ')
            {
                return 1;
            }
        }
    }

    // Checking for column wins
    for (int i = 0; i < row - 3; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i + 2][j] == board[i + 3][j] && board[i][j] != ' ')
            {
                return 1;
            }
        }
    }

    // Check for Diagonal 1 win
    for (int i = 3; i < row; i++)
    {
        for (int j = 0; j < col - 3; j++)
        {
            if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i - 2][j + 2] && board[i - 2][j + 2] == board[i - 3][j + 3] && board[i][j] != ' ')
            {
                return 1;
            }
        }
    }

    // Check for Diagonal 2 win
    for (int i = 0; i < row - 3; i++)
    {
        for (int j = 0; j < col - 3; j++)
        {
            if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3] && board[i][j] != ' ')
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    cout << "\n-------------------------------------------------------------------\n\n";
    cout << "\t\t\t Connect-4\n";
    cout << "\n-------------------------------------------------------------------\n\n";

    int input;
    char player1[20];
    char player2[20];

    char board[row][col];

    // Actual logic
    int gameover = 1;
    players(player1, player2);
    rules();

    while (gameover)
    {
        // Assigning blank space to all array elements
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                board[i][j] = ' ';
            }
        }

        ShowBoard(board);

        while (CheckWin(board) != 1)
        {

            cout << "Enter your move (1-7): ";
            if (moves(board, input))
            {
                system("cls");
                ShowBoard(board);
            }
        }

        if (counter == 41)
        {
            cout << "\n\nThe game ends in a draw\n";
        }
        else
        {
            if (token == 'X')
            {
                cout << "\n\nCongrats! " << player2 << ", you WON\n";
            }
            else
            {
                cout << "\n\nCongrats! " << player1 << ", you WON\n";
            }
        }

        for (int i = 0; i < 10; i++)
        {
            cout << "\n";
        }

        cout << "Do you want to play again?\n";
        cout << "Press 1 for YES and 0 for NO: ";
        cin >> gameover;
    }

    return 0;
}