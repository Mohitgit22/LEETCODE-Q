class Solution {
public:
        int delop(string s1,string s2,int m,int n) {

          int dp[m+1][n+1];
          for(int i =0; i< m+1; i++)
          dp[i][0] = i;
          for(int j =0; j< n+1; j++)
          dp[0][j] = j;

          for(int i =1; i< m+1;i++) {
            for(int j =1; j< n+1; j++) {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] =  dp[i-1][j-1];
                else{
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);

                }
            }
        }
        return dp[m][n];
        }

    int minDistance(string word1, string word2) {
          int m = word1.length();
          int n = word2.length();

          return delop(word1, word2, m ,n );
    }
};