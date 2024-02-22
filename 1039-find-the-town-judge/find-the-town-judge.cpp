class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>ram1(n+1),ram2(n+1);
        for(int i = 0;i < trust.size();i++)
        {
            ram1[trust[i][0]]++;   
            ram2[trust[i][1]]++;
        }
        for(int i = 1;i <= n;i++){
            if(ram1[i] == 0 && ram2[i] == n-1)return i;
        }
        return -1;
    }
};