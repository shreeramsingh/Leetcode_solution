class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefSummp;
        int prefSum = 0;
        prefSummp[0] = 1;
        int subArrayCnt = 0;
        for (int num : nums) {
            prefSum += num;
            if (prefSummp.find(prefSum - goal) != prefSummp.end()) {
                subArrayCnt += prefSummp[prefSum - goal];
            }
            prefSummp[prefSum]++;
        }   
        return subArrayCnt;
    }
};