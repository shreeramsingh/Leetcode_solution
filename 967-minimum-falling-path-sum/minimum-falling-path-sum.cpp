class Solution {
public:
    // int dp[105][105];
    // int solve(int i,int j, vector<vector<int>>&m,int n)
    // {
    //     if(i<0 || j<0 || j>=n ){
    //         return 1e7;
    //     }
    //     if(i == (n-1)){
    //         return m[i][j];
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int ans=m[i][j] + min(min(solve(i+1,j-1,m,n),solve(i+1,j,m,n)),
    //     solve(i+1,j+1,m,n));
    //     return dp[i][j]=ans;

    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,0));

        for(int col = 0; col < n; col++) dp[0][col] = matrix[0][col];

        for(int row = 1; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(col == 0) {
                    dp[row][col] = min({dp[row-1][col], dp[row-1][col+1]}) 
                        + matrix[row][col];
                }
                else if(col == n-1) {
                    dp[row][col] = min({dp[row-1][col-1], dp[row-1][col]}) 
                        + matrix[row][col];
                } else {
                    dp[row][col] = min({dp[row-1][col-1], dp[row-1][col], dp[row-1][col+1]}) 
                        + matrix[row][col];
                }
            }
        }

        int ans = 1e9;
        for(int lastCol = 0; lastCol < n; lastCol++) 
            ans = min(ans, dp[n-1][lastCol]);

        return ans;
    }
};