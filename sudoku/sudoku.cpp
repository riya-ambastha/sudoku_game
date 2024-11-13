#include "sudoku.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Sudoku::Sudoku() {
    // Initialize an empty board
    board = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
    solution = board;
    generatePuzzle();
}

void Sudoku::displayBoard() {
    std::cout << "\nSudoku Board:\n";
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << (board[i][j] ? std::to_string(board[i][j]) : ".") << " ";
        }
        std::cout << "\n";
    }
}

bool Sudoku::isValidMove(int row, int col, int num) {
    for (int x = 0; x < 9; ++x) {
        if (board[row][x] == num || board[x][col] == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

bool Sudoku::solveSudoku() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isValidMove(row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku())
                            return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void Sudoku::generatePuzzle() {
    solveSudoku();
    solution = board;

    srand(time(0));
    for (int i = 0; i < 20; ++i) {
        int row = rand() % 9;
        int col = rand() % 9;
        board[row][col] = 0;
    }
}

void Sudoku::startNewGame() {
    board = solution;
    displayBoard();
    while (!isComplete()) {
        int row, col, num;
        std::cout << "Enter row (0-8), column (0-8), and number (1-9): ";
        std::cin >> row >> col >> num;

        if (row < 0 || row > 8 || col < 0 || col > 8 || num < 1 || num > 9) {
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        if (board[row][col] == 0 && isValidMove(row, col, num)) {
            makeMove(row, col, num);
            displayBoard();
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }
    std::cout << "Congratulations! You completed the puzzle.\n";
}

void Sudoku::makeMove(int row, int col, int num) {
    if (board[row][col] == 0 && isValidMove(row, col, num)) {
        board[row][col] = num;
    }
}

bool Sudoku::isComplete() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0)
                return false;
        }
    }
    return true;
}
