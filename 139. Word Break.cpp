class Solution {
    // Recursive utility function to check if a string can be segmented
    bool wordBreakUtil(string s, unordered_set<string>& wordset) {
        // Base case: if the string is empty, we can segment it (no words needed)
        if (s.empty()) return true;

        // Check each prefix of the string
        for (int i = 1; i <= s.length(); i++) {
            string prefix = s.substr(0, i); // Extract prefix from start to i
            // If the prefix is found in the word set and the rest of the string can also be segmented
            if (wordset.find(prefix) != wordset.end() && wordBreakUtil(s.substr(i), wordset)) {
                return true; // Return true if both conditions are satisfied
            }
        }
        return false; // Return false if no valid prefix found
    }

    // Memoization utility function to improve efficiency of the recursive solution
    bool wordBreakUtilmemo(string s, unordered_set<string>& wordset, vector<int>& dp, int start) {
        // Base case: if 'start' index equals the length of the string, we've segmented the entire string
        if (start == s.length()) return true;

        // Return cached result if already computed for the current start index
        if (dp[start] != -1) return dp[start];

        // Check each possible prefix starting from 'start' index
        for (int i = start + 1; i <= s.length(); i++) {
            string prefix = s.substr(start, i - start); // Extract prefix
            // If prefix is in word set and the remaining string can be segmented
            if (wordset.find(prefix) != wordset.end() && wordBreakUtilmemo(s, wordset, dp, i)) {
                return dp[start] = true; // Cache the result as true
            }
        }
        return dp[start] = false; // Cache the result as false if no valid segmentation found
    }

    // Dynamic programming approach to solve the word break problem iteratively
    bool wordBreakUtilTab(string s, unordered_set<string>& wordset) {
        vector<bool> dp(s.length() + 1, false); // DP array to track segmentation
        dp[0] = true; // Base case: an empty string can always be segmented

        // Loop over each length of substring
        for (int i = 1; i <= s.length(); i++) {
            // Loop over possible split points to check valid prefixes
            for (int j = 0; j < i; j++) {
                string prefix = s.substr(j, i - j); // Get substring from j to i
                // If prefix is in word set and the substring up to j can be segmented
                if (wordset.find(prefix) != wordset.end() && dp[j]) {
                    dp[i] = true; // Mark dp[i] as true indicating valid segmentation
                    break; // No need to check further for this i
                }
            }
        }
        return dp[s.length()]; // Return if the entire string can be segmented
    }

public:
    // Main function to check if the string can be segmented into words from the dictionary
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end()); // Convert vector to unordered set for O(1) lookup
        vector<int> dp(s.length(), -1); // Initialize memoization array with -1 (indicating not computed)
        return wordBreakUtilTab(s, wordset); // Call the dynamic programming approach to solve the problem
    }
};
