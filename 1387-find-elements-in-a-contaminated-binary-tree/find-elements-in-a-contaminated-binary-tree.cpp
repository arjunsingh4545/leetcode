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
class FindElements {
    unordered_set<int> values;
    int leftVal(int x) {
        return 2*x+1;
    }
    int rightVal(int x) {
        return 2*x+2;
    }
    
    void makeBinary(TreeNode* root , int x) {
        root->val = x;
        values.insert(x);

        if(root->left != nullptr) {
            makeBinary(root->left , leftVal(x));
        }

        if(root->right != nullptr) {
            makeBinary(root->right , rightVal(x));
        }
    }

    
public:
    FindElements(TreeNode* root) {
        if(root != nullptr) makeBinary(root , 0);
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