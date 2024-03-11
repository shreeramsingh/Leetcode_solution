class Solution {
public:
    string customSortString(string order, string s){
        vector<int> frequency(26);
        for(int i=0;i<s.length();i++){
            frequency[s[i]-'a']++;
        }
        string out="";
        for(int i=0;i<order.length();i++){
            out.append(frequency[order[i]-'a'], order[i]);
            frequency[order[i]-'a']=0;
        }
        for(int i=0;i<26;i++){
            out.append(frequency[i], 'a'+i); 
        }
        return out;
    }
};