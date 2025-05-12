*********************************************************
    Brute Force
*********************************************************


class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();

        vector<int> ans;
        unordered_set<int> st;

        for(int i = 0; i < n; i++){
            if(digits[i] != 0){
                string temp = to_string(digits[i]);
                for(int j = 0; j < n; j++){
                    if(i != j){
                        temp += to_string(digits[j]);

                        for(int k = 0; k < n; k ++){
                            if(k != j && k != i){
                                temp += to_string(digits[k]);
                                //cout<<i<<" "<<j<<" "<<k<<" "<<temp<<endl;
                                int y = stoi(temp);
                                if(y % 2 == 0)
                                    st.insert(y);
                                temp.pop_back();
                            }
                        }
                        temp.pop_back();
                    }
                }
            }
        }

        for(auto x : st){
            ans.push_back(x);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
***********************************************************************
 Optimal Approach 
***********************************************************************

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();

        vector<int> result;

        map<int, int> mp;

        for(int i = 0; i < n; i++) mp[digits[i]]++;

        for(int i = 1; i <= 9; i++){
            if(mp[i] > 0){ 
                mp[i]--;
                for(int j = 0; j < 10; j++){
                    if(mp[j] > 0){
                        mp[j]--;
                        for(int k = 0; k < 10; k+=2){
                            if(mp[k] > 0){
                                mp[k]--;
                                int num = i*100 + j*10 + k;
                                result.push_back(num);
                                mp[k]++;
                            }
                        }
                        mp[j]++;
                    }
                }
                mp[i]++;
            }
        }

        return result;

    }    
};
