class Solution {
public:
 void dfs( vector<vector<int>>& adj, int u, vector<bool>& vis) {
          vis[u] = true;

          for(int& v: adj[u]) {
            if(!vis[v])
                    dfs(adj, v, vis);
          }
 }

 void bfs( vector<vector<int>>& adj, int u, vector<bool>& vis) {
     vis[u] = true;
     queue<int> que;
    que.push(u);

    while(!que.empty()) {
        int node = que.front();
        que.pop();

        for(int&v: adj[node]) {
            if(vis[v] == false){
              vis[v] = true;
              que.push(v);
        }
    }
 }
 }
 int makeConnected(int n, vector<vector<int>>& connections) {
    vector<bool> vis(n, false);

    if(n-1 > connections.size())
      return -1;

    vector<vector<int>> adj(n);

    for(int i = 0; i < connections.size(); i++) {
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }
   
    int cnt = 0; 
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            //dfs(adj, i, vis);
            bfs(adj, i, vis);
            cnt++;
        }
    }

    return cnt - 1;
 }

};
//   vector<int> parent;
//     vector<int> rank;

//     int find(int x) {
//         if(x == parent[x])
//            return x;
        
//         return parent[x] = find(parent[x]);
//     }

//     void union_dsu(int x, int y) {
//         int x_parent = find(x);
//         int y_parent = find(y);
       
        
//         if(rank[x_parent] > rank[y_parent]) 
//            parent[y_parent] = x_parent;
//         else if(rank[y_parent] > rank[x_parent])
//            parent[x_parent] = y_parent;
//         else{
//             parent[x_parent] = y_parent;
//             rank[y_parent]+= 1;
//         }
//     }
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         parent.resize(n);
//         rank.resize(n, 0);

//         for(int i = 0; i < n; i++) {
//             parent[i] = i;
//         }
//          if(n-1 > connections.size() )
//             return -1;

//         int components = n;
//         for(auto &conn : connections) {
//             int x = conn[0];
//             int y = conn[1];

//             int x_parent = find(x);
//             int y_parent = find(y);

//             if(x_parent != y_parent){
//                 union_dsu(x, y);
//                 components -= 1;
//             }
//         }

//         return components-1;
//     }
// };