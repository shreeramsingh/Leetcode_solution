class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //1 3 4 2 2
        //s
        //f
        int slow=nums[0];
        int fast=nums[0];

        slow=nums[slow];
        fast=nums[nums[fast]];
        //Detect cycle
        while(slow!= fast)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        //After slow and fast at a same point then again put slow at begineeing
        slow=nums[0];
        //then run both by one pointer only
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};