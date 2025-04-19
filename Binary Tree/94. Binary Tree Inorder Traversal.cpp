*********************** Recursive Approach ***********************

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == nullptr)
            return;
        
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans ;

        inorder(root, ans);

        return ans;
    }
};

******************  Itrative Approach ******************************

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans ;

        stack<TreeNode*> st;
        TreeNode* temp = root;
        
        while(true){
            if(temp){
                st.push(temp);
                temp = temp->left;
            }else{
                if(st.empty()) break;
                TreeNode* temp1 = st.top();
                st.pop();
                ans.push_back(temp1->val);
                temp = temp1->right;
            }
        }

        return ans;
    }
};
