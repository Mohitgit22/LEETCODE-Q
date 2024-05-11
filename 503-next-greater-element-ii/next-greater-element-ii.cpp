class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> ans;
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (st.empty())
                ans.push_back(-1);
            else if (!st.empty() && st.top() > nums[i])
                ans.push_back(st.top());
            else if (!st.empty() && st.top() <= nums[i])
            {
                while (!st.empty() && st.top() <= nums[i])
                {
                    st.pop();
                }
                if (st.empty())
                {
                    bool flag = false;
                    for (int j = 0; j < i; j++)
                    {
                        if (nums[i] < nums[j])
                        {
                            flag = true;
                            ans.push_back(nums[j]);
                            break;
                        }
                    }
                    if (flag == false)
                        ans.push_back(-1);

                    flag = false;
                }
                //   ans.push_back(-1);
                else
                    ans.push_back(st.top());
            }
            st.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        ans.pop_back();

        bool flag = false;
        for(int i = 0; i < nums.size()-1 ; i++) {
            if(nums[nums.size()-1] < nums[i]){
                flag = true;
                ans.push_back(nums[i]);
                break;
            }
        }
        if(flag == false)
          ans.push_back(-1);
        return ans;
    }
};