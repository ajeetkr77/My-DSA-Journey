
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
    int widthOfBinaryTree(TreeNode* root) {
        
        long long maxWidth = 1;

        queue<pair<TreeNode*, int> > q;

        q.push({root, 0});

        while(!q.empty()){

            int sz = q.size();

            long long leftmostChild = q.front().second;
            long long rightmostChild = q.back().second;

            maxWidth = max(maxWidth, rightmostChild - leftmostChild + 1);

            while(sz--){
                TreeNode* node = q.front().first;
                long long i = q.front().second;
                q.pop();

                if(node->left){
                    q.push({node->left, 2*i + 1});
                }

                if(node->right){
                    q.push({node->right, 2*i + 2});
                }
            }
        }

        return (int)maxWidth;
    }
};
