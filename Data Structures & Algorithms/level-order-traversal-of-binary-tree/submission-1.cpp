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
    // void helper(vector<vector<int>> &res, TreeNode *root, int level){
    //     if(root == nullptr){
    //         return;
    //     }
    //     if(level >= res.size()){
    //         res.push_back({root->val});
    //     }else{
    //         res[level].push_back(root->val);
    //     }
    //     helper(res, root->left, level+1);
    //     helper(res, root->right, level+1);
    // }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        
        vector<vector<int>> res;
        // helper(res, root, 0);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> temp;
            for(int i = 0; i < sz; i++){
                TreeNode *node = q.front();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                temp.push_back(node->val);
                q.pop();
            }
            res.push_back(temp);
        }
        return res;
    }
};
