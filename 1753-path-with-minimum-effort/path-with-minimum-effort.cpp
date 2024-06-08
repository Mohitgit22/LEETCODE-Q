class Solution {
public:
   typedef pair<int, pair<int, int>> P;

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        if(m == 1 && n==1)
        return 0;

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({dist[0][0], {0, 0}});
        
        int dx[4] = {0 , 0 , -1, 1};
        int dy[4] = {-1, 1, 0 , 0};

        while(!pq.empty()){
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
          
            for(int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if(newx >=0 && newy >=0 && newx < m && newy < n ) {
                     int newdis = abs(heights[newx][newy] - heights[x][y]);

                     //for max effort
                    int maxdis = max(d, newdis);

                    if(maxdis < dist[newx][newy]){
                        dist[newx][newy] = maxdis;
                        pq.push({maxdis, {newx, newy}});
                }
            }
        }
    }
       
       return dist[m-1][n-1];
    }

};