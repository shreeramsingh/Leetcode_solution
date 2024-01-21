class Solution {
public:
    int dp[105];
    int solve(int i,vector<int>& nums)
    {
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
       int a= solve(i+2,nums)+nums[i];
       int b= solve(i+1,nums)+0;
        return dp[i]=max(a,b);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        return solve(ans,nums);
        
    }
};