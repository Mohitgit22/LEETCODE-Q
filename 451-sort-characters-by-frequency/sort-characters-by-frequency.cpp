class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(int i=0 ; i<s.length(); i++) {
            mp[s[i]]++;
        }
      
        vector<pair<int, char>> v;
        for(auto it: mp) {
              v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end());
        string p ="";
        //
            for(int i=v.size()-1;i>=0;i--)
        {
           int x=v[i].first;
           char c=v[i].second; 
           while(x>0)
           {
               p+=c;
                x--;
           }    
        }
        return p;

    }
};
