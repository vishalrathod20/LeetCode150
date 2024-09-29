class Solution {
    void findCombination(int index,int target, vector<int>& candidates,vector<int> currentComb, vector<vector<int>> &result){
        if(target == 0){
            result.push_back(currentComb);
            return;
        }

        for(int i = index; i<candidates.size(); ++i){
            if(candidates[i]>target){
                continue;
            }

            currentComb.push_back(candidates[i]);

            findCombination(i, target-candidates[i],candidates,currentComb, result);

            currentComb.pop_back();
        }


    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentComb;

        findCombination(0, target, candidates, currentComb, result);
        return result;
    }
};
