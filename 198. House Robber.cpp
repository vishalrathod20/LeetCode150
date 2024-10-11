class Solution {
    // Recursive function to solve the problem without memoization
    int recursions(vector<int>& nums, int n) {
        // Base case: If we've gone out of bounds, return 0
        if (n < 0) return 0;

        // Recurrence relation: choose to rob the current house or skip it
        // We check both possibilities: 
        // 1. Skip the current house (n-1)
        // 2. Rob the current house (nums[n]) and add the maximum from the house before the previous one (n-2)
        int steal = nums[n]+recursion(nums,n-2);
        int skip =  recursion(n-1);
        return max(skip,steal);
    }

    // Recursive function with memoization to avoid redundant calculations
    int recursionMemo(vector<int>& nums, int n, vector<int>& dp) {
        // Base case: If we've gone out of bounds, return 0
        if (n < 0) return 0;

        // Check if the result for this subproblem is already computed
        if (dp[n] != -1) {
            return dp[n]; // Return the stored value
        }

        int steal = nums[n] + recursionsMemo(nums, n - 2, dp);
        int skip = recursionsMemo(nums, n - 1, dp);

        // Store the maximum value in memo
        dp[n] = max(skip, steal);

        return dp[n]; // Return the computed maximum
    }

    // Dynamic Programming approach using a bottom-up table
    int recursionTab(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0]
        // Initialize the DP table
        vector<int> dp(n+1, 0);
        dp[0] = 0; // Maximum money that can be robbed from the first house
        dp[1] = nums[0]; // Maximum money that can be robbed from the first two houses

        // Fill the DP table for houses from index 2 to n-1
        for (int i = 2; i < n; i++) {
            int steal = nums[i-1]+dp[i-2];
            int skip = dp[i-1];
           dp[i] = max(steal,skip);
        }
        return dp[n]; // Return the maximum money that can be robbed from all houses
    }
    
    // Optimized Dynamic Programming approach using constant space
    int recursionTab2(vector<int>& nums) {
        int n = nums.size();
    if (n == 0) return 0;          // No houses to rob
    if (n == 1) return nums[0];    // Only one house to rob

    int prev1 = 0;  // Maximum money robbed up to the house before the last one
    int prev2 = 0;  // Maximum money robbed up to the last house

    // Iterate through the houses
    for (int i = 0; i < n; i++) {
        int steal = nums[i] + prev1; // Amount robbed if robbing the current house
        int skip = prev2;             // Amount robbed if skipping the current house
        int current = max(steal, skip); // Max amount robbed up to the current house
        
        // Update prev1 and prev2 for the next iteration
        prev1 = prev2; 
        prev2 = current;
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
