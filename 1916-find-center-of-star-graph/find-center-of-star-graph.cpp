class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
       int n= edges.size();  
        vector<int>adj[n+2];
        for(auto x: edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        
        for(int i=1; i<=n+1; i++)
        {
            if(adj[i].size()==n)  
            return i;

        }
        return 0;
    }
};