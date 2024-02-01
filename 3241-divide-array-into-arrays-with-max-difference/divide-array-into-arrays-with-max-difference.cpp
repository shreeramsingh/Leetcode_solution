class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int count=0,i=0,n=nums.size();
        while(i<n-2){
            vector<int>temp;
            if(nums[i+1]-nums[i]<=k && nums[i+2]-nums[i]<=k){
                temp.push_back(nums[i]);
                temp.push_back(nums[i+1]);
                temp.push_back(nums[i+2]);
                i=i+3;
                count+=3;
                ans.push_back(temp);
            }else{
                i++;
            }
        }
        if(count!=n){
            vector<vector<int>>emp;
            return emp;
        }else{
            return ans;
        }
    }
};