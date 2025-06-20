class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        map<int, int> freqMap;
        
        for(int x: arr) freqMap[x]++;
        
        for(auto p : freqMap){
            
            int val = p.first;
            int freq = p.second;
            
            if(freq == 0) continue;
            
            for(int i = 1; i < k; i++){
                
                int nextVal = val + i;
                
                if(freqMap[nextVal] < freq) return false;
                
                freqMap[nextVal] -= freq;
            }
        }
        
        return true;
    }
};
