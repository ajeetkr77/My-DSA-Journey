class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int sum = 0;
        
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                
                string temp = s.substr(i, j - i + 1);
                sum += stoi(temp);
            }
        }
        
        return sum;
    }
};
