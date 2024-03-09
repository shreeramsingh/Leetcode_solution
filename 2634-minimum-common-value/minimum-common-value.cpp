class Solution {
public:
    int getCommon(vector<int>& nums1,vector<int>& nums2){
        set<int>s;
        int mini=INT_MAX;
        for(auto it:nums1) s.insert(it);
        for(int i=0;i<nums2.size();i++){
            if(s.find(nums2[i])!=s.end()){
                return nums2[i];
            }
        }
        return -1;
    }
};