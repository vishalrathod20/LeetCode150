class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int longest = 1;
        int currLength = 1;

        for(int i = 1; i<nums.size(); i++)
        {
               if(nums[i] == nums[i-1]){
                   continue;
               }
               else if(nums[i]== nums[i-1]+1){
                currLength++;
               }
               else{
                longest = max(longest,currLength);
                currLength = 1;
               }
        }
        return max(longest,currLength);
    }
};
Time complexity = nlogn and sc = O(1)


****************************************************************************************************************************************************************************************************************


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        unordered_set<int> num_set(nums.begin(),nums.end());
        int longest = 0;

        for(int num: num_set)
        {
               if(num_set.find(num-1) == num_set.end()){
                   int current_num = num;
                   int current_length = 1;
               
               while(num_set.find(current_num + 1) != num_set.end()){
                 ++current_num;
                 ++current_length;
               }
               longest = max(longest , current_length);
            }
        }
        return longest;
    }
};
using hasmap TC :- O(n) and sc :- O(n)
