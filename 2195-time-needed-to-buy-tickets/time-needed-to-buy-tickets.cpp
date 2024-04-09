class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
           map<int, int> mp;
        for(int i = 0; i < tickets.size(); i++) {
             mp[i] = tickets[i];
        }
        
        int cnt = 0;
        while (mp[k] > 0) {
            bool flag = false;
            for(auto& p : mp) {
                if (p.second > 0) {
                    cnt++;
                    p.second--;
                    if (p.first == k && p.second == 0) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) break;
        }
        return cnt;


        // map<int, int> mp;
        // for(int i= 0; i< tickets.size(); i++) {
        //      mp[i] = tickets[i];
        // }
        
        // int cnt = 0;
        // for(auto it: mp) {
        //     if(mp.count(k)!=0){
        //        cnt = cnt + mp.size();
        //        for(auto p : mp){
        //           p.second = p.second-1;
        //           if(p.second == 0){
        //             mp[p] = mp[p].clear();
        //           }
        //        }
        //     }
            
        // }
        // return cnt;
    }
};