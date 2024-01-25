class Solution {
public:
    int solve(string &s1, string &s2, int i,
    int j,vector<vector<int>> &dp)
    {
        if(i==s1.size())
        return 0;
        if(j==s2.size())
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j])
        {
            return 1+solve( s1, s2, i+1,j+1,dp);
        }
        else
        {
            ans= max(solve(s1, s2, i+1,j,dp), solve(s1, s2, i,j+1,dp));
        }
        return dp[i][j]= ans;
    }
    int longestCommonSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(),-1));
        int i=0,j=0;
        return solve( s, t, i, j,dp);
    }
};