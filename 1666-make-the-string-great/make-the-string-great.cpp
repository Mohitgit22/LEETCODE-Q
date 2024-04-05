class Solution {
public:
    string makeGood(string s) {
        string res = "";
        for(int i = 0; i < s.length(); i++) {
             if(res.empty() == false && abs(res.back() -s[i])==32)
                   res.pop_back();
             else
              res += (s[i]);
        }
         return res;
    }
};