class Solution {
public:
   int mod = 1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , greater<int>> pq;

        for(auto it : nums){
            pq.push(it);
        }

        while(k--){
            int x = pq.top();
            pq.pop();
            x += 1;
            pq.push(x);
        }

       long long int ans = 1;
       while(!pq.empty()){
            ans = (ans * pq.top()) % mod;
            pq.pop();
        }
        return ans;
    }
};