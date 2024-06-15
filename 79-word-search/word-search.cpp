class Solution {
public:
    bool search_dfs(vector<vector<char>>& board, int word_idx, int x, int y, int dx[], int dy[], string word, vector<vector<bool>>& vis) {
         
        int m = board.size();
        int n = board[0].size();

        if(word_idx == word.size()) 
           return true;


         //check for neighbours , do they match the folllowing letters;
           for(int i = 0; i < 4; i++) {
               int newx = x + dx[i];
               int newy = y + dy[i];

               if(newx >=0 && newy >= 0 && newx < m && newy < n && board[newx][newy] == word[word_idx] && !vis[newx][newy]){
                vis[newx][newy] = true;
                 if(search_dfs(board,word_idx + 1, newx, newy, dx, dy, word, vis)) 
                 return true;
                 vis[newx][newy] = false;
               }
           }
           return false;
    }



    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

       int dx[4] = {0, 0 ,-1, 1};
       int dy[4] = {-1, 1, 0, 0};


        char ch = word[0];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                  if(board[i][j] == ch){
                   vector<vector<bool>> vis(m, vector<bool>(n, false));
                   vis[i][j] = true;
                   if(search_dfs(board, 1, i, j ,dx, dy, word,vis)) 
                     return true;
                  }
            }
        }
        return false;
    }
    };