class Solution {
public:
    bool canPartition(vector<int>& nums) {
           int sum = 0;
           int N = nums.size();
        for(int i =0; i<N; i++) {
            sum += nums[i];
        }
        if(sum%2 !=0)
        return false;
        
        int w = sum/2;
        
        int dp[N+1][w+1];
        for(int i =0; i<=w; i++)
           dp[0][i] = 0;
        for(int i = 0; i<= N; i++)
           dp[i][0] = 1;
        
        for(int i = 1 ;i <=N; i++){
            for(int j =1 ;j <=w; j++) {
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                   dp[i][j] = dp[i-1][j];
            }
        }
        if(dp[N][w] == 1)
        return true;
        else
        return false; 
    }
};