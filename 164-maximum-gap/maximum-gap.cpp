class Solution {
public:
    int maximumGap(vector<int>& nums) {
        priority_queue<int , vector<int> , greater<int>> pq;
        for(auto it : nums){
            pq.push(it);
        }

        if(pq.size() == 0)
        return 0;

        int maxi = INT_MIN;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();

            maxi = max(maxi, abs(x - pq.top()));
        }
        return maxi;
    }
};