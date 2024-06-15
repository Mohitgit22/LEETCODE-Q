class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < points.size(); i++) {
            int x = abs(points[i][0]);
            int y = abs(points[i][1]);
            int dist = pow(x,2) + pow(y,2);

            pq.push({dist,i});

            if(pq.size() > k)
              pq.pop();
        }

    vector<vector<int>> ans;

      while(!pq.empty()) {
         int dis = pq.top().first;
         int idx = pq.top().second;
         ans.push_back(points[idx]);

         pq.pop();
    }
    return ans;
        
    }
};