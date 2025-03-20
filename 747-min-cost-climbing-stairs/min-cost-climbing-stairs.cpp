class Solution {
public:
    //using recursion
    // int mincost(vector<int>& cost, int n) {
    //     if(n == 0 || n == 1) 
    //     return 0;

    //     return min(cost[n-1] + mincost(cost, n-1) , 
    //                cost[n-2] + mincost(cost, n-2));
    // }
  
     //using top down approach
     int mincost(vector<int>& cost, int n, vector<int>& dp) {
        if(n == 0 || n==1)
        return 0;

        if(dp[n] == -1){
            dp[n] = min(cost[n-1] + mincost(cost, n-1, dp) , 
                       cost[n-2] + mincost(cost, n-2, dp));
        }

        return dp[n];
     }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();   
        vector<int> dp(n+1, -1);
       dp[0] = 0;
       dp[1] = 0;
       return mincost(cost, n, dp);
    }
};