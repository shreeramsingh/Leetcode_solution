class Solution {
public:
    string convert(string s, int numRows) {
        
    //     if(numRows ==1)
    //     {
    //         return s;
    //     }
    //     int i=0;
    //     bool flag=false;
    //     vector<string> ans(numRows);
    //     for(auto ch:s){
    //         ans[i]+=ch;
    //         if(i==0 || i==numRows-1)
    //         {
    //             flag=!flag;
    //         }
    //         if(flag)
    //         {
    //             i++;
    //         }
    //         else
    //         {
    //             i--;
    //         }
    //     }
    // }
    // string zig="";
    // for(int i=0;i<ans.size();i++) {
    //     zig+=ans[i];
    // }
    // return zig;
    if(numRows == 1) {
            return s;
        }
        
        vector<string> ans(numRows);
        int i = 0;
        bool flag = false;

        for(auto ch : s) {
            ans[i] += ch;
            if(i == 0 || i == numRows - 1) {
                flag = !flag;
            }
            if(flag) {
                i++;
            } else {
                i--;
            }
        }

        string zig = "";
        for(int i = 0; i < ans.size(); i++) {
            zig += ans[i];
        }
        return zig;
    }
};