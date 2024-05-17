class Solution {
public:
    int scoreOfString(string s) {
        int n=s.size();
        int sum=0;
        for(int i=1;i<n;i++){
            int a=s[i-1]-'a';
            int b=s[i]-'a';
            sum+=abs(a-b);
        }
        return sum;
    }
};