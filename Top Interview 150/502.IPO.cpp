class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++) vec.push_back({capital[i] , profits[i]});

        sort(vec.begin(), vec.end());

        int maxCapital = w;

        priority_queue<int> pq;

        // for(int i = 0; i < n; i++){

        //     if( vec[i].first <= maxCapital )pq.push(vec[i].second);

        //     else{
        //         if(pq.empty()) break;

        //         maxCapital += pq.top();

        //         pq.pop();

        //         if( vec[i].first <= maxCapital )pq.push(vec[i].second);

        //         k--;
        //     }

        //     if(k == 0) break;

        // }

        // while(k && !pq.empty()){
        //     maxCapital += pq.top();

        //     pq.pop(); 

        //     k--;
        // }
        int i = 0;
        while(k--){

            while(i < n && vec[i].first <= maxCapital){
                pq.push(vec[i].second);
                i++;
            }

            if(pq.empty()) break;

            maxCapital += pq.top();

            pq.pop();
        }

        return maxCapital;
    }
};
