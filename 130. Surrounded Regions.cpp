class Solution {
    void dfs(vector<vector<char>>& board,int i, int j, int m, int n){
        if(i<0 || i>= m ||j<0 || j>=n||board[i][j] != 'O'){
            return;
        }
        board[i][j] = 'T';

        dfs(board,i-1,j,m,n);//up
        dfs(board,i+1,j,m,n);//down
        dfs(board,i,j-1,m,n);//left
        dfs(board,i,j+1,m,n);//right

    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(board.empty()){
            return ;
        }
        for(int i = 0; i<m; i++){
            dfs(board,i,0,m,n);//first coloumn
            dfs(board,i,n-1,m,n);//last column
        }
        for(int j = 0; j<n; j++){
             dfs(board,0,j,m,n);//first row
             dfs(board,m-1,j,m,n);//last row

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j]=='T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
