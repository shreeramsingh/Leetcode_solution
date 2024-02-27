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
    int diameterOfBinaryTree(TreeNode* root) {
        int daimeter=0;
        height(root,daimeter);
        return daimeter;
    }
    int height(TreeNode* root,int&daimeter)
    {
        if(root==NULL) return 0;
        int lh=height(root->left,daimeter);
        int rh=height(root->right,daimeter);
        daimeter = max(daimeter,lh+rh);
        
        return 1+max(lh,rh);
            
    }
};