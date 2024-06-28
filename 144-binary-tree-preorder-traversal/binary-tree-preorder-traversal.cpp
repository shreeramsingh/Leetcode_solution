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
    void preorder1(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        ans.push_back(root->val);
        preorder1(root->left,ans);
        preorder1(root->right,ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorder1(root,ans);
        return ans;/**
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
                    ans.push_back(root->val);
                    curr->right=root;
                    root=root->left;
                }else{
                    //Alreay Traversal
                    curr->right=NULL;
                    root=root->right;
                }
            }
        }
        return ans;
        
    }
};
    }
};