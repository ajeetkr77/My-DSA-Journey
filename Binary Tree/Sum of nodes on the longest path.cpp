class Solution {
  public:
    pair<int, int> solve(Node *root, pair<int, int> p){
        if(root == nullptr){
            return p;
        }
        
        pair<int, int> p1 = solve(root->left, {p.first+1, p.second + root->data});
        pair<int, int> p2 = solve(root->right, {p.first+1, p.second + root->data});
        
        if(p1.first > p2.first) return p1;
        else if(p1.first < p2.first) return p2;
        
        return (p1.second >= p2.second) ? p1 : p2;
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        pair<int, int> p = solve(root, {0, 0});
        return p.second;
        
    }
};
