class Solution {
    int kadane_maxSum(vector<int>& nums){
        int currentMax = nums[0];
        int Globalmax = nums[0];

        for(int i = 1; i<nums.size(); i++){
            currentMax = max(nums[i],currentMax+nums[i]);
            Globalmax = max(Globalmax,currentMax);
        }
        return Globalmax;
    }

    int kadane_minSum(vector<int>&nums){
        int currentMin = nums[0];
        int GlobalMin = nums[0];
        for(int i = 1; i<nums.size(); i++){
            currentMin = min(nums[i],currentMin+nums[i]);
            GlobalMin = min(GlobalMin,currentMin);
        }
        return GlobalMin;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;
        int maxSum = kadane_maxSum(nums);
        int minSum = kadane_minSum(nums);

        for(int num : nums){
            total_sum+=num;
        }

        if(total_sum == minSum){
           return maxSum;
        }
        return max(maxSum,total_sum-minSum);
    }
};
