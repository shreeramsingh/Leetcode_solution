class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        for(auto it:num)
        {
            while(!st.empty() && k>0 && st.top()>it)
            {
                st.pop();
                k--;
            }
            if(!st.empty() || it!='0')
            {
                st.push(it);
            }
        }
        while(!st.empty() && k--)
        {
            st.pop();
        }
        if(st.empty())
        return "0";
        while(!st.empty())
        {
            num[n-1]=st.top();
            st.pop();
            n--;
        }
        return num.substr(n);
    }
};