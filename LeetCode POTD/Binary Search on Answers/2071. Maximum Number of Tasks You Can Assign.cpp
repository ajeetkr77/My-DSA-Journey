class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        int pillsUsed = 0;
        multiset<int> st(workers.begin(), workers.begin() + mid);

        for(int i = mid - 1; i >= 0; i--){
            
            int req = tasks[i];
            auto it = prev(st.end());

            if(*it >= req){
                st.erase(it);
            }else if(pillsUsed >= pills){
                return false;
            }else{
                auto weakestWorkerIt = st.lower_bound(req - strength);

                if(weakestWorkerIt == st.end()) return false;

                st.erase(weakestWorkerIt);

                pillsUsed++;
            }
        }

        return true;
    }


    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int task = tasks.size();

        int worker = workers.size();

        int taskDone = 0;

        sort(workers.begin(), workers.end(), greater<int>());
        sort(tasks.begin(), tasks.end());

        int l = 0, r = min(task, worker);

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(check(tasks, workers, pills, strength, mid)){

                taskDone = mid;

                l = mid + 1;

            }else{

                r = mid - 1;

            }
        }
        
        return taskDone;
    }
};
