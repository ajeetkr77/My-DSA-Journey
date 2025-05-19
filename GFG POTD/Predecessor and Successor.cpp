************************************************************
  Time Complexity  : O(n)
  Space Complexity : O(n)
************************************************************


class Solution {
  public:
    void solve(Node* root, int key, vector<Node*> &ans){
        if(root == NULL) return;
        
        solve(root->left, key, ans);
        
        ans.push_back(root);
        
        solve(root->right, key, ans);
        
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        
        solve(root, key, ans);
        
        int n = ans.size();
        
        vector<Node*> result(2, NULL);
        
        for(int i = 0; i < n; i++){
            if(ans[i]->data < key){
                result[0] = ans[i];
            }
            
            if(ans[i]->data > key){
                result[1] = ans[i];
                break;
            }
        }
        return result;
    }
};


************************************************************
  Time Complexity  : O(n)
************************************************************
class Solution {
  public:
    void solve(Node* root, int key, vector<Node*> &ans, int& mark1){
        if(root == NULL) return;
        
        solve(root->left, key, ans, mark1);
        
        if(root->data < key){
            ans[0] = root;
        }
        
        if(root->data > key && mark1 == 0){
            ans[1] = root;
            mark1 = 1;
            return;
        }
        
        solve(root->right, key, ans, mark1);
        
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans(2, NULL);
        
        int mark1 = 0;
        
        solve(root, key, ans, mark1);
    
        return ans;
    }
};
