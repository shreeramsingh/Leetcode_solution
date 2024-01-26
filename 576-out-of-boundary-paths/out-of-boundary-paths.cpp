class Solution {
public:
    int dp[55][55][55];
    int mod=1e9+7;
    int delrow[4]={1,0,0,-1};
    int delcol[4]={0,1,-1,0};
    int f(int row,int col,int m,int n,int maxMove) {
        if(maxMove == 0) return 0;
        int ans = 0;
        // if(row < 0 || col < 0 || row >= m ||col >= n) return 1;
        if(dp[row][col][maxMove]!=-1){
            return dp[row][col][maxMove];
        }
        for(int dir = 0; dir < 4; dir++) {
            int nrow = delrow[dir] + row;
            int ncol = delcol[dir] + col;
            if(nrow < 0 || ncol < 0 || nrow >= m || ncol >= n) ans=(ans+1)%mod;
            else ans = (ans%mod + f(nrow, ncol, m, n, maxMove-1)%mod)%mod;
        }
        return dp[row][col][maxMove]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>>a(m,vector<int>(n,0));
        memset(dp,-1,sizeof(dp));
        return f(startRow,startColumn,m, n, maxMove);
    }
};