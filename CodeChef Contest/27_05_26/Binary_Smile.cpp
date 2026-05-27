#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    int aone = 0, bone = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1')
            aone++;
        if (b[i] == '1')
            bone++;
    }
    if (aone != bone) {
        minus;
        return;
    }
    string tb = b;
    int count = 0, count2 = 0;
    for (int i = 0, j = 0; i < n || j < n; i++, j++) {
        if (a[i] == b[j])
            continue;
        if (a[i] == '1') {
            int temp = j;
            while (j < n && b[j] != '1')
                j++;
            b[j] = '0';
            j = temp;
            count++;
        } else if (b[j] == '1') {
            int temp = i;
            while (i < n && a[i] != '1') {
                i++;
            }
            a[i] = '0';
            i = temp;
            count++;
        }
    }
    cout << (count) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}