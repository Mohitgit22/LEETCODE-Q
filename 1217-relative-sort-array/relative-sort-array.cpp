class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
     
        int m = arr1.size();
        int n = arr2.size();

        // Count the frequency of elements in arr1
        for (int i = 0; i < m; i++) {
            mp[arr1[i]]++;
        }

        vector<int> ans;

        // Append elements from arr2 in the order they appear, respecting their count in arr1
        for (int i = 0; i < n; i++) {
            while (mp[arr2[i]] > 0) {
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }

        // Collect remaining elements not in arr2
        vector<int> remain;
        for (int i = 0; i < m; i++) {
            if (mp[arr1[i]] > 0) {
                remain.push_back(arr1[i]);
                mp[arr1[i]]--;
            }
        }

        // Sort the remaining elements
        sort(remain.begin(), remain.end());

        // Append sorted remaining elements to the answer
        for (auto x : remain) {
            ans.push_back(x);
        }

        // Print the result for debugging
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;

        return ans;
    }
};
