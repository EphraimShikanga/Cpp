#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>



std::vector<std::string> generateChessboard(int size) {
    std::vector<std::string> chessboard;
    for (int i = 0; i < size; ++i) {
        std::string row(size * 3, ' ');
        for (int j = 0; j < size; ++j) {
            row[j * 3 + 1] = '|';
        }
        chessboard.push_back(row);
    }
    return chessboard;
}

void printChessboard(const std::vector<std::string>& chessboard) {
    for (const std::string& row : chessboard) {
        std::cout << row << std::endl;
    }
}

void userInput(std::vector<std::string>& chessboard) {
    int row, col;
    std::cout << "Enter the row number (0-" << chessboard.size() - 1 << "): ";
    std::cin >> row;
    std::cout << "Enter the column number (0-" << chessboard[0].size() / 3 - 1 << "): ";
    std::cin >> col;

    if (row >= 0 && row < chessboard.size() && col >= 0 && col < chessboard[0].size() / 3) {
        chessboard[row * 2 + 1][col * 3 + 2] = 'Q';
        std::cout << "Queen placed successfully!" << std::endl;
    } else {
        std::cout << "Invalid position! Please try again." << std::endl;
    }
}

bool isValidSolution(const std::vector<std::string>& chessboard) {
    int n = chessboard.size();
    
    // Count the number of queens in each row
    std::vector<int> queenCount(n, 0);
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (chessboard[row * 2 + 1][col * 3 + 2] == 'Q') {
                queenCount[row]++;
            }
        }
    }
    
    // Check if each row has exactly one queen
    for (int row = 0; row < n; ++row) {
        if (queenCount[row] != 1) {
            return false;
        }
    }
    
    // Check for diagonal conflicts
    for (int row1 = 0; row1 < n - 1; ++row1) {
        for (int row2 = row1 + 1; row2 < n; ++row2) {
            for (int col1 = 0; col1 < n; ++col1) {
                for (int col2 = 0; col2 < n; ++col2) {
                    if (chessboard[row1 * 2 + 1][col1 * 3 + 2] == 'Q' &&
                        chessboard[row2 * 2 + 1][col2 * 3 + 2] == 'Q') {
                        if (std::abs(row1 - row2) == std::abs(col1 - col2)) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    
    return true;
}

int main() {
    int n;
    std::cout << "Enter the size of the chessboard (N): ";
    std::cin >> n;
    
    std::vector<std::string> chessboard = generateChessboard(n);
    
    while (true) {
        printChessboard(chessboard);
        userInput(chessboard);
        if (isValidSolution(chessboard)) {
            std::cout << "Congratulations! You have found a valid solution!" << std::endl;
            break;
        }
    }
    
    return 0;
}