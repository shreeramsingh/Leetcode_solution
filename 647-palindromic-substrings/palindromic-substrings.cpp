class Solution {
public:
    bool ispali(int i,int j,string &s){
        if(i>=j) return true;
        if(s[i]==s[j]) return ispali(i+1,j-1,s);
        return false;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){

                if(ispali(i,j,s)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};