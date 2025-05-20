class Solution {
public:
    TreeNode* findNode(TreeNode* root, int target){
        
        if(root == nullptr)
            return nullptr;
            
        if(root->val == target){
            return root;
        }
        
        TreeNode* Left = findNode(root->left, target);
        TreeNode* Right = findNode(root->right, target);
        
        if(Left == nullptr) return Right;
        
        return Left;
    }


    int amountOfTime(TreeNode* root, int target) {
        unordered_map<TreeNode*, TreeNode*> parent;
        
        queue<TreeNode*> q;
        
        if(root == nullptr) return 0;
        
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left){
                q.push(curr->left);
                parent[curr->left] = curr;
            }
            
            if(curr->right){
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
        
        
        queue<pair<TreeNode*, int>> Q;
        
        TreeNode* start = findNode(root, target);
        
        cout<<start->val;
        
        Q.push({start, 0});
        
        unordered_map<TreeNode*, int> vis;
        
        vis[start] = 1;
        
        int timeRequired = 0;
        
        while(!Q.empty()){
            
            TreeNode* curr = Q.front().first;
            
            int time = Q.front().second;
            
            timeRequired = max(time, timeRequired);
            
            Q.pop();
            
            if(curr->left && !vis[curr->left]){
                Q.push({curr->left, time + 1});
                vis[curr->left] = 1;
            }
            
            if(curr->right && !vis[curr->right]){
                Q.push({curr->right, time + 1});
                vis[curr->right] = 1;
            }
            
            if(parent[curr] && !vis[parent[curr]]){
                Q.push({parent[curr], time + 1});
                vis[parent[curr]] = 1;
            }
            
        }
        
        return timeRequired;
    }
};
