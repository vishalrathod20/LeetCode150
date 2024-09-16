class Solution {
    int maxSum; // Class-level variable to keep track of the maximum path sum

    int maxSumPath(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        // Compute maximum path sum starting from the left and right child
        int leftMax = max(0, maxSumPath(root->left));
        int rightMax = max(0, maxSumPath(root->right));

        // Calculate the current path sum including the node and both children
        int currSum = root->val + leftMax + rightMax;

        // Update the global maximum path sum
        maxSum = max(maxSum, currSum);

        // Return the maximum path sum starting from the current node
        return root->val + max(leftMax, rightMax);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN; // Initialize the global maximum path sum to the smallest possible integer
        maxSumPath(root);
        return maxSum;
    }
};
