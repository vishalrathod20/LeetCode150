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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr){
                if(curr->left){
                    TreeNode* rightmost = curr->left;
                    while (rightmost->right) {
                    rightmost = rightmost->right;
                }
            
             // Right subtree ko left ke rightmost node ke right mein attach karo
                rightmost->right = curr->right;
                
                // Left subtree ko right mein shift karo
                curr->right = curr->left;
                curr->left = NULL;
            }
            // Next node pe move karo (right child)
            curr = curr->right;

        }
    }
};
