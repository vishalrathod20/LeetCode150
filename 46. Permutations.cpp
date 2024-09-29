class Solution {
    void FindPermutations(vector<int>& nums, int index, vector<vector<int>> &result){
        if(index == nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i = index; i< nums.size(); i++){
            swap(nums[index],nums[i]);

            FindPermutations(nums,index+1,result);

            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        FindPermutations(nums,0,result);
        return result;
    }
};
