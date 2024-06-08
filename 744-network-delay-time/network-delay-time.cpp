class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto vec: times) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> result(n+1, INT_MAX);
        result[k] = 0;

        while(!pq.empty()){ 
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjnode = it.first;
                int dist = it.second;

                if(d+dist < result[adjnode]){
                    result[adjnode] = d + dist;
                    pq.push({ d + dist, adjnode});
                }
            }
        }
        int mini = INT_MIN;
     for(int i = 1; i <= n; i++){
        if(result[i] == INT_MAX)
         return -1;
        mini = max(mini, result[i]);
     }   
     return mini;


    }
};