class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> distinct;
        unordered_set<string> duplicate;

        for (const string& str : arr) {
            if (duplicate.find(str) != duplicate.end()) {
                continue;
            }
            if (distinct.find(str) != distinct.end()) {
                distinct.erase(str);
                duplicate.insert(str);
            } else {
                distinct.insert(str);
            }
        }

        for (const string& str : arr) {
            if (duplicate.find(str) == duplicate.end()) {
                k--;
            }
            if (k == 0) {
                return str;
            }
        }
        return "";
    }
};