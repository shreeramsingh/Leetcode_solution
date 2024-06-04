class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int>um;
        // //auto char &ch
        // for(int i=0;i<s.size();i++){
        //     um[s[i]]++;
        // }
        // int ans=0;
        // bool oddFeq=false;
        // for(auto it:um){
        //     if(it.second%2==0){
        //         ans+=it.second;
        //     }else{
        //         ans+=it.second-1;
        //         oddFeq=true;
        //     }
        // }
        
        // if(oddFeq)
        // ans++;

        // return ans;

        //Another Method
        int ans=0,oddFeq=0;

        for(char &ch:s){
            um[ch]++;

            if(um[ch] % 2 !=0){
                oddFeq++;
            }else{
                oddFeq--;
            }
        }
        if(oddFeq>0){
            return n-oddFeq+1;
        }

        return n;

    }
};