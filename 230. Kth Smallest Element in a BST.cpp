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
    int ans = -1;
    int count = 0;

    void inordered(TreeNode* root, int k){
        if(root == nullptr){
            return;
        }

        inordered(root->left,k);

        count++;
        if(count == k){
          ans = root->val;
          return;
        }

        inordered(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
         inordered(root,k);

         return ans;

    }
};
