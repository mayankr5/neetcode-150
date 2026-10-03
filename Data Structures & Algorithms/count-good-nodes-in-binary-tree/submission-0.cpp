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
    void helper(TreeNode *root, int maxVal, int &res){
        if(root == nullptr)
            return;
        
        if(root->val >= maxVal){
            res++;
            maxVal = root->val;
        }
        helper(root->left, maxVal, res);
        helper(root->right, maxVal, res);
    }
    int goodNodes(TreeNode* root) {
        int res = 0;
        helper(root, INT_MIN, res);
        return res;
    }
};
