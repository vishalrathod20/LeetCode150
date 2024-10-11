class Solution {
    // Recursive approach without memoization: very inefficient for large n due to overlapping subproblems.
    int recursive(int n) {
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        // Recursive relation: adding results of previous two steps
        return recursive(n - 1) + recursive(n - 2);
    }

    // Recursive approach with memoization: stores previously calculated results in dp array.
    int recursionMEMO(int n, vector<int> dp) {
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        // If result for current n is already computed, return it to avoid recomputation
        if (dp[n] != -1) {
            return dp[n];
        }

        // Otherwise, compute the result and store it in dp array
        dp[n] = recursionMEMO(n - 1, dp) + recursionMEMO(n - 2, dp);
        return dp[n];
    }

    // Tabulation (Bottom-up DP): iteratively fill the dp array based on previous results
    int recursionTab(int n) {
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        // Create a dp array to store results from 1 to n
        vector<int> dp(n + 1, 0);  
        dp[1] = 1;
        dp[2] = 2;

        // Fill dp array by summing up previous two values for each step
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return the final result stored at dp[n]
        return dp[n]; 
    }

    // Optimized tabulation: reduces space complexity by using only two variables instead of a dp array
    int recursionTab2(int n) {
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        // Variables to store previous two results
        int prev1 = 1;
        int prev2 = 2;

        // Iterate and calculate current step using prev1 and prev2, then update them accordingly
        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev1 = prev2;  // Update prev1 to prev2 (moving forward)
            prev2 = current;  // Update prev2 to current (moving forward)
        }

        // Return the last calculated value which is the final result
        return prev1;
    }

public:
    // Main function to calculate the number of ways to climb stairs
    int climbStairs(int n) {
        // You can choose any approach here: 
        // 1. recursive(n) 
        // 2. recursionMEMO(n, vector<int>(n+1, -1)) 
        // 3. recursionTab(n) 
        // 4. recursionTab2(n) 
        return recursionTab(n);  // Using tabulation for efficiency
    }
};
