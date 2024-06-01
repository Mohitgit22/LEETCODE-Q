class Solution {
public:

    bool isCycleDfs(vector<int> adj[], int u, vector<bool>& visited, vector<bool>& inRecursion) {

        visited[u] = true;
        inRecursion[u] = true;
        for(int &v: adj[u]){
            if(!visited[v] && isCycleDfs(adj, v, visited, inRecursion))
            return true;
            else if(visited[v] == true && inRecursion[v] == true)
            return true;
        }

        inRecursion[u] = false;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];

        for(auto x : prerequisites){
            vector<int> data = x;
            int u = data[0];
            int v = data[1];
            adj[u].push_back(v);
        }

        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);

        for(int i = 0; i<n; i++) {
            if(visited[i] == false && isCycleDfs(adj, i,visited, inRecursion))
            return false;
        }
        return true;
    }
};