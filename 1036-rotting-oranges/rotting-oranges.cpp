class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // int n=grid.size();
        // int m=grid[0].size();
        // int vis[n][m];
        // //{{r,c},t}
        // queue<pair<pair<int,int>,int>>q;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]==2){
        //             q.push({{i,j},0});
        //             vis[i][j]=2;
        //         }else{
        //             vis[i][j]=0;
        //         }
        //     }
        // }
        // int tm=0;
        // int delrow[]={-1,0,+1,0};
        // int delcol[]={0,+1,0,-1};
        // int cnt=0;
        // while(!q.empty()){
        //     int r= q.front().first.first;
        //     int c= q.front().first.second;
        //     int t= q.front().second;
        //     tm=max(tm,t);
        //     q.pop();
            
        //     for(int i=0;i<4;i++){
        //         int nrow=r+delrow[i];
        //         int ncol=c+delcol[i];
        //         if(nrow>=0 && nrow<n && ncol>=0 &&
        //         ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
        //             q.push({{nrow,ncol},t+1});
        //             vis[nrow][ncol]=2;
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(vis[i][j]!=2 && grid[i][j]==1){
        //             return -1;
        //         }
        //     }
        // }
        // return tm;

        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<int>> vis(ROWS, vector<int>(COLS, 0));
        queue<tuple<int, int, int>> q;
        int cntFresh = 0;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                    vis[i][j] = 2;
                }
                if (grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }
        int maxTime = 0, cnt = 0;
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        while (!q.empty()) {
            auto [r, c, t] = q.front();
            q.pop();
            maxTime = max(maxTime, t);
            for (int i = 0; i < 4; ++i) {
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                if (nRow >= 0 && nRow < ROWS && nCol >= 0 && nCol < COLS && vis[nRow][nCol] == 0 && grid[nRow][nCol] == 1) {
                    vis[nRow][nCol] = 2;
                    q.push({nRow, nCol, t + 1});
                    cnt++;
                }
            }
        }
        if (cnt != cntFresh) {
            return -1;
        }
        return maxTime;
    }
};