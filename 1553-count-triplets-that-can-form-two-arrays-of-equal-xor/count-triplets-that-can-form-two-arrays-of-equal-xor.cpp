class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int>s(n+1);
        for(int i=1;i<=n;i++)
        {
            s[i]=s[i-1]^arr[i-1];
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j;k<=n;k++)
                {
                    if((s[i-1]^s[j-1]) == (s[k]^s[j-1]))
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};