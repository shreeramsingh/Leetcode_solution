class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int MaxVal=0;
        int result=0;
        int streak=0;

        for(auto num : nums){
            if(num> MaxVal){
                MaxVal = num;
                result = 0;
                streak = 0;
            }
            if(MaxVal == num){
                streak++;
            }else{
                streak=0;
            }
            result = max(result,streak);
        }
        return result;
    }
};