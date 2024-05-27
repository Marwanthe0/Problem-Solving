#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    string s, world;
    getline(cin, s);
    reverse(s.begin(), s.end());
    stringstream ss(s);
    while (ss >> world)
    {
        reverse(world.begin(), world.end());
        cout << world << endl;
    }
}
int main()
{
    marwan();
    return 0;
}