class Solution {
public:
     void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&vis,
    int *delrow,int *delcol,int n,int m)
    {
        vis[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            vis[nrow][ncol]==false && 
            grid[nrow][ncol]=='1')
            {
                dfs(nrow,ncol,grid,vis,delrow,delcol,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int N=grid.size();
        int M=grid[0].size();
        vector<vector<bool>>vis(N,vector<bool>(M,false));
        int ans=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==false)
                {
                    ans++;
                    dfs(i,j,grid,vis,delrow,delcol,N,M);
                }
            }
        }
        return ans;
        
    }
};