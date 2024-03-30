class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         int m = coins.size();
         int n = amount;

         int dp[m+1][n+1];
         //Inititalising the DP i.e. 1st row and 1st col
         for(int i = 0; i< m+1; i++) {
            dp[i][0] = 0;
          }

         for(int i =0; i< n+1; i++) {
            dp[0][i] = INT_MAX - 1;
         }
     
        //Inititalising the DP i.e. 1st row and 1st col
          for(int i =1; i< n+1; i++) {
            if(i%coins[0] == 0)
                dp[1][i] = i/coins[0];
            else
                dp[1][i] = INT_MAX - 1;
          }

          // Unbounded knapsack code
          for(int  i =2 ; i< m+1; i++) {
            for(int  j =1; j< n+1; j++) {
                if(coins[i-1] <= j)
                dp[i][j] = min(1+ dp[i][j-coins[i-1]], dp[i-1][j]);
                else
                dp[i][j] = dp[i-1][j];
            }
          }

          if(dp[m][n] == INT_MAX - 1 || dp[m][n] == INT_MAX)
          return -1;
          else
          return dp[m][n];


    }
};