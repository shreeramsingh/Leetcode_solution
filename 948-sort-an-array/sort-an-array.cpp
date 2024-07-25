class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int>v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(nums[i]);
        }
        return v;
    }
};