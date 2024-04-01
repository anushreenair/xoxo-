#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to draw the tic-tac-toe board
void drawBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if there's a winner
char checkWinner(const vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] != '.' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // No winner
    return '.';
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '.')); // Initialize empty board
    char currentPlayer = 'X'; // 'X' starts the game

    // Main game loop
    while (true) {
        drawBoard(board);
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (e.g., 1 2): ";
        int row, col;
        cin >> row >> col;

        // Check if input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '.') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Update board
        board[row - 1][col - 1] = currentPlayer;

        // Check for winner
        char winner = checkWinner(board);
        if (winner != '.') {
            drawBoard(board);
            cout << "Player " << winner << " wins!" << endl;
            break;
        }

        // Check for draw
        bool draw = true;
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == '.') {
                    draw = false;
                    break;
                }
            }
            if (!draw) break;
        }
        if (draw) {
            drawBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
