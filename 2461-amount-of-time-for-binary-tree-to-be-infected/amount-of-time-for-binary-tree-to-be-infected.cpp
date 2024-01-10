/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void creatGraph(TreeNode* root,int parent, unordered_map<int,unordered_set<int>>&graph){
        if(root==nullptr) return;
        if(parent!=-1){
            //in this code root->val know for child
            graph[parent].insert(root->val);
            graph[root->val].insert(parent);
        }
        creatGraph(root->left,root->val,graph);
        creatGraph(root->right,root->val,graph);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,unordered_set<int>>graph;
        creatGraph(root,-1,graph);
        queue<pair<int,int>>q;
        q.push({start,0});
        int ans=-1;
        vector<int>visited(1e5+10,0);
        visited[start] = 1;
        while(!q.empty())
        {
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();

            ans=max(ans,steps);
            for(auto it:graph[node])
            {
                if(visited[it]==0){
                    visited[it]=1;
                    q.push({it,steps+1});
                }
            }

        }
        return ans;
    }
};