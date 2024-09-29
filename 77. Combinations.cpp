class Solution {
    void findCombination(int start, int n, int k, vector<int> &currentComb,vector<vector<int>> &result){
        if(currentComb.size()==k){
            result.push_back(currentComb);
            return;
        }

        for(int i = start; i<=n; ++i){
            currentComb.push_back(i);

            findCombination(i+1, n, k, currentComb, result);

            currentComb.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> currentComb;

        findCombination(1,n,k,currentComb, result);
        return result;
    }
};
