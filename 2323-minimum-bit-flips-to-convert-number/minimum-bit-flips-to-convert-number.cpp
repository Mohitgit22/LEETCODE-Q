class Solution {
public:
    int countNoOfSetBits(int ans) {
        int cnt = 0;
        for(int i = 0; i < 31; i++) {
            if(ans & (1<<i))
            cnt++;
        }
        return cnt;
    }
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;

        return countNoOfSetBits(ans);
    }
};