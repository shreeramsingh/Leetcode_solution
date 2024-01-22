class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second==2){
                v.push_back(it.first);
            }
        }
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                v.push_back(i);
                break;
            }
        }
        return v;
    }
};