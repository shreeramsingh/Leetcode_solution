class Solution {
private:
    bool issafe(int newx, int newy,vector<vector<int>>&visited,vector<vector<char>>&mat,
    int n, int m)
    {
        if((newx>=0 && newx<n) && (newy>=0 && newy<m) && visited[newx][newy]!=1){
            return true;
        }
        return false;
    }
bool solve(int x,int y,vector<vector<char>>&mat, int n,int m,vector<vector<int>>&visited,int i,string word)
{
    //base case
    // cout<< mat[x][y] << "\n";
    if(i >= word.size()) return true;
    if(mat[x][y] != word[i]) return false;
    if(i+1 >= word.size()) return true;
    //4 movement D,L,R,U
    visited[x][y]=1;
    //Down
    if(issafe(x+1,y,visited,mat,n, m)){
        // cout<<"HELLO"<< mat[x+1][y] ;
        if(solve(x+1,y,mat,n,m,visited,i+1,word) == true) return true;
    }
    //left
    if(issafe(x,y-1,visited,mat,n, m)){
        // cout<<"HELLO"<< mat[x][y-1];
        if(solve(x,y-1,mat,n,m,visited,i+1,word) == true) return true;
    }
    //right
    if(issafe(x,y+1,visited,mat,n, m)){
        // cout<<"HELLO" << mat[x][y+1];
        if(solve(x,y+1,mat,n,m,visited,i+1,word) == true) return true;
    }
    //up
    if(issafe(x-1,y,visited,mat,n, m)){
        // cout<<"HELLO" << mat[x-1][y];
        if(solve(x-1,y,mat,n,m,visited,i+1,word) == true) return true;
    }
    visited[x][y]=0;
    return false;
}
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // cout<< n <<" ";
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                // cout<<board[i][j] <<" ";
                // if(board[i][j] == word[0]) cout<< i << " " << j << "\n";
                if(board[i][j] == word[0] && solve(i,j,board,m, n,visited,0,word) == true) 
                return true;
            }
            // cout<<"\n";
        }

        return false;
    }
};