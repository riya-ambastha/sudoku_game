#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>

class Sudoku {
private:
    std::vector<std::vector<int>> board;
    std::vector<std::vector<int>> solution;

    bool isValidMove(int row, int col, int num);
    bool solveSudoku();
    void generatePuzzle();

public:
    Sudoku();
    void startNewGame();
    void displayBoard();
    bool isComplete();
    void makeMove(int row, int col, int num);
};

#endif // SUDOKU_H
