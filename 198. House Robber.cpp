class Solution {
    // Recursive function to solve the problem without memoization
    int recursions(vector<int>& nums, int n) {
        // Base case: If we've gone out of bounds, return 0
        if (n < 0) return 0;

        // Recurrence relation: choose to rob the current house or skip it
        // We check both possibilities: 
        // 1. Skip the current house (n-1)
        // 2. Rob the current house (nums[n]) and add the maximum from the house before the previous one (n-2)
        return max(recursions(nums, n - 1), nums[n] + recursions(nums, n - 2));
    }

    // Recursive function with memoization to avoid redundant calculations
    int recursionMemo(vector<int>& nums, int n, vector<int>& dp) {
        // Base case: If we've gone out of bounds, return 0
        if (n < 0) return 0;

        // Check if the result for this subproblem is already computed
        if (dp[n] != -1) {
            return dp[n]; // Return the stored value
        }

        // Calculate the maximum money that can be robbed and store it in dp
        dp[n] = max(recursionMemo(nums, n - 1, dp), nums[n] + recursionMemo(nums, n - 2, dp));
        
        return dp[n]; // Return the computed maximum
    }

    // Dynamic Programming approach using a bottom-up table
    int recursionTab(vector<int>& nums) {
        int n = nums.size();
        // Handle base cases
        if (n == 0) return 0;  // No houses to rob
        if (n == 1) return nums[0]; // Only one house available

        // Initialize the DP table
        vector<int> dp(n, 0);
        dp[0] = nums[0]; // Maximum money that can be robbed from the first house
        dp[1] = max(nums[0], nums[1]); // Maximum money that can be robbed from the first two houses

        // Fill the DP table for houses from index 2 to n-1
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]); 
            // Compare not robbing the current house (dp[i-1]) 
            // and robbing the current house (nums[i] + dp[i-2])
        }
        return dp[n - 1]; // Return the maximum money that can be robbed from all houses
    }
    
    // Optimized Dynamic Programming approach using constant space
    int recursionTab2(vector<int>& nums) {
        int n = nums.size();

        // Handle base cases
        if (n == 0) return 0;  // No houses to rob
        if (n == 1) return nums[0]; // Only one house available

        // Initialize previous values for the first and second houses
        int prev1 = nums[0]; // Maximum money that can be robbed from the first house
        int prev2 = max(nums[0], nums[1]); // Maximum money that can be robbed from the first two houses

        // Iterate through the houses starting from the third house
        for (int i = 2; i < n; i++) {
            int current = nums[i]; // Money in the current house
            int temp = prev2; // Store the previous maximum before updating
            
            // Update prev2 to the maximum of robbing the current house or not
            prev2 = max(prev2, prev1 + current); 
            // Update prev1 to the old value of prev2
            prev1 = temp;  
        }
        return prev2; // Return the maximum amount robbed
    }

public:
    // Main function to determine the maximum amount that can be robbed
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); // Initialize memoization table with -1
        // Uncomment the line for the desired approach
        // return recursions(nums, n - 1);  // Start from the last house (n-1)
        // return recursionMemo(nums, n - 1, dp); // Use memoized recursion
        // return recursionTab(nums); // Use bottom-up dynamic programming

        return recursionTab2(nums); // Use optimized dynamic programming
    }
};
