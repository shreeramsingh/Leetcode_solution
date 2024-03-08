class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxi=INT_MIN;
        for(auto it:nums){
            m[it]++;
            maxi=max(maxi,m[it]);
        }
        //cout<<maxi<<" ";
        int ans=0;
        for(auto it:m){
            if(it.second==maxi){
                ans+=it.second;
            }
        }
        return ans;
    }
};