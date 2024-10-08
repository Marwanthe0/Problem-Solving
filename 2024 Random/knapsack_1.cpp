#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int knapsack(int n, vector<int> v, vector<int> w, int weight)
{
    if(n <= 0 || weight == 0) return 0;
    if (w[n] <= weight)
    {
        // case 1
        int ans1 = knapsack(n - 1, v, w, weight - w[n]) + v[n];
        // case 2
        int ans2 = knapsack(n - 1, v, w, weight);
        return max(ans1,ans2);
    }
    else
    {
        // case 2
        int ans = knapsack(n - 1, v, w, weight);
        return ans;
    }
}
void marwan()
{
    int n, weight;
    cin >> n >> weight;
    vector<int> w(n), v(n);
    for (auto &vl : w)
        cin >> vl;
    for (auto &vl : v)
        cin >> vl;
    cout<<knapsack(n - 1, v, w, weight)<<endl;
}
int main()
{
    marwan();
    return 0;
}