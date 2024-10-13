class Solution {
    // Recursive method (not used in the updated tabulation approach)
    int countPaths(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || obstacleGrid[i][j] == 1) return 0;

        if (i == 0 && j == 0) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int up = countPaths(obstacleGrid, i - 1, j, dp);
        int left = countPaths(obstacleGrid, i, j - 1, dp);

        dp[i][j] = up + left;
        return dp[i][j];
    }

    int countpathsTab(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case: Starting point
        dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        // Fill the first row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the first column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i - 1][0];
            }
        }

        // Fill the rest of the dp table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1]; // Return paths to the bottom-right corner
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If starting or ending point is blocked, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        return countpathsTab(obstacleGrid); // Using tabulation method
    }
};
