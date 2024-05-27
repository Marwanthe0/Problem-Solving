#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int lower_bnd(vector<int> arr, int target, int n)
{
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == target)
            return mid + 1;
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start + 1;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int target;
    cin >> target;
    cout << lower_bnd(v, target, n) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}