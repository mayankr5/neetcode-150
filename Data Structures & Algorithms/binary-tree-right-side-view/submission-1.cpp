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
    // void helper(TreeNode *root, vector<int> &res, int level){
    //     if(root == nullptr)
    //         return;
        
    //     if(res.size() <= level){
    //         res.push_back(root->val);
    //     }
    //     helper(root->right, res, level + 1);
    //     helper(root->left, res, level+1);
    // }
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> res;
        // helper(root, res, 0);
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            res.push_back(q.front()->val);
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                TreeNode *node = q.front();
                if(node->right)
                    q.push(node->right);
                
                if(node->left)
                    q.push(node->left);
                
                q.pop();
            }
        }
        return res;
    }
};
