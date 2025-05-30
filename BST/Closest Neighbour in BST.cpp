class Solution {
  public:
    int ans = -1;
    void solve(Node* root, int k){
        if(root == NULL ) return ;
        
        if(root->data <= k){
            ans = max(root->data, ans);
            solve(root->right, k);
        }
        
        if(root->data > k){
            solve(root->left, k);
        }
    }
    
    int findMaxFork(Node* root, int k) {
        // code here
        solve(root, k);
        return ans;
    }
};
