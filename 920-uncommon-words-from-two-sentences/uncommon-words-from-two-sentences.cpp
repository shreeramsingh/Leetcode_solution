class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
       vector<string>v;
       vector<string>ans;
       string word="";
       map<string,int>m;
       for(int i=0;i<s1.size();i++)
       {
           if(s1[i]==' ')
           {
               v.push_back(word);
               word="";
           }
           else
           {
               word+=s1[i];
           }
       }
       v.push_back(word);
       word="";
    for(int i=0;i<s2.size();i++)
       {
           if(s2[i]==' ')
           {
               v.push_back(word);
               word="";
           }
           else
           {
               word+=s2[i];
           }
       }
       v.push_back(word);
       for(auto it:v)
       {
           m[it]++;
       }
       for(auto it:m)
       {
           if(it.second==1)
           {
               ans.push_back(it.first);
           }
       }
       return ans;
    }
};