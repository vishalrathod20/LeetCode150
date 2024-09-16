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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftToright = true;

        while(!q.empty()){
            int levelSize = q.size();
            vector<int>level(levelSize);

            for(int i = 0; i<levelSize; i++){
                TreeNode* rootNode = q.front();
                q.pop();
                
                int index = leftToright ? i : (levelSize-1-i);
                level[index] = rootNode->val;

                if(rootNode->left) q.push(rootNode->left);

                if(rootNode->right) q.push(rootNode->right);    
            }
           leftToright = !leftToright;
            result.push_back(level);
            
        }
        return result;
    }
};
