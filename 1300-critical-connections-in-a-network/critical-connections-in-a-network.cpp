class Solution {
public:
     int timer = 1;

     void dfs(int node, int parent,  vector<vector<int>>& adj, vector<bool>& vis, int tin[], int low[],  vector<vector<int>>& bridges) {
           
           vis[node] = true;

           low[node] = tin[node] = timer;
           timer++;

           for(auto v : adj[node]) {

            //apart from parent, all adjacent nodes   --->. Tarjans algo 
            if(v == parent)
              continue;

            if(vis[v] == false) { 
                dfs(v, node, adj, vis, tin, low, bridges);
                low[node] = min(low[node], low[v]);

                //node --bridge---  v 
                if(low[v] > tin[node]) {
                   bridges.push_back({node, v});
                }
             }
            else{
                low[node] = min(low[node], low[v]);
            }
        }
     }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto it : connections) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);    
        }
        
        vector<bool> vis(n, false);

        int tin[n];
        int low[n];

        vector<vector<int>> bridges;

        for(int i = 0; i < n ;i++) {
            if(!vis[i])
               dfs(i, -1, adj, vis, tin, low, bridges);
        }

        return bridges;
    }
};