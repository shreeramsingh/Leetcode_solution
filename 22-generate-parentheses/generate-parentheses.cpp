class Solution {
public:
    vector<string>ans;
    //brutee force
    bool isValid(string &s)
    {
        int count=0;
        for(auto &ch:s){
            if(ch=='(') count++;
            else count--;
            //this case handle ())( this case
            if(count<0) return false;
        }
        return count==0;
    }
    void solve(string &cur, int n)
    {
        if(cur.size()==2*n){
            if(isValid(cur)){
                ans.push_back(cur);
            }
            return ;
        }

        cur.push_back('(');
        solve(cur,n);
        cur.pop_back();
        cur.push_back(')');
        solve(cur,n);
        cur.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        solve(s,n);
        return ans;
    }
};