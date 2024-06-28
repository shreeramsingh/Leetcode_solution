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
    vector<int> inorderTraversal(TreeNode* root) {
        //code here
        //WE ARE DOING MORRIS TRAVERSAL
        
        //Left
        //Node
        //Right
        vector<int>ans;
        while(root)
        {
            //left Part doesn't exit
            if(!root->left)
            {
                ans.push_back(root->val);
                root=root->right;
            }
            //left Part exit
            else{
                TreeNode * curr = root->left;
                while(curr->right && curr->right!=root){
                    curr=curr->right;
                }
                //Left subtree not traversal
                if(curr->right==NULL){
                    curr->right=root;
                    root=root->left;
                }else{
                    //Alreay Traversal
                    curr->right=NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }
            }
        }
        return ans;
        
    }
};