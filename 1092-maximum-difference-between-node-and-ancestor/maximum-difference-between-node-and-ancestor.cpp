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
    void solve(TreeNode* root, int mini, int maxi,int &ans) {
        if (!root)
            return;
        ans = max(ans, max(abs(mini - root->val), abs(maxi - root->val)));
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        solve(root->left, mini, maxi,ans);
        solve(root->right, mini, maxi,ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
        return 0;
        int ans=0;
        int maxi=root->val,mini=root->val;
        solve(root,mini,maxi,ans);
        return ans;
    }
};