class Solution {
public:
int mod=1e9+7;
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

         long long int dp[m+1][n+1];
        for(int i =0; i< n+1; i++) {
              dp[0][i] = 0;
        }
        for(int i =0; i< m+1; i++) {
              dp[i][0] = 1;
        }

    
       for(int i = 1; i< m+1; i++) {
        for(int j =1; j< n+1; j++) {
            if(s[i-1] == t[j-1]){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }else
                  dp[i][j] = dp[i-1][j];
        }
       }
       return dp[m][n];
    }
};