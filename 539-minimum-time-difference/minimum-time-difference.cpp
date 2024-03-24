class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // vector<int> v;
        // for(int i=0; i<timePoints.size(); i++) {
        //     int p = timePoints[i][timePoints[i].length()-1];
        //     int q = timePoints[i][timePoints[i].length()-2];
        //     int minute = 10*q + p;
        //     if(minute == 0)
        //     v.push_back(60);
        //     else
        //     v.push_back(minute);
        // }
        // sort(v.begin(),v.end());
        // int ans = INT_MAX;
        // for(int i =1; i<v.size(); i++) {
        //     if(v[i-1] == v[i])
        //       return 0;
        //     else{
        //         ans = min(ans, (v[i]-v[i-1]));
        //     }
        // }
        // return ans;

             vector<int> minutes;
        for (const string& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3));
            minutes.push_back(hour * 60 + minute); // Convert time to minutes
        }
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        int n = minutes.size();
        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        // Consider the circular nature of time
        minDiff = min(minDiff, (24 * 60 - minutes[n - 1] + minutes[0]));
        
        return minDiff;
    }
};