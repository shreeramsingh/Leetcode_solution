class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        int cnt=0;
        while(ans!=0){
            int bits=ans&1;
            if(bits)
            cnt++;
            ans=ans>>1;
        }
        return cnt;
    }
};