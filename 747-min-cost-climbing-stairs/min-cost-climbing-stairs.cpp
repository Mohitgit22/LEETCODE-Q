class Solution {
public:
    //using recursion
    // int mincost(vector<int>& cost, int n) {
    //     if(n == 0 || n == 1) 
    //     return 0;
           
        //    int onestep = cost[n-1] + mincost(cost, n-1);
        //    int twostep = cost[n-2] + mincost(cost, n-2);
    //     return min(onestep, twostep);
    // }
  
     //using top down approach
    //  int mincost(vector<int>& cost, int n, vector<int>& dp) {
    //     if(n == 0 || n==1)
    //     return 0;

    //     if(dp[n] == -1){
    //         dp[n] = min(cost[n-1] + mincost(cost, n-1, dp) , 
    //                    cost[n-2] + mincost(cost, n-2, dp));
    //     }

    //     return dp[n];
    //  }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();   

    //     vector<int> dp(n+1, -1);
    //    dp[0] = 0;
    //    dp[1] = 0;
       //bottom up
    //    for(int state = 2; state <= n ; state++) {
    //     int onestep = cost[state - 1] + dp[state - 1];
    //     int twostep = cost[state - 2] + dp[state - 2];
    //     dp[state] = min(onestep, twostep);
    //    }

    //space optimized bottom up
    int prev1  = 0;
    int prev2 = 0;
    int ans = 0;
        for(int state = 2; state <= n ; state++) {
        int onestep = cost[state - 1] + prev1;
        int twostep = cost[state - 2] + prev2;

        ans = min(onestep, twostep);
         prev2 = prev1;
         prev1 = ans;
       }

    //    return mincost(cost, n, dp);
    return ans;
    }
};