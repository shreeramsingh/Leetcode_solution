class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        vector<pair<int,char>>p;
        for(auto it:m)
        {
            p.push_back({it.second,it.first});
        }
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());
        for(auto it:p)
        {     
            while(it.first)
            {
              ans+=it.second;
              it.first--;
            }  
        }
        return ans;
    }
};