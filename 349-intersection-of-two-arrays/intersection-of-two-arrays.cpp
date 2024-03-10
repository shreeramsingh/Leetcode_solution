class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        unordered_set<int>s,s2;
        for(auto it:nums1) s.insert(it);
        for(int i=0;i<nums2.size();i++){
            if(s.find(nums2[i])!=s.end()){
                s2.insert(nums2[i]);
            }
        }
        for(auto it:s2) v.push_back(it);
        return v;
    }
};