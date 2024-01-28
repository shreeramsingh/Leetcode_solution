class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        for(int i=0;i<rows;i++){
            for(int j=1;j<cols;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }

        int ans=0;
        for(int startCols=0;startCols<cols;startCols++){
            for(int j=startCols; j<cols;j++){
                unordered_map<int,int>mp;
                mp.insert({0,1});
                int currSum=0;
                for(int r=0;r<rows;r++){
                    currSum+=matrix[r][j]-(startCols>0 ? matrix[r][startCols-1]:0);

                    if(mp.find(currSum-target)!=mp.end()){
                        ans+=mp[currSum-target];
                    }
                    mp[currSum]++;
                }
            }
        }
        return ans;

    }
};