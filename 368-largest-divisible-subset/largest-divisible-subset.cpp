class Solution {
public:
    // void solve(int i,vector<int>& nums,vector<int>&ans,vector<int>& temp,int prev)
    // {
    //     if(i>=nums.size()){
    //         if(temp.size()>ans.size()){
    //             ans=temp;
    //         }
    //         return;
    //     }
    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }
    //     if(prev==-1 || nums[i]%prev==0)
    //     {
    //         temp.push_back(nums[i]);
    //         solve(i+1,nums,ans,temp,nums[i]);
    //         temp.pop_back();
    //     }
    //     solve(i+1,nums,ans,temp,prev);
    // }
    /*
    in this question their is pick,not pick option
    */
    vector<int>largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>t(n,1);
        vector<int>pre_index(n,-1);
        int last_choose_index=0;
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(t[i]<t[j]+1){
                        t[i]=t[j]+1;
                        pre_index[i]=j;
                    }
                    if(t[i]>maxi){
                        maxi=t[i];
                        last_choose_index=i;
                    }
                }
            }
        }
        vector<int>ans;
        while(last_choose_index!=-1){
            ans.push_back(nums[last_choose_index]);
            last_choose_index=pre_index[last_choose_index];
        }
        return ans;
    }
};