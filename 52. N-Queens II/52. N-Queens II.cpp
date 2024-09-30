class Solution {
    bool isSafe(int row, int cols, vector<int>& col,vector<int>& diag1,vector<int>&diag2,int n){
       if(col[cols]||diag1[row-cols+n-1]||diag2[row+cols]){
           return false;
       }
       return true;
    }
    void solve(int row, int &count, vector<int> &col, vector<int>& diag1,vector<int>&diag2,int n){
      if(row == n){
        count++;
        return;
      }

      for(int cols = 0; cols<n; ++cols){
        if(isSafe(row,cols,col,diag1,diag2,n)){
            col[cols] = diag1[row-cols+n-1] = diag2[row+cols] = 1;

            solve(row+1, count,col,diag1,diag2,n);

            col[cols] = diag1[row-cols+n-1] = diag2[row+cols] =0;
        }
      }
    }
public:
    int totalNQueens(int n) {
        vector<int> col(n,0); //for column
        vector<int> diag1(2*n-1,0);//main diagonal
        vector<int> diag2(2*n-1,0);//anti diagonal

        int count = 0;
        solve(0,count,col,diag1,diag2,n);
        return count;
    }
};
