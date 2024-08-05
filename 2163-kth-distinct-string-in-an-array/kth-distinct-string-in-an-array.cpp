class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freqMap;
    
        // Count the frequency of each string in the array
        for (const string& str : arr) {
            freqMap[str]++;
        }
        
        // Find the k-th distinct string
        for (const string& str : arr) {
            if (freqMap[str] == 1) {
                k--;
            }
            if (k == 0) {
                return str;
            }
        }
        
        return "";
    }
};