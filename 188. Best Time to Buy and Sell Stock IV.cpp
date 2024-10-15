class Solution {
private:
    // Tabulation approach
    int solveTab(int k, vector<int>& prices) {
        int n = prices.size();
        
        // If there are no prices or no transactions allowed, profit is 0
        if (n == 0 || k == 0) return 0;

        // If k is greater than half the number of days, we can treat it as unlimited transactions
        if (k >= n / 2) {
            int maxProfit = 0;  // Variable to accumulate maximum profit
            for (int i = 1; i < n; i++) {
                // Sum up all profitable transactions
                if (prices[i] > prices[i - 1]) {
                    maxProfit += prices[i] - prices[i - 1]; // Buy the stock and sell at the next price if it's higher
                }
            }
            return maxProfit; // Return the accumulated profit for unlimited transactions
        }

        // Initialize the DP table
        // dp[index][buy][limit] where:
        // index: the current day (0 to n)
        // buy: whether we can buy (1) or sell (0)
        // limit: the maximum number of transactions left
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        // Fill the DP table from the last day to the first day
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) { // Loop over buy (0 = sell, 1 = buy)
                for (int limit = 1; limit <= k; limit++) { // Loop over the allowed transactions
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

        // The answer is in the first day, with the ability to buy and with `k` transactions remaining.
        return dp[0][1][k];  // Return maximum profit with k transactions starting from day 0
    }

public:
    // Public method to calculate the maximum profit
    int maxProfit(int k, vector<int>& prices) {
        return solveTab(k, prices);  // Call the solveTab function to compute the profit
    }
};
