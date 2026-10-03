class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> squares[9];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                if (board[r][c] == '.')
                    continue;

                char num = board[r][c];

                // Find which 3x3 square this belongs to
                int squareIndex = (r / 3) * 3 + (c / 3);

                // Check if number already exists
                if (rows[r].count(num) ||
                    cols[c].count(num) ||
                    squares[squareIndex].count(num)) {
                    return false;
                }

                // Add number to all 3
                rows[r].insert(num);
                cols[c].insert(num);
                squares[squareIndex].insert(num);
            }
        }

        return true;
    }
};