#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void Selection(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[i])
                swap(v[j], v[i]);
        }
    }
}
void printarr(vector<int> &v)
{
    for (auto vl : v)
        cout << vl << " ";
    cout << endl;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    // Printing Before Sort
    printf("Printing Before Sort:\n");
    printarr(v);
    // Using Selection Sort
    Selection(v);
    printf("Printing After Sort:\n");
    printarr(v);
}
int main()
{
    marwan();
    return 0;
}