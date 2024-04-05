class Solution {
public:
    string makeGood(string s) {
        string res = "";
        //it handles cases where more than two adjacent characters need to be removed and
        // it may be present before and after a bad combo.
        //eg "abBAcC"
        //bB is the bad part , after removing ,
        // we need to check the resultant string that is there any formation of a bad combo from last char and current char
        for(int i = 0; i < s.length(); i++) {
             if(res.empty() == false && abs(res.back() -s[i])==32)
                   res.pop_back();
             else
              res += (s[i]);
        }
         return res;
    }
};