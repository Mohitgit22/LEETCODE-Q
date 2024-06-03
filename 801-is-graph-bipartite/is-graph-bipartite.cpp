class Solution {
public:
    bool dfs( unordered_map<int, vector<int>>& mp, int u, vector<int>& color, int currcolor) {
        color[u] = currcolor;
        currcolor = 1 - currcolor;

        for(int &v: mp[u]){
            if(color[v] == color[u])
              return false;
            if(color[v] == -1){
                color[v] = currcolor;
                if( dfs(mp, v, color, currcolor) == false )
                 return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        //1. make the graph
        unordered_map<int, vector<int>> mp;
        int size = graph.size();
        for(int i = 0; i < size; i++) {
            for(int& v: graph[i]){
                mp[i].push_back(v);
            }
        }

        //check bipartite using dfs
        vector<int> color(size, -1);

        for(int i = 0; i < size; i++){
            if(color[i] == -1 && dfs(mp, i, color, 1) == false)
                  return false;
        }
        return true;
    }
};