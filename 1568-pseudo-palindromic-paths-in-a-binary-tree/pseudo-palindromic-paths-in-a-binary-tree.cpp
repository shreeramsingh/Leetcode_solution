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
    bool checkPali(vector<int>&t){
        int cnt=0;
        for(int i=0;i<t.size();i++){
            if(t[i]&1){
                cnt++;
            }
        }
        return cnt<=1;
    }
    int help(TreeNode* root,vector<int>t)
    {
        if(root==NULL){
            return 0;
        }
        t[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            if(checkPali(t)) return 1;
            return 0;
        }
        int ans=0;
        ans+=help(root->left,t);
        ans+=help(root->right,t);
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>num(10,0);
        return help(root,num);
    }
};