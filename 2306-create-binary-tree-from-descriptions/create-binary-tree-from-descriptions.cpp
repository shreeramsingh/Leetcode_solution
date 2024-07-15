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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_set<int> children;
        unordered_map<int, TreeNode*> nodes;

        // Track nodes and their relationships
        for (int i = 0; i < n; ++i) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            bool isLeft = descriptions[i][2];

            // Add child to the set of children
            children.insert(child);

            // Ensure nodes exist in the map
            if (nodes.find(parent) == nodes.end()) {
                nodes[parent] = new TreeNode(parent);
            }
            if (nodes.find(child) == nodes.end()) {
                nodes[child] = new TreeNode(child);
            }

            // Link child to parent
            if (isLeft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
        }

        // Identify the root
        for (int i = 0; i < n; ++i) {
            int parent = descriptions[i][0];
            if (children.find(parent) == children.end()) {
                return nodes[parent];
            }
        }

        return nullptr;
    }
};