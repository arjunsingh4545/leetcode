class Solution {
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') { // Find an empty cell
                    for (char c = '1'; c <= '9'; ++c) { // Try digits 1-9
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c; // Place the digit
                            if (solve(board)) { // Recursively try to solve
                                return true;
                            }
                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid number found, need to backtrack
                }
            }
        }
        return true; // Solved
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        // Check the row and column
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == c || board[i][col] == c) {
                return false;
            }
        }
        // Check the 3x3 sub-box
        int boxRowStart = (row / 3) * 3;
        int boxColStart = (col / 3) * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[boxRowStart + i][boxColStart + j] == c) {
                    return false;
                }
            }
        }
        return true; // Valid placement
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};