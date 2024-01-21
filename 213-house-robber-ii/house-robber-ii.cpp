class Solution {
public:
    int dp[105];
    int dp2[105];
    int help(int i,vector<int>& nums, int n, int *dp)
    {
        if(i >= n) {
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int a=help(i+2,nums,n,dp)+nums[i];
        int b=help(i+1,nums,n,dp)+0;
        return dp[i]=max(a,b);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        return max( help(0,nums, n-1,dp) , help(1,nums, n,dp2));
    }
};