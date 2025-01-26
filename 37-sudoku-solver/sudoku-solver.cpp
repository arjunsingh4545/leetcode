class Solution {
     bool solve(vector<vector<char>>& board, array<array<bool, 9>, 9>& rows,
               array<array<bool, 9>, 9>& cols, array<array<bool, 9>, 9>& boxes) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') { // Find an empty cell
                    for (int num = 0; num < 9; ++num) { // Try digits 1-9
                        if (!rows[r][num] && !cols[c][num] && !boxes[(r / 3) * 3 + (c / 3)][num]) {
                            // Place the digit
                            board[r][c] = num + '1'; // Convert int to char
                            rows[r][num] = true;
                            cols[c][num] = true;
                            boxes[(r / 3) * 3 + (c / 3)][num] = true;

                            // Recursively try to solve
                            if (solve(board, rows, cols, boxes)) {
                                return true;
                            }

                            // Backtrack
                            board[r][c] = '.';
                            rows[r][num] = false;
                            cols[c][num] = false;
                            boxes[(r / 3) * 3 + (c / 3)][num] = false;
                        }
                    }
                    return false; // No valid number found, need to backtrack
                }
            }
        }
        return true; // Solved
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Initialize the tracking arrays
        array<array<bool, 9>, 9> rows = {};
        array<array<bool, 9>, 9> cols = {};
        array<array<bool, 9>, 9> boxes = {};

        // Fill the tracking arrays with existing numbers
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '1'; // Convert char to int (0-8)
                    rows[r][num] = true;
                    cols[c][num] = true;
                    boxes[(r / 3) * 3 + (c / 3)][num] = true;
                }
            }
        }

        // Start solving the Sudoku
        solve(board, rows, cols, boxes);

    }
};