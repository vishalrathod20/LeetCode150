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
    int minDiff = INT_MAX;
    int prev = -1;

    void inorderTraversal(TreeNode* root){
        if(root == nullptr) return;

        inorderTraversal(root->left);

        if(prev != -1){
            
            minDiff = min(minDiff, root->val-prev);
        }
        prev = root->val;

        inorderTraversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        
        inorderTraversal(root);
        return minDiff;
    }
};
