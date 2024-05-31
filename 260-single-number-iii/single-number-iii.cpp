class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // vector<int>ans;
        // sort(nums.begin(),nums.end());
        // int a=0;
        // for(int i=0;i<nums.size()-1;i++){
        //     nums[i]^=nums[i+1];
        //     cout<<a<<" ";
        // }
        // return nums;

        unordered_map<int,int>um;
        for(int i=0;i<nums.size();i++)
        {
            um[nums[i]]++;
        }
        vector<int>ans;
        for(auto it:um){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
        return ans;

    }
};