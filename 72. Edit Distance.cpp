class Solution {
    // Recursive approach (not used in the final solution)
    int solve(string a, string b, int i, int j) {
        // Base case: if we reach the end of string 'a'
        if (i == a.length()) {
            return b.length() - j; // We need to insert all remaining characters of 'b'
        }

        // Base case: if we reach the end of string 'b'
        if (j == b.length()) {
            return a.length() - i; // We need to delete all remaining characters of 'a'
        }

        int ans = 0;

        // If characters are the same, move to the next characters
        if (a[i] == b[j]) {
            return solve(a, b, i + 1, j + 1);
        } else {
            // Perform operations: insert, delete, replace
            int insertAns = solve(a, b, i, j + 1);
            int deleteAns = solve(a, b, i + 1, j);
            int replaceAns = solve(a, b, i + 1, j + 1);
            ans = 1 + min(insertAns, min(deleteAns, replaceAns)); // Take minimum of all operations
        }
        return ans; // Return the result
    }

    // Memoization approach (not used in the final solution)
    int solveMemo(string a, string b, int i, int j, vector<vector<int>>& dp) {
        // Base case: if we reach the end of string 'a'
        if (i == a.length()) {
            return b.length() - j; // Insert remaining characters of 'b'
        }

        // Base case: if we reach the end of string 'b'
        if (j == b.length()) {
            return a.length() - i; // Delete remaining characters of 'a'
        }

        // Check if already computed
        if (dp[i][j] != -1) {
            return dp[i][j]; // Return stored result
        }

        int ans = 0;

        // If characters are the same, no operation needed
        if (a[i] == b[j]) {
            return solveMemo(a, b, i + 1, j + 1, dp);
        } else {
            // Perform operations: insert, delete, replace
            int insertAns = solveMemo(a, b, i, j + 1, dp);
            int deleteAns = solveMemo(a, b, i + 1, j, dp);
            int replaceAns = solveMemo(a, b, i + 1, j + 1, dp);
            ans = 1 + min(insertAns, min(deleteAns, replaceAns)); // Take minimum of all operations
        }
        return ans; // Return the result
    }

    // Tabulation approach (dynamic programming)
    int solveTab(string a, string b) {
        int n = a.length(), m = b.length();

        // DP table size should be (n+1)x(m+1) to handle empty strings
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Initialize base cases:
        // If 'a' is empty, we need to insert all characters of 'b'
        for (int j = 0; j <= m; j++) {
            dp[n][j] = m - j; // Insertions required
        }

        // If 'b' is empty, we need to delete all characters of 'a'
        for (int i = 0; i <= n; i++) {
            dp[i][m] = n - i; // Deletions required
        }

        // Fill the DP table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    // If characters are the same, no operation needed
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    // Calculate the minimum of insert, delete, and replace operations
                    int insertAns = 1 + dp[i][j + 1];    // Insert character
                    int deleteAns = 1 + dp[i + 1][j];    // Delete character
                    int replaceAns = 1 + dp[i + 1][j + 1]; // Replace character
                    // Minimum of the three operations
                    dp[i][j] = min(insertAns, min(deleteAns, replaceAns));
                }
            }
        }

        // Result will be in dp[0][0], which is the minimum number of operations
        return dp[0][0];
    }

    // Space optimized Tabulation approach (using two 1D arrays)
    int solveTab2(string a, string b) {
        int n = a.length(), m = b.length();

        // We only need two 1D arrays: one for the previous row and one for the current row
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Initialize the base case for the last row (if 'a' is empty)
        for (int j = 0; j <= m; j++) {
            prev[j] = m - j;  // Number of insertions required if 'a' is empty
        }

        // Iterate over the rows of 'a' from bottom to top
        for (int i = n - 1; i >= 0; i--) {
            // Initialize the base case for the current row (if 'b' is empty)
            curr[m] = n - i;  // Number of deletions required if 'b' is empty

            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    curr[j] = prev[j + 1];  // If characters match, no operation needed
                } else {
                    // Calculate minimum of insert, delete, and replace operations
                    int insertAns = 1 + curr[j + 1];    // Insert character
                    int deleteAns = 1 + prev[j];        // Delete character
                    int replaceAns = 1 + prev[j + 1];   // Replace character
                    curr[j] = min(insertAns, min(deleteAns, replaceAns));
                }
            }

            // Copy current row into previous row for the next iteration
            prev = curr;
        }

        // The result will be in prev[0], which is the minimum operations to convert word1 to word2
        return prev[0];
    }

public:
    int minDistance(string word1, string word2) {
        // Initialize DP table for memoization (not used)
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        
        // Call the optimized tabulation method
        return solveTab2(word1, word2);
    }
};
