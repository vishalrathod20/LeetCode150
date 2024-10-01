class Solution {
    bool dfs(vector<vector<char>>& board, int i, int j, int index, string word) {
        if (index == word.size()) {
            return true;
        }
        // Boundary conditions: out of bounds or character mismatch
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        // Save the current character and mark it as visited
        char temp = board[i][j];
        board[i][j] = '*';  // Mark visited by changing the character

        // Check in all four directions
        bool found = dfs(board, i + 1, j, index + 1, word) ||
                     dfs(board, i - 1, j, index + 1, word) ||
                     dfs(board, i, j + 1, index + 1, word) ||
                     dfs(board, i, j - 1, index + 1, word);

        // Restore the character (backtrack)
        board[i][j] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // Start DFS from each cell
                if (dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};
