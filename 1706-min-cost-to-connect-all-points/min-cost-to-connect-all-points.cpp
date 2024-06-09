class Solution {
public:
   typedef  pair<int, int> P;
    int spanningTree(int V, vector<vector<pair<int, int>>>& adj)
    {
        
        vector<bool> inMST(V, false);
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
            //{wt, node}
    
        int sum = 0;
        while(!pq.empty()) {
            auto it = pq.top();
            int node = it.second;
            int wt = it.first;
            
            pq.pop();
            
            if(inMST[node] == true)
            continue;
            
            inMST[node] = true;
            
            sum += wt;
            
            for(auto &edge : adj[node]) {
                int adjnode = edge.first;
                int adjnode_wt = edge.second;
                
                if(inMST[adjnode] == false)
                pq.push({adjnode_wt, adjnode});
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
      int V = points.size();

      vector<vector<pair<int, int>> > adj(V);

      for(int i = 0; i < V; i++) {
        for(int j = i + 1; j < V; j++) {
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) ;
            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
        }
      }

     return spanningTree(V, adj);
    }
};