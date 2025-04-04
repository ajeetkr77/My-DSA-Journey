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
    pair<TreeNode*, int> find(TreeNode* root){
        if(!root) return{nullptr, 0};

        pair<TreeNode*, int> left = find(root->left);
        pair<TreeNode*, int> right = find(root->right);

        if(left.second == right.second)
            return {root, 1 + left.second};
        else if(left.second < right.second)
            return {right.first, 1 + right.second};
        else 
            return {left.first, 1 + left.second};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<TreeNode*, int> res = find(root);
        return res.first;
    }
};
