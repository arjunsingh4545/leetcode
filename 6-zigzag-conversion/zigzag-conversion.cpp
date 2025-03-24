class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.size()) {
            return s;
        }

        // Create a vector of strings to hold each row
        std::vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        // Iterate through each character in the string
        for (char c : s) {
            // Append the character to the current row
            rows[currentRow] += c;

            // Change direction if we are at the top or bottom row
            if (currentRow == 0) {
                goingDown = true;
            } else if (currentRow == numRows - 1) {
                goingDown = false;
            }

            // Move to the next row
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows to get the final result
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};