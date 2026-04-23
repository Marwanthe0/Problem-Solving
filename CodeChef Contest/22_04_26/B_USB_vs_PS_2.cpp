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
void marwan() {
    int a, b, c;
    cin >> a >> b >> c;
    int m;
    cin >> m;
    vector<int> usb, ps2;
    while (m--) {
        int x;
        string s;
        cin >> x >> s;
        if (s == "USB")
            usb.push_back(x);
        else
            ps2.push_back(x);
    }
    sort(all(usb), greater<int>());
    sort(all(ps2), greater<int>());
    int com = 0ll, price = 0ll;
    while (a-- && !usb.empty()) {
        price += usb.back(), com++;
        usb.pop_back();
    }
    while (b-- && !ps2.empty()) {
        price += ps2.back(), com++;
        ps2.pop_back();
    }
    while (c--) {
        if (usb.empty() && ps2.empty())
            break;
        else if (usb.empty()) {
            com++, price += ps2.back();
            ps2.pop_back();
        } else if (ps2.empty()) {
            com++, price += usb.back();
            usb.pop_back();
        } else {
            com++;
            if (usb.back() < ps2.back()) {
                price += usb.back();
                usb.pop_back();
            } else {
                price += ps2.back();
                ps2.pop_back();
            }
        }
    }
    cout << com << " " << price << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}