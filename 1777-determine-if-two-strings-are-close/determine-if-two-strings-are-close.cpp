class Solution {
public:
    bool closeStrings(string word1, string word2) {
       int n=word1.size();
       int m=word2.size();
       if(m!=n){
           return false;
       }
       vector<int>freq1(26);
       vector<int>freq2(26);
       for(int i=0;i<n;i++){
           char ch1=word1[i];
           freq1[ch1-'a']++;

           char ch2=word2[i];
           freq2[ch2-'a']++;
       }
       for(int i=0;i<26;i++){
           if(freq1[i]>=1 && freq2[i]<=0){
               return false;
           }
       }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        return freq1==freq2;
    }
};