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
    bool bstHelper(TreeNode* root, long long minVal, long long maxVal){
        if(!root) return true;

        if(root->val <= minVal || root->val >= maxVal){
            return false;
        }

        return bstHelper(root->left,minVal, root->val) && bstHelper(root->right, root->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return bstHelper(root, LONG_LONG_MIN,LONG_LONG_MAX);
    }
};
