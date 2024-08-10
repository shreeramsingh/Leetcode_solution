class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result=0;
        for(int i=0;i<32;i++){
            int lsb = n&1; //first i will check least signifigint bit
            int reversebit = lsb << (31-i); //reverse bit lsb into first position
            result |=reversebit; //or operation should perforn to save it

            n = n>>1; // divid by 2 to reduce n
        }
        return result;
    }
};