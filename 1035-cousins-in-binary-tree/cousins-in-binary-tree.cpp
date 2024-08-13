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
    bool parent(TreeNode * root, int a, int b)
    {
        if(!root)
        return 0;
        
        if(root->left && root->right)
        {
            if(root->left->val==a && root->right->val==b)
            return 1;
            
            if(root->left->val==b && root->right->val==a)
            return 1;
            
        }
        //left parent and right parent
        return parent(root->left, a, b) || parent(root->right, a, b);
    }
    bool isCousins(TreeNode* root, int a, int b) {
        if(!root->left && !root->right ) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int l1=-1,l2=-1;
        int level=0;
        while(!q.empty())
        {
            int n= q.size();
            while(n--)
            {
                TreeNode *temp = q.front();
                q.pop();
                
                if(temp->val==a){
                    l1=level;
                }
                if(temp->val==b){
                    l2=level;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            level++;
            if(l1!=l2){
                return 0;
            }
            if(l1!=-1 && l2!=-1){
                break;
            }
        }
        return !parent(root, a, b);
    }
};