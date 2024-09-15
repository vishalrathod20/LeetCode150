link = https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

solution class Solution {
public:
    bool checkPal(char ch){
        if((ch>='a'&& ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
            return true;
        }
        else{
            return false;
        }
    }
    void toLowerCase(string &str) {
    for (char &c : str) {
        if (c >= 'A' && c <= 'Z') {
            c += ('a' - 'A');
        }
    }
}
    bool checkPalin(string str){
        int s = 0; 
        int e = str.length()-1;

        while(s<=e){
            if(str[s]!=str[e]){
                return false;
            }
            
            s++;
            e--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        
        string temp = "";

        for(int j = 0; j<s.length(); j++){
            if(checkPal(s[j])){
                temp.push_back(s[j]);
            }
        }
        toLowerCase(temp);

        return checkPalin(temp);
}
};
