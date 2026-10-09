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
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &curr, int l, int r){
        if(l > r){
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[curr]);
        int idx;
        for(int i = 0; i < inorder.size(); i++){
            if(preorder[curr] == inorder[i]){
                idx = i;
                curr++;
                break;
            }
        }
        root->left = helper(preorder, inorder, curr, l, idx-1);
        root->right = helper(preorder, inorder, curr, idx+1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int curr = 0;
        return helper(preorder, inorder, curr, 0, inorder.size()-1);
    }
};
