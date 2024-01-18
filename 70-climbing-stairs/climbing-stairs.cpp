class Solution {
public:
    int dp[46];
    int solve(int n)
    {
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=solve(n-1)+solve(n-2);
        return dp[n]=ans;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        if(n<=2){
            return n;
        }
        return solve(n);
    }
};