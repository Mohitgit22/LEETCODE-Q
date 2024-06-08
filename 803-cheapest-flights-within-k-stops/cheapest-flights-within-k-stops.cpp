class Solution {
public:
    typedef pair<int,pair<int, int>> P;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto vec: flights) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v,w});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,{src, 0}});
              //{stops, {node, price}}

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!pq.empty()) {
            int stops = pq.top().first;

            auto conn = pq.top();
            int node = conn.second.first;
            int price = conn.second.second;
            pq.pop();
            

            if(stops > k)
                continue;

            for(auto it: adj[node]) {
                int v= it.first;
                int p = it.second;


                if(price + p < dist[v] ){
                    dist[v] = price + p;
                    pq.push({stops+1, {v, price + p}});
                }
            }
        }

        if(dist[dst] == 1e9)
        return -1;

        return dist[dst];
    }
};