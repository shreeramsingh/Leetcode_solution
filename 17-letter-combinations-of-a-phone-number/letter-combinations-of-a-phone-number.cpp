class Solution {
public:
    void letterCombation(int idx,string &digits,unordered_map<int,string>&m,
    vector<string>&ans,string temp)
    {
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }
        string s=m[digits[idx]-'0'];
        for(int i=0;i<s.size();i++){
            letterCombation(idx+1,digits,m,ans,temp+s[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        string temp="";
        unordered_map<int,string>m;
        m[2]="abc";
        m[3]="def"; 
        m[4]="ghi"; 
        m[5]="jkl";
        m[6]="mno"; 
        m[7]="pqrs"; 
        m[8]="tuv"; 
        m[9]="wxyz";
        letterCombation(0,digits,m,ans,temp);
        return ans;
    }
};