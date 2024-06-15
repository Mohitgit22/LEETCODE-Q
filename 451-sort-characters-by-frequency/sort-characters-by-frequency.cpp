class Solution {
public:
    typedef pair<int, char> P;
    string frequencySort(string s) {
        
        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        priority_queue<P> maxh;

        for(auto it = mp.begin(); it != mp.end(); it++){
            maxh.push({it->second, it->first});
        }

        string ans = "";

        while(!maxh.empty()) {
            char ch = maxh.top().second;
            int freq = maxh.top().first;

            maxh.pop();

            while( freq!=0 ) {
                ans += ch;
                freq--;
            }
        }

        return ans;
    }
};