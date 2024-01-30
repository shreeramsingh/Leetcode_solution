class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans=0;
        // if(tokens.size()==1){
        //     return stoi(tokens[0]);
        // }
        stack<string>st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" &&tokens[i]!="/"){
                st.push(tokens[i]);
            }else
            {
                int second = stoi(st.top());st.pop();
                int first =stoi(st.top());st.pop();
                //int ans;
                switch(tokens[i][0]){
                    case '+':
                       ans = first+second;
                        break;
                    case '-':
                      ans = first-second;
                        break;
                    case '*':
                      ans = first*second;
                        break;
                    case '/':
                      ans = first/second;
                        break;
                }
                st.push(to_string(ans));
            }
                
        }
        return stoi(st.top());
    }
};