#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int x,y;cin>>x>>y;
    if(x - y >= 18) cout<<"RCB\n";
    else cout<<"CSK\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        marwan();
    return 0;
}