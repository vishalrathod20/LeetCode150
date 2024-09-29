class Solution {
    void backTracking(string&digits, int index,string current,vector<string>&result,unordered_map<char,string>&mapping){
        if(index == digits.size()){
            result.push_back(current);
            return;
        }
        
        string letters = mapping[digits[index]];

        for(char l : letters){
            backTracking(digits,index+1,current+l,result,mapping);
        }

    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()){
            return result;
        }
        unordered_map<char,string>mapping;
         mapping['2'] = "abc";
         mapping['3'] = "def";
         mapping['4'] = "ghi";
         mapping['5'] = "jkl";
         mapping['6'] = "mno";
         mapping['7'] = "pqrs";
         mapping['8'] = "tuv";
         mapping['9'] = "wxyz";

        backTracking(digits,0,"",result,mapping);
        return result;
    }
};
