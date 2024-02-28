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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
       q.push(root);
       vector<int>v;
        int ans;
       while(!q.empty())
       {
           int n=q.size();
           for(int i=0;i<n;i++)
           {
               TreeNode* nod=q.front();
               q.pop();
               if(i==0)
               {
                   ans=(nod->val);
               }
               if(nod->left)
               {
                   q.push(nod->left);
               }
               if(nod->right)
               {
                   q.push(nod->right);
               }
           }
       }
       return ans;
        
    }
};