class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        bool dp[m+1][n+1];

        for(int i = 0; i< m+1; i++) {
            for(int j = 0; j< n+1; j++) {
                if(i==0 && j==0)
                  dp[i][j] = true;
                else
                  dp[i][j] = false;
            }
        }
           for (int i = 1; i <= n; i++) {
            if (p[i - 1] == '*')//staribng char is matched with the string , if * it willl accept everything 
                dp[0][i] = true;
            else
                break;
        }


        for(int i = 1; i< m+1; i++) {
            for(int j = 1; j<n+1; j++) {
                if((s[i-1] == p[j-1]) || p[j-1] == '?')
                      dp[i][j]= dp[i-1][j-1];
                 if(p[j-1] == '*')
                      dp[i][j] =  dp[i-1][j] || dp[i][j-1];
                
            }
        }
        return dp[m][n];
    }
};