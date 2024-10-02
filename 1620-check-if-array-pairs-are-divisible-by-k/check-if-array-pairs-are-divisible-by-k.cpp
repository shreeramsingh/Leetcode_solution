class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
         vector<int>mp(k,0);//O(k)
         //mp[r] = x;
         //remainder r has frequency x

         for(int &num : arr){
            int rem = (num%k + k) % k;//handling negative remainder
            mp[rem]++;
         }

         if(mp[0]%2 !=0){
            return false;
         }

         for(int rem =1; rem<= k/2; rem++){
            int countHalf = k-rem;
            if(mp[countHalf] !=mp[rem]){
                return false;
            }
         }
         return true;
    }
};