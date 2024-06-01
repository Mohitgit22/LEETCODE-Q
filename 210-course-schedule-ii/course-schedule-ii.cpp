class Solution {
public:
    bool isCycleDfs(vector<int> adj[], int u, vector<bool>& visited, vector<bool> &inRecursion){
        visited[u] = true;
        inRecursion[u] = true;

        for(int &v: adj[u]){
            if(!visited[v] && isCycleDfs(adj, v, visited, inRecursion))
            return true;
            else if(inRecursion[v] == true)
            return true;
        }
        inRecursion[u] = false;
        return false;
    }

    void topo(vector<int> adj[], int u, vector<bool>& visited, stack<int>& st){
            visited[u] = true;

            for(int &v: adj[u]){
                if(!visited[v])
                  topo(adj, v, visited, st);
            }

            st.push(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
         
         //1. form the adjcaceny list
        for(vector<int> &x: prerequisites){
            int u = x[1];
            int v = x[0];
            adj[u].push_back(v);
        }

        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        vector<int> ans;

        //2. check for cycle -> if present return empty array 
        for(int i = 0; i < n; i++) {
            if(!visited[i] && isCycleDfs(adj, i, visited, inRecursion))
            return ans;
        }
         
         for(auto x: visited){
              x = false;
         }
        stack<int> st;

        for(int i =0; i < n; i++) {
            if(!visited[i])
              topo(adj, i, visited, st);
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }
};