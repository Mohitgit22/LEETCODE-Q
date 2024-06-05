class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int u, vector<int>& vis, vector<int>& pathvis, vector<int>& check) {
        vis[u] = 1;
        pathvis[u] = 1;
        check[u] = 0; // it is not confirmed as safenode
        
        for(int& v : graph[u]) {
            if(vis[v] == 0){
                if(dfs(graph, v, vis, pathvis, check) == true) 
                   return true;
            }
                else if(pathvis[v] == 1) 
                    return true;
            }
        
        check[u] = 1;
        pathvis[u] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

    int v = graph.size();

    vector<int> vis(v, 0);
    vector<int> pathvis(v, 0);
    vector<int> check(v, 0);

        for(int i = 0; i < v; i++) {
            if(vis[i] == 0)
              dfs(graph, i, vis, pathvis, check);
         }
        
         vector<int> safeNodes;
        for(int i =0 ; i < v; i++) {
            if(check[i] == 1)
             safeNodes.push_back(i);
        }

        return safeNodes;
    }
};



// this is also equivalent

//  class Solution {
// public:
    
// 	// cycle detection
//     bool dfs(vector<vector<int>>& graph, int src, vector<bool> &visited, vector<bool> &dfsVisited){
//         visited[src]=true;
//         dfsVisited[src]=true;
        
//         for(int i=0;i<graph[src].size();i++){
//             int child=graph[src][i];
//             if(visited[child]==false){
//                 if(dfs(graph,child,visited,dfsVisited)) return true;
//             }else{
//                 if(dfsVisited[child]==true) return true;
//             }
//         }
//         dfsVisited[src]=false;
//         return false;
//     }
    
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n=graph.size();
        
//         vector<bool> visited(n,false), dfsVisited(n,false);
        
//         vector<int> ans;
//         for(int i=0;i<n;i++){
//             if(dfs(graph,i,visited,dfsVisited)==false) ans.push_back(i);
//         }
        
//         return ans;
//     }
// };