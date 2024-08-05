class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> distinct;
        unordered_set<string> duplicate;

        for (const string& str : arr) {
            if (duplicate.count(str)) {
                continue;
            }
            if (distinct.count(str)) {
                distinct.erase(str);
                duplicate.insert(str);
            } else {
                distinct.insert(str);
            }
        }

        for (const string& str : arr) {
            if (!duplicate.count(str)) {
                k--;
            }
            if (k == 0) {
                return str;
            }
        }
        return "";
    }
};