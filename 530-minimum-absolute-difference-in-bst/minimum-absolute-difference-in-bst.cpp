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
    void inOrderTraversal(TreeNode* root, vector<int>& values) {
        if (root == nullptr) return;
        inOrderTraversal(root->left, values);
        values.push_back(root->val);
        inOrderTraversal(root->right, values);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> values;
        inOrderTraversal(root, values);
        
        int minDiff = INT_MAX;
        for (int i = 1; i < values.size(); ++i) {
            minDiff = min(minDiff, values[i] - values[i - 1]);
        }
        
        return minDiff;
    }
};