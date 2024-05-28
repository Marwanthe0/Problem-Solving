#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int a,b;
    cin>>a>>b;
    a = a^b;
    b = a^b;
    a = a^b;
    cout<<a<<" "<<b<<endl;
}
int main()
{
    marwan();
    return 0;
}