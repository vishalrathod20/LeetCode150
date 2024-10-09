class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

    // Convert the integer to a string
    std::string s = std::to_string(x);
    
    // Reverse the string
    std::string rev_s = s;
    std::reverse(rev_s.begin(), rev_s.end());

    // Check if the original string is equal to the reversed string
    return s == rev_s;
    }
};
