class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        int ans1=ans^k;
        int cnt=0;
        while(ans1!=0){
            int bits=ans1&1;
            if(bits)
                cnt++;
            ans1=ans1>>1;    
        }
        return cnt;
    }
};