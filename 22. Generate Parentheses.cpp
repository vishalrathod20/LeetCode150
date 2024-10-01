class Solution {
    void genrateParenthesisBackTracking(vector<string>& result,int n, string current , int open , int close ){
             if(open == n && close ==n){
                result.push_back(current);
                return ;
             }

             if(open<n){
                genrateParenthesisBackTracking(result,n,current+"(",open+1,close);
             }
             if(close<open){
                genrateParenthesisBackTracking(result,n,current+")",open, close+1);
             }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        genrateParenthesisBackTracking(result,n,"",0,0);
        return result;
    }
};
