class Solution {
public:

    bool dfs(unordered_map<int, vector<int>> adj, int u,  vector<int>& color) {
           
            queue<int> q;
            q.push(u);
            color[u] = 1;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(auto v : adj[node]){
                    if(color[v] == color[node])
                    return false;
                    if(color[v] == -1) {
                        color[v] = abs(1 - color[node]);
                        q.push(v);
                    }
                }
            }
            for(auto el : color) {
                cout<<el << " ";
            }
            
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        //make adjacency list

        unordered_map<int, vector<int>> adj;

    for (int i = 0; i < dislikes.size(); i++)
    {
        adj[dislikes[i][0]].push_back(dislikes[i][1]);
        adj[dislikes[i][1]].push_back(dislikes[i][0]);
    }

        //check bipartite
        vector<int> color(n+1, -1);
        for(int i = 1; i <= n; i++) {
            if(color[i] == -1){
                if(dfs(adj, i, color) == false)
                return false;
            }
        }
        return true;
    }
};
