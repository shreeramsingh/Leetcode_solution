class Solution {
public:
    int num(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else return 1000;
        
    }
    int romanToInt(string s) {
        int sum=0;
        for(int i=0;i<s.size()-1;i++){
            if(num(s[i])<num(s[i+1])){
                sum-=num(s[i]);
            }else{
                sum+=num(s[i]);
            }
        }
        sum+=num(s[s.size()-1]);
        return sum;
    }
};