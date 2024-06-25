class Solution {
public:
    bool ispalidrome(string &s,int left,int right)
    {
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int left=0;
        int right=n-1;
        while(left<right)
        {
            if(s[left]==s[right]){
                left++;
                right--;
            }else{
                return ispalidrome(s,left+1,right) || ispalidrome(s,left,right-1);
            }
        }
        return true;
    }
};