#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int bin_search(int arr[], int target, int n)
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
    return -1;
}
void marwan()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &vl : arr)
        cin >> vl;
    int target;
    cin >> target;
    (bin_search(arr, target, n) != -1) ? cout << bin_search(arr, target, n) << endl : cout << "Element not found\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        marwan();
    return 0;
}