class Solution {
public:

bool check(vector<int>& vec1, vector<int>& vec2) {
    if(vec1[0] == vec2[0] || vec1[1] == vec2[1])
      return true; 

      return false;
}

void dfs(vector<vector<int>>& stones, int i, vector<bool>& vis ) {
          vis[i] = true;

          for(int j = 0; j < stones.size(); j++) {
            if(check(stones[i], stones[j]) && !vis[j])
               dfs(stones, j, vis);
          }
      }
int removeStones(vector<vector<int>>& stones) {
      int n = stones.size();
      vector<bool> vis(n, false);
      
      int cnt = 0;
      for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(stones, i, vis);
            cnt++;
        }
      }

      return n - cnt;
} 
};