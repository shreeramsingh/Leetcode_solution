class Solution {
public:
    int dp[501];
    int help(int i, vector<int>& arr, int k)
    {
        if(i==arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        int current_val=-1;
        for(int j=i; j<arr.size() && j-i+1<=k;j++){
            current_val=max(current_val,arr[j]);
            ans=max(ans,((j-i+1)*current_val)+help(j+1,arr,k));
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return help(0,arr,k);
    }
};