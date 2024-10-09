class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto i = mp.begin(); i != mp.end(); i++) {
            if (i->second == 1) {
                return i->first;
                
                break;
            }
        }
            return -1;
    }
};
