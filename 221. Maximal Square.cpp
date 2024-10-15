class Solution {
private:
    // Tabulation approach to find the largest square
    int solveTab(vector<vector<char>>& matrix) {
        int m = matrix.size(); // Number of rows in the matrix
        if (m == 0) return 0; // Handle edge case of empty matrix
        int n = matrix[0].size(); // Number of columns in the matrix
        
        // DP table to store the size of the largest square ending at each cell
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSide = 0; // To keep track of the maximum side length of the square

        // Fill the DP table
        for (int i = 0; i < m; i++) { // Iterate over each row
            for (int j = 0; j < n; j++) { // Iterate over each column
                // Check if the current cell is '1' (part of a square)
                if (matrix[i][j] == '1') {
                    // If we are at the first row or first column, the largest square is 1 if it's '1'
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // Square size is 1 for '1' in first row/column
                    } else {
                        // Update the DP value to be the minimum of three neighbors plus one
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                        // This means we can form a larger square with the current cell as the bottom-right corner
                    }
                    // Update max side length found
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        // Return the area of the largest square
        return maxSide * maxSide; // Area is side length squared
    }

public:
    // Public method to initiate the solution process
    int maximalSquare(vector<vector<char>>& matrix) {
        return solveTab(matrix);  // Call the solveTab function to compute the result
    }
};
