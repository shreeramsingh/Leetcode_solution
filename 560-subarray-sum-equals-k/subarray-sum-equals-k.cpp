class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp.insert({0,1});
        int currSum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            if(mp.find(currSum-k)!=mp.end()){
                ans+=mp[currSum-k];
            }
            mp[currSum]++;
        }
        
        return ans;
    }
};