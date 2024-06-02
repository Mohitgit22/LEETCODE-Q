class Solution {
public:
   
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){
        visited[u] = true;

        //visit neighbours
        for(int& v : adj[u]){
            if(!visited[v])
              dfs(adj, v, visited);
        }
    }

    void bfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){
        visited[u] = true;

        queue<int> que;
        que.push(u);
        while(!que.empty()){
            int curr = que.front();
            que.pop();

            for(int& v:adj[curr]){
                if(!visited[v])
                  bfs(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) { 
    int n = isConnected.size();

    vector<bool>visited(n, false);

    //make graph
    unordered_map<int, vector<int>> adj;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
             if(isConnected[i][j] == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
             }
        }
    }

    int cnt = 0;

    for(int i = 0; i<n; i++){
        if(!visited[i]){
            // u can use dfs or bfs
            //1. dfs
            dfs(adj, i, visited);
            //2. bfs
            bfs(adj,i, visited);
            cnt++;
        }
    }

    return cnt;
    }
};