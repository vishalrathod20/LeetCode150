class Solution {
    int n;
    vector<vector<int>> memo;

    int solve(vector<int>& nums, int i, int p){
        if(i>=n) return 0;

        int take = 0;
        if(p == -1 || nums[i]>nums[p]){
            take = 1+solve(nums,i+1,i);
        }
        int skip = solve(nums,i+1,p);
        return max(take,skip);
    }
    
    int solveMemo(vector<int>& nums, int i, int p){
        if(i>=n) return 0;
        
        if (memo[i][p + 1] != -1) return memo[i][p + 1];  // Check if already computed

        int take = 0;
        if (p == -1 || nums[i] > nums[p]) {
            take = 1 + solve(nums, i + 1, i);
        }
        int skip = solve(nums, i + 1, p);
        return memo[i][p + 1] = max(take, skip);
    }

    int solveTab(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // Initialize the dp array
        vector<int> dp(n, 1); // Each element is at least an increasing subsequence of length 1 (itself)

        // Fill the dp array
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) { // Condition for increasing subsequence
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // The length of the longest increasing subsequence will be the maximum value in dp
        return *max_element(dp.begin(), dp.end());
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memo = vector<vector<int>>(n, vector<int>(n + 1, -1));
        return solveTab(nums);
    }
};
