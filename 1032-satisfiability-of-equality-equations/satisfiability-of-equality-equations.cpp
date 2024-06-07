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

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);
        
        for(int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < equations.size(); i++) {
            if(equations[i][1] == '='){
            char first =  equations[i][0];
            char second = equations[i][3];
            union_dsu(first - 'a', second - 'a');
            }
        }

        for(int i = 0;i < equations.size(); i++) {
            if(equations[i][1] == '!'){
            int x = find(equations[i][0] - 'a');
            int y = find(equations[i][3] - 'a');
            if(x == y)
             return false;
          }
        }

        return true;
    }
};