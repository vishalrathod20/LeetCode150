class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> CharIndexMap;
        int max_length = 0;
        int start = 0; 

        for(int end = 0; end<s.length(); end++){
            char currentChar = s[end];
            
            if(CharIndexMap.count(currentChar) && CharIndexMap[currentChar]>=start){
                start = CharIndexMap[currentChar]+1;
            }
            CharIndexMap[currentChar] = end;

            max_length = max(max_length,end-start+1);
        }  
        return max_length;
    }
};
