class Solution {
public:
  vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if(x == parent[x])
           return x;
        
        return parent[x] = find(parent[x]);
    }

    void union_dsu(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
       
        
        if(rank[x_parent] > rank[y_parent]) 
           parent[y_parent] = x_parent;
        else if(rank[y_parent] > rank[x_parent])
           parent[x_parent] = y_parent;
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]+= 1;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
         if(n-1 > connections.size() )
            return -1;

        int components = n;
        for(auto &conn : connections) {
            int x = conn[0];
            int y = conn[1];

            int x_parent = find(x);
            int y_parent = find(y);

            if(x_parent != y_parent){
                union_dsu(x, y);
                components -= 1;
            }
        }

        return components-1;
    }
};