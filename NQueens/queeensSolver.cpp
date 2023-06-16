#include <iostream>
#include <vector>

bool isSafe(const std::vector<int>& board, int row, int col) {
    // Check if the current position is safe from attacks
    for (int i = 0; i < row; ++i) {
        // Check if there is a queen in the same column or in diagonal positions
        if (board[i] == col || board[i] - col == i - row || board[i] - col == row - i) {
            return false;
        }
    }
    return true;
}

void solveNQueensUtil(std::vector<std::vector<int>>& solutions, std::vector<int>& board, int row, int n) {
    if (row == n) {
        // Found a solution, add it to the solutions vector
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            // Place the queen in the current position
            board[row] = col;

            // Recur for the next row
            solveNQueensUtil(solutions, board, row + 1, n);

            // Backtrack and try the next column
            board[row] = -1;
        }
    }
}

std::vector<std::vector<int>> solveNQueens(int n) {
    std::vector<std::vector<int>> solutions;
    std::vector<int> board(n, -1);

    solveNQueensUtil(solutions, board, 0, n);

    return solutions;
}

void printSolution(const std::vector<int>& board) {
    int n = board.size();
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (board[row] == col) {
                std::cout << "Q ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int boardSize() {
    int n;
    std::cout << "Enter the size of the chessboard (N): ";
    std::cin >> n;
    return n;
}

int main() {
    // int n = boardSize();
    int n = 14;
    std::vector<std::vector<int>> solutions = solveNQueens(n);

    int numSolutions = solutions.size();
    std::cout << "Number of solutions: " << numSolutions << std::endl;

    std::cout << "Solutions:" << std::endl;
    if (numSolutions > 10)
    {
        for (int i = 0; i < 10; ++i) {
            std::cout << "Solution " << (i + 1) << ":" << std::endl;
            printSolution(solutions[i]);
        }
    } else {
        for (int i = 0; i < numSolutions; ++i) {
            std::cout << "Solution " << (i + 1) << ":" << std::endl;
            printSolution(solutions[i]);
        }
    }

    return 0;
}
