class Solution {
public:
    string fun (string str1 )
{
    str1 +=" "; //to capture the last count 
    int len = str1.size();
    int count =1;
    string ans= "";

    for ( int i =0; i< len-1 ;i++)
    {
        if(str1[i+1] == str1[i]) count++;
        else {
            ans+=('0'+count);
            ans+=str1[i];
            count =1;
        }
    }
    return ans ;
}
    string countAndSay(int n) {
        if(n==1)
        return "1";
        string x=fun(countAndSay(n-1));
        return x;
    }
};