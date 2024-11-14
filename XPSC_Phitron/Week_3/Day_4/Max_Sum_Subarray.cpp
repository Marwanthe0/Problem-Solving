#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
long long maximumSumSubarray(vector<int> &arr, int k)
{
    long long l = 0, r = 0, n = arr.size(), sum = 0, ans = 0;
    while (r < n)
    {
        sum += arr[r];
        if (r - l + 1 == k)
        {
            ans = max(sum, ans);
            sum -= arr[l];
            l++, r++;
        }
        else
        {
            r++;
        }
    }
    return ans;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int k;
    cin >> k;
    cout << maximumSumSubarray(v, k) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}