class Solution {
    // Function to solve the problem using tabulation (3D DP array)
    int solveTab(vector<int>& prices) {
        int n = prices.size();
        
        // Initialize a 3D DP array
        // dp[index][buy][limit] where:
        // index: the current day (0 to n)
        // buy: whether we can buy (1) or sell (0)
        // limit: the maximum number of transactions left
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        // Fill the DP table from the last day to the first day
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 2; limit > 0; limit--) {
                    int profit = 0; // Variable to track the profit for this state
                    if (buy) {
                        // If we can buy on this day
                        // Option to buy or skip
                        int buyThis = -prices[index] + dp[index + 1][0][limit]; // Buy the stock
                        int skipThis = dp[index + 1][1][limit]; // Skip buying
                        profit = max(buyThis, skipThis); // Take the maximum profit
                    } else {
                        // If we can sell on this day
                        // Option to sell or skip
                        int sellThis = prices[index] + dp[index + 1][1][limit - 1]; // Sell the stock
                        int skipThis = dp[index + 1][0][limit]; // Skip selling
                        profit = max(sellThis, skipThis); // Take the maximum profit
                    }
                    dp[index][buy][limit] = profit; // Store the calculated profit
                }
            }
        }
        return dp[0][1][2]; // Return the maximum profit starting from day 0, with the ability to buy and 2 transactions left
    }

    // Function to solve the problem using space-optimized tabulation (2D DP arrays)
    int solveTab2(vector<int>& prices) {
        int n = prices.size();

        // Space-optimized DP: only two 2D arrays (curr and next)
        vector<vector<int>> curr(2, vector<int>(3, 0)); // Current state
        vector<vector<int>> next(2, vector<int>(3, 0)); // Next state

        // Fill the DP arrays from the last day to the first day
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 2; limit > 0; limit--) {
                    int profit = 0; // Variable to track the profit for this state
                    if (buy) {
                        // If we can buy on this day
                        // Option to buy or skip
                        int buyThis = -prices[index] + next[0][limit]; // Buy the stock
                        int skipThis = next[1][limit]; // Skip buying
                        profit = max(buyThis, skipThis); // Take the maximum profit
                    } else {
                        // If we can sell on this day
                        // Option to sell or skip
                        int sellThis = prices[index] + next[1][limit - 1]; // Sell the stock
                        int skipThis = next[0][limit]; // Skip selling
                        profit = max(sellThis, skipThis); // Take the maximum profit
                    }
                    curr[buy][limit] = profit; // Store the calculated profit
                }
            }
            // Move to the next state (copy curr to next for the next day)
            next = curr;
        }
        // Return the result from the initial state
        return curr[1][2]; // Maximum profit with the ability to buy and 2 transactions left
    }

public:
    // Public method to initiate profit calculation
    int maxProfit(vector<int>& prices) {
        return solveTab2(prices); // Call the optimized tabulation function
    }
};
