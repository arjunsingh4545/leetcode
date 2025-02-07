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
    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> val;
        q.push(root);
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            val.push_back(curr->val);
            if(curr->left) {
                q.push(curr->left);
            } 
            if(curr->right) {
                q.push(curr->right);
            }
        }

        sort(val.begin() , val.end());

        int minDiff = INT_MAX;
        for(int i=1 ; i < val.size() ; i++) {
            minDiff = std::min(minDiff , val[i] - val[i-1]);
        }
        return minDiff;
    }
};