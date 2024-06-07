class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if(x == parent[x])
          return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent != y_parent) {
            if(rank[x_parent] > rank[y_parent])
               parent[y_parent] = x_parent;
            else if(rank[x_parent] < rank[y_parent])
               parent[x_parent] = y_parent;
            else{
                 parent[x_parent] = y_parent;
                 rank[y_parent]++;
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n ; i++) {
            parent[i] = i;
        }

        //make components
          for(auto u: edges) {
            int x = u[0];
            int y = u[1];

            Union(x, y);
        }

        //make map to set the size of comp
        unordered_map<int, int> mp;
        for(int i = 0; i < n ; i++) {
            int x = find(i);
            mp[x]++;
        }

        //result
        long long result = 0;
        long long remaining = n;
        for(auto it : mp) {
            int size = it.second;
            result += size * (remaining - size);
            remaining -= size;
        }

        return result;
    }
};