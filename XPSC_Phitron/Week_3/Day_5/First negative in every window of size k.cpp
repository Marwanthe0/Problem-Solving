class Solution
{
public:
    vector<int> FirstNegativeInteger(vector<int> &arr, int k)
    {
        // write code here
        vector<int> ans;
        queue<int> q;
        int n = arr.size();
        int l = 0, r = 0;
        while (l < n && r < n)
        {
            if (arr[r] < 0)
                q.push(arr[r]);
            if (r - l + 1 == k)
            {
                if (q.empty())
                    ans.push_back(0);
                else
                {
                    ans.push_back(q.front());
                    if (arr[l] == q.front())
                        q.pop();
                }
                l++, r++;
            }
            else
                r++;
        }
        return ans;
    }
};