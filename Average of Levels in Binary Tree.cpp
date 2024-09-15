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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;

        if(root == nullptr){
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelsize = q.size();
            double levelSum =0;

            for(int i = 0; i<levelsize; i++){
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            result.push_back(levelSum/levelsize);
        }
        return result;
    }
};
