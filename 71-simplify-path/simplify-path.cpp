class Solution {
public:
    string simplifyPath(string path) {
        int i=path.size()-1;
        string ans="";
        int back=0;

        while(i>=0)
        {
            string temp="";
            while(i>=0 and path[i]!='/')
            {
                temp+=path[i];
                i--;
            }
            i--;
            if(temp=="" || temp==".")
            continue;
            if(temp=="..")
            {
                back++;
            }
            else if(back>0){
                back--;
            }
            else{
                ans+=temp;
                ans+="/";
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans=="")
        return "/";
        return ans;
    }
};