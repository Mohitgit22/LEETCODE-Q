class Solution {
public:
    int minInsertions(string s) {
           int m = s.length();
           string temp = s;

          //min insertions = string length - longest plaindromic subsequence
           reverse(s.begin(), s.end());
           string p = s;
           s=temp;
          int n = p.length();

          int dp[m+1][n+1];
          for(int i =0; i<m+1; i++) {
            for(int j =0; j<n+1; j++) {
                if(i ==0 || j==0)
                   dp[i][j] = 0;
            }
          }
       
          for(int i = 1; i<m+1; i++) {
            for(int j =1; j< n+1 ;j++) {
                if(s[i-1] == p[j-1])
                   dp[i][j] =1+ dp[i-1][j-1];
                else
                   dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
          }

          int maxlengthpali = dp[m][n];
          int minoperations = m - maxlengthpali;
          return minoperations;
    }
};