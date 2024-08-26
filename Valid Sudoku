class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Create sets to keep track of seen digits
        unordered_set<string> rows[9], cols[9], boxes[9];
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.') continue;
                
                // Convert char to string
                string str(1, ch);
                
                // Check if the digit is already seen in the current row, column, or box
                if (rows[i].count(str) || cols[j].count(str) || boxes[i / 3 * 3 + j / 3].count(str)) {
                    return false;
                }
                
                // Mark the digit as seen
                rows[i].insert(str);
                cols[j].insert(str);
                boxes[i / 3 * 3 + j / 3].insert(str);
            }
        }
        
        return true;
    }
};
