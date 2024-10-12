class Solution {
    int recursions(vector<int>& coins, int amount) {
        if (amount == 0) return 0; // No coins needed for 0 amount
        if (amount < 0) return -1;  // Cannot form this amount

        int minCoin = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            int res = recursions(coins, amount - coins[i]); // Corrected the recursive call

            // Check if res is valid (not -1)
            if (res >= 0) {
                minCoin = min(minCoin, res + 1); 
            }
        }

        return (minCoin == INT_MAX) ? -1 : minCoin; // If minCoin is unchanged, return -1
    }
    
  int recursionDp(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0; // Base case: no coins needed for amount 0
        if (amount < 0) return -1;  // Base case: can't form negative amount
        if (dp[amount] != -1) return dp[amount]; // Return already computed result

        int minCoin = INT_MAX; // Initialize minCoin to maximum value

        for (int i = 0; i < coins.size(); i++) {
            int res = recursionDp(coins, amount - coins[i], dp); // Recursive call

            if (res >= 0) { // Valid result found
                minCoin = min(minCoin, res + 1); // Update minCoin
            }
        }

        // If minCoin remains unchanged, return -1
        dp[amount] = (minCoin == INT_MAX) ? -1 : minCoin;
        return dp[amount];
    }

    int recursionTab(vector<int>&coins,int amount){
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;

        for(int i = 0; i<= amount; i++){
            for(int coin : coins){
                if(i-coin>=0){
                    if(dp[i-coin]!= INT_MAX)
                    {
                       dp[i] = min(dp[i],dp[i-coin]+1);
                    }
                }
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,-1);
        return recursionTab(coins, amount);
    }
};
