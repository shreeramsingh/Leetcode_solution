class Solution {
public:
    int dp[10001];
    int perfect(vector<int>&v,int n){
        if(n==0){
            return 0;
        }    
        if(n < 0) return 1e8;
        if(dp[n]!=-1){
            return dp[n];
        }
        //pick
        int ans = 1e8;
        for(int i = 0 ;i < 101; i++) {
            if(n - v[i] >= 0 ) ans = min(ans, perfect(v, n-v[i]) + 1);
            else break;
        }

        return dp[n]=ans;
    }
    
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        vector<int>v;
        int cnt=0;
        for(int i=1;i<=101;i++){
            v.push_back(i*i);
        }
        return perfect(v,n);
    }
};