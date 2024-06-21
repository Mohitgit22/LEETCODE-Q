class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        if(barcodes.size() == 0 || barcodes.size() == 1)
        return barcodes;

        unordered_map<int, int> mp;
        for(auto it : barcodes){
            mp[it]++;
        }
       
        priority_queue<pair<int, int>> pq;
        for(auto it : mp){
            // {freq, number}
            pq.push({it.second, it.first});
        }
     
        vector<int> ans;
        while(pq.top().first > 0) {

            //processing the first element
            pair<int, int> p = pq.top();
            pq.pop();
            int node = p.second;

            ans.push_back(node);
            p.first--;

            pair<int, int> q = pq.top();
            pq.pop();
            if(q.first > 0){
                ans.push_back(q.second);
                q.first--;
            }
            pq.push(p);
            pq.push(q);
        }
        return ans;
    }
};