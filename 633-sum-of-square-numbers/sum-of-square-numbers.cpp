class Solution {
public:
    bool judgeSquareSum(int c) {
       if (c < 0) 
       return false;
        
        long long s = 0;
        long long e = (sqrt(c));
        
        while (s <= e) {
            long long sum = s * s + e * e;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                s++;
            } else {
                e--;
            }
        }
        return false;
    }
};