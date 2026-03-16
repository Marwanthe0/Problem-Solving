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
int digsum(int a) {
    int sum = 0ll;
    while (a)
        sum += (a % 10), a /= 10;
    return sum;
}
void marwan() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << s << endl;
        return;
    }
    map<int, int> frq;
    int sum = 0ll;
    for (auto c : s) {
        frq[c - '0']++, sum += c - '0';
    }
    for (int x = 1; x <= sum; x++) {
        map<int, int> urq;
        int num = x;
        while (num > 9) {
            int temp = num;
            while (temp)
                urq[temp % 10]++, temp /= 10;
            num = digsum(num);
        }
        urq[num]++;
        bool flag = true;
        int thissum = 0;
        for (auto [i, j] : urq) {
            thissum += i * j;
            if (frq[i] < j) {
                flag = false;
                break;
            }
        }
        if (flag == false || sum - thissum != x)
            continue;
        for (int i = 1; i <= 9; i++) {
            int k = frq[i] - urq[i];
            while (k--)
                cout << i;
        }
        int k = frq[0] - urq[0];
        while (k--)
            cout << 0;
        num = x;
        while (num > 9) {
            cout << num;
            num = digsum(num);
        }
        cout << num << endl;
        return;
    }
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