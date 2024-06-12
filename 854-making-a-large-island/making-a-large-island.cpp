class Solution {
public:
     vector<int> parent;
     vector<int> size;
      
     int find(int x) {
        if(x == parent[x])
         return x;

        return parent[x] = find(parent[x]);
     }

     void UnionBySize(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent)
           return ;

        if(size[x_parent] > size[y_parent]){
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }else if(size[x_parent] < size[y_parent]){
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }else{
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
     }
     
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        parent.resize(n*n);
        size.resize(n*n, 1);

        for(int i = 0; i < n*n; i++) {
            parent[i] = i;
        }
        
        int dx[4] = {0, 0 , -1, 1};
        int dy[4] = {-1, 1, 0 , 0};


      // step 1.

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 0)
                   continue;

                int x = i;
                int y = j;

                for(int k = 0; k < 4; k++) {
                    int newx = x + dx[k];
                    int newy = y + dy[k];
                    if(newx >= 0 && newy >= 0 && newx < n && newy < n && grid[newx][newy] == 1) {
                        int nodeno = x * n + y;
                        int adjnodeno = newx *n + newy;
                        
                            UnionBySize(nodeno, adjnodeno);
                        
                    }

                }
            }
        }

    //step 2.

    int ans = INT_MIN;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(grid[i][j] == 1)
            continue;
          
            set<int> components;
            int x = i;
            int y = j;

            for(int k = 0; k < 4; k++) {

                int newx = x + dx[k];
                int newy = y + dy[k];

                if(newx >= 0 && newy >= 0 && newx < n && newy < n && grid[newx][newy] == 1 ){
                        int nodeno = x * n + y;
                        int adjnodeno = newx *n + newy;
                        
                        int ultimateparent = find(adjnodeno);

                        components.insert(ultimateparent);
                }
            }
            int sizetotal = 0;
            for(auto it: components) {
                sizetotal += size[it];
            }

             ans = max(ans, sizetotal + 1);
        }
    }

    if(ans == INT_MIN)
      return n*n;

    return ans;
    }
};