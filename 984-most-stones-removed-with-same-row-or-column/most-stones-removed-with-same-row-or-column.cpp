// class Solution {
// public:
//     vector<int> parent;
//     vector<int> rank;

//     int find(int x) {
//         if(x == parent[x])
//          return x;

//         return parent[x] = find(parent[x]);
//     }

//     void Union(int x , int y) {
        
//         int x_parent = find(x);
//         int y_parent = find(x);

//         if(x_parent != y_parent) {
//             if(rank[x_parent] > rank[y_parent])
//              parent[y_parent] = x_parent;
//             else if(rank[x_parent] < rank[y_parent])
//              parent[x_parent] = y_parent;
//              else{
//              parent[y_parent] = x_parent;  
//              rank[x_parent]++;
//              }
//         }
//     }

//     bool check(vector<int> vec1, vector<int> vec2){
//         int x1 = vec1[0];
//         int y1 = vec1[1];

//         int x2 = vec2[0];
//         int y2 = vec2[1];

//         if(x1 == x2) 
//          return true;
//         if(y1 == y2)
//          return true;
        
//         return false;
//     }

//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
//         parent.resize(n);
//         rank.resize(n, 0);

//         for(int i = 0; i < n; i++) {
//             parent[i] = i;
//         }
       
//         int cnt = 0;
//         for(int i = 1; i < n; i++) {

//             // for(int j = i; j < v; j++) {
//                 if(check(stones[i], stones[i-1]) == true){
//                     cnt++;
//                 }   
//                     Union(stones[i][0], stones[i-1][0]);
//                     Union(stones[i][1], stones[i-1][1]);  
//             // }
//         }
//         return  cnt;
//     }
// };


class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent != y_parent) {
            if (rank[x_parent] > rank[y_parent])
                parent[y_parent] = x_parent;
            else if (rank[x_parent] < rank[y_parent])
                parent[x_parent] = y_parent;
            else {
                parent[y_parent] = x_parent;
                rank[x_parent]++;
            }
        }
    }

    bool check(vector<int>& vec1, vector<int>& vec2) {
        int x1 = vec1[0];
        int y1 = vec1[1];
        int x2 = vec2[0];
        int y2 = vec2[1];

        return (x1 == x2 || y1 == y2);
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(stones[i], stones[j])) {
                    Union(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                cnt++;
            }
        }

        return n - cnt;
    }
};
