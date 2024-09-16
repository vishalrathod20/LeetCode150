class Solution {
public:
    // Helper function to build the tree recursively
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
                              unordered_map<int, int>& inorderMap, int& preorderIndex, 
                              int inorderStart, int inorderEnd) {
        // Base case: if there are no elements to process
        if (inorderStart > inorderEnd) {
            return nullptr;
        }
        
        // Root node is the current element in the preorder traversal
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        // Get the index of the root in the inorder traversal
        int inorderIndex = inorderMap[rootVal];
        
        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(preorder, inorder, inorderMap, preorderIndex, inorderStart, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inorderMap, preorderIndex, inorderIndex + 1, inorderEnd);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the index of each value in the inorder traversal for quick access
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        int preorderIndex = 0;
        return buildTreeHelper(preorder, inorder, inorderMap, preorderIndex, 0, inorder.size() - 1);
    }
};
