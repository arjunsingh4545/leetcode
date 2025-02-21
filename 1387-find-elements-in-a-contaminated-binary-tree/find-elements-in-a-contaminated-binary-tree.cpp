/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };;
 */
 //bfs approach
class FindElements {
    unordered_set<int> values;
    int leftVal(int x) {
        return 2*x+1;
    }
    int rightVal(int x) {
        return 2*x+2;
    }
    void bfs(TreeNode* root) {
        if(root != nullptr) {
            root->val = 0;
            values.insert(root->val);

            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left != nullptr) {
                    curr->left->val = leftVal(curr->val);
                    values.insert(curr->left->val);
                    q.push(curr->left);
                }

                if(curr->right != nullptr) {
                    curr->right->val = rightVal(curr->val);
                    values.insert(curr->right->val);
                    q.push(curr->right);
                }
            }
        }
    }
public:
    FindElements(TreeNode* root) {
        //bfs
        bfs(root);
    }
    
    bool find(int target) {
        return values.find(target) != values.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */