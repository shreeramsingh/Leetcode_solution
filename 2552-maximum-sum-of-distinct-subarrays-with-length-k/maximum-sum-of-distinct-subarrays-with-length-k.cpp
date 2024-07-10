class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
         long long i=0,j=0,ans=0,sum=0;
        unordered_map<int, int>mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            sum+=nums[j];
            if(j-i+1==k){
                if(mp.size()==k){//here it check uniqueness through map
                    ans=max(ans, sum);
                }
                mp[nums[i]]--;//decrease the frequency
                sum-=nums[i];
                if(mp[nums[i]]==0){//erase from map for uniqueness
                    mp.erase(nums[i]);
                    
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};