class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n = nums.size();
        int start = 0;
        int current_sum = 0; 

        int min_length = INT_MAX;
        for(int end = 0; end<n; end++){
             current_sum += nums[end];
             while(current_sum>=target){
                min_length = min(min_length, end-start+1);
                current_sum -=nums[start];
                start++; 
             } 
        }
        return (min_length == INT_MAX) ? 0 : min_length;
    }
};
