class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //BY Rohit negi string
        // vector<bool>count(256,0);//there is only 256 character in alphabet so size is 256
        // int first=0,second=0,len=0;
        // while(second<s.size())
        // {
        //     while(count[s[second]]) //this while loop help us repeating caracter ko hata na k leya
        //     {
        //         count[s[first]]=0; //sliding my window to front and making it zero
        //         first++;
        //     }
        //     count[s[second]]=1;
        //     len=max(len,second-first+1);
        //     second++;
        // }
        // return len;

        //Aditya verma sliding window
         int left=0,right=0,ans=0;
            int n=s.size();
            map<char,int>freq;
            int count=0;
            while(right<n){
                freq[s[right]]++;
                count++;
                
                if(freq.size()==count){
                    ans=max(ans,right-left+1);
                }
                else{
                    while(freq.size()<count){
                        freq[s[left]]--;
                        count--;
                        if(freq[s[left]]==0){
                            freq.erase(s[left]);
                        }
                        left++;
                    }
                }
                right++;
            }
            
            return ans;
    }
};