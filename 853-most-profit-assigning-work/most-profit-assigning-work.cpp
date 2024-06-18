class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        // sort(worker.begin(), worker.end());
        //   int ans= 0 ;
           
        // for(int i = 0; i < worker.size(); i++) {
        //     int dif = -1;
        //     for(int j = 0; j < difficulty.size(); j++) {
        //         if(worker[i] >= difficulty[j]){
        //             dif = max(dif, j);
        //         }
        //     }
        //     if(dif == -1)
        //     continue;
        //     ans += profit[dif];
        // }

        // return ans;


         int n = difficulty.size();
        vector<pair<int, int>> jobs(n);

        for (int i = 0; i < n; i++) {
            jobs[i] = {difficulty[i], profit[i]};
        }

        // Sort jobs by difficulty
        sort(jobs.begin(), jobs.end());
        // Sort workers by their ability
        sort(worker.begin(), worker.end());

        int maxProfit = 0, i = 0, best = 0;
        
        for (int ability : worker) {
            // Update best profit we can achieve with current ability
            while (i < n && ability >= jobs[i].first) {
                best = max(best, jobs[i].second);
                i++;
            }
            maxProfit += best;
        }

        return maxProfit;
    }
};