#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    vector<vector<int>> pr(n, vector<int>(n, 0)), tr;
    for (auto &s : v)
        cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i] == '1')
                pr[i][j]++, tr[i][j]++;
            if (j)
                pr[i][j] += pr[i][j - 1];
            if (i)
                tr[i][j] += tr[i - 1][j];
        }
    }
    int ans = 0ll;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < n; k++) {
                // checking from i,j ---- i,k   x,j --- x,k
                int cur_sum = pr[i][k] - (j ? pr[i][j - 1] : 0);
                if (cur_sum > k)
                    break;
                int req = k - cur_sum;
                int l = i, r = n - 1,tans = ;

                while(l <= r){
                    
                }
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}