class Solution {
public:
    string simplifyPath(string path) {
        //This problem is solve through tokenization new concept
        string token="";
        stringstream ss(path);
        stack<string>st;
        while(getline(ss,token,'/')){
            
            if(token == "" || token==".") continue;

            if(token!=".."){
                st.push(token);
            }else if(!st.empty()){
                st.pop();
            }
        }
        string result="";
        if(st.empty())
        return "/";
        //add stack element into string without doing reverse
        while(!st.empty())
        {
            result = "/"+st.top()+result;
            st.pop();
        }
        return result;
    }    
};