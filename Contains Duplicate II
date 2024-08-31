class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> num_Map;//create map
        //traverse the array
        for(int i = 0; i<nums.size(); i++){
            if(num_Map.find(nums[i])!=num_Map.end()){
                if(abs(i-num_Map[nums[i]])<=k){
                    return true;
                }
            }
            num_Map[nums[i]] = i;// update the hasmap
        }
        return false;
    }
};
