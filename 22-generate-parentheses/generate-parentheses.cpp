class Solution {
public:
    vector<string>ans;
    
    void solve(string &cur, int n,int open,int close)
    {
        if(cur.size()==2*n){
        ans.push_back(cur);
            return ;
        }
        //according to objevation open never should greater than n
        if(open<n){
            cur.push_back('(');
            solve(cur,n,open+1,close);
            cur.pop_back();
        }
        //according to objervation close never should greater than open
        if(close<open){
            cur.push_back(')');
            solve(cur,n,open,close+1);
            cur.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        int open=0,close=0;
        solve(s,n,open,close);
        return ans;
    }
};