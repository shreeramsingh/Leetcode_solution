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
    
    void inorder(TreeNode* root,vector<int>&v)
    {
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    //construct new tree
    TreeNode* solve(int l,int r,vector<int>&v){
        if(l>r) return NULL;
        int mid=l+(r-l)/2;
        TreeNode*  root = new TreeNode(v[mid]);
        root->left=solve(l,mid-1,v);
        root->right=solve(mid+1,r,v);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        int l=0,r=v.size()-1;
        
        return solve(l,r,v);
    }
};