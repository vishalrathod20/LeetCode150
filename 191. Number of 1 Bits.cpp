class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);  // Turn off the rightmost set bit
            count++;
        }
        return count;
    }
};
