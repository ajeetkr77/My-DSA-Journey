class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        int level = 0;
        
        //queue<Node*> q;
        stack<Node*> s1, s2;
        
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        s1.push(root);
        
        while(!s1.empty() || !s2.empty()){
            
            int n;
            
            if(level % 2 == 0){
                n = s1.size();
                for(int i = 0; i < n; i++){
                
                    Node* temp = s1.top();
                    s1.pop();
                    ans.push_back(temp->data);
                    
                    if(temp->right){
                        s2.push(temp->right); 
                    } 
                    
                    if(temp->left){
                       s2.push(temp->left); 
                    } 
                    
                    
                
                }
            }else{
                n = s2.size();
                for(int i = 0; i < n; i++){
                
                    Node* temp = s2.top();
                    s2.pop();
                    
                    ans.push_back(temp->data);
                    
                    if(temp->left) s1.push(temp->left);
                    
                    if(temp->right) s1.push(temp->right);
                
                }
            }
            
            level++;
        }
        
        return ans;
    }
};
