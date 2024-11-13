#include <iostream>
#include "sudoku.h"

void displayMenu() {
    std::cout << "Welcome to the Sudoku Game!\n";
    std::cout << "1. Start New Game\n";
    std::cout << "2. Instructions\n";
    std::cout << "3. Quit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;
    Sudoku game;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                game.startNewGame();
                break;
            case 2:
                std::cout << "Fill the 9x9 grid with digits from 1 to 9.\n";
                std::cout << "Each row, column, and 3x3 sub-grid must contain unique numbers.\n";
                break;
            case 3:
                std::cout << "Thank you for playing!\n";
                return 0;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
