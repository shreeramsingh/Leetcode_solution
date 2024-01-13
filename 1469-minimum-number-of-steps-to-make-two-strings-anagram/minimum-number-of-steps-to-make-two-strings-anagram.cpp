class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>ch1(26,0);
        for(int i=0;i<s.size();i++){
            ch1[s[i]-'a']++;
            ch1[t[i]-'a']--;
        }
        int diff=0;
       for(int i=0;i<26;i++){
           diff += max(0, ch1[i]);
       }
        return diff;
    }
};