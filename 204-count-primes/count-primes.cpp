class Solution {
public:
    int countPrimes(int n) {
       // bool* isprime = new bool[n];
        bool isprime[n+1];
        for(int i=2;i<n;i++)
        {
            isprime[i]=true;
        }
        for(int i=2;i*i<n;i++)
        {
            if(!isprime[i])
            continue;
            for(int j=i*i;j<n;j=j+i)
            {
                isprime[j]=false;
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++)
        {
            if(isprime[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
};