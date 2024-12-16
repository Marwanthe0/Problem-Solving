#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    vector<string> temp, ans, temp2;
    string s = "";
    string cp;
    cin >> cp;
    if (cp == "4")
    {
        cout << 1 << endl;
        return;
    }
    else if (cp == "7")
    {
        cout << 2 << endl;
        return;
    }
    ll count = 3;
    temp.push_back("4");
    temp.push_back("7");
    ans.push_back("4");
    ans.push_back("7");
    for (ll i = 1; i <= 10; i++)
    {
        for (ll j = 0; j < 2; j++)
        {
            if (j < (1))
            {
                for (ll k = 0; k < temp.size(); k++)
                {
                    string tpp = "4" + temp[k];
                    temp2.push_back(tpp);
                    if (tpp == cp)
                    {
                        cout << count << endl;
                        return;
                    }
                    count++;
                }
            }
            else
            {
                for (ll k = 0; k < temp.size(); k++)
                {
                    string tpp = "7" + temp[k];
                    temp2.push_back(tpp);
                    if (tpp == cp)
                    {
                        cout << count << endl;
                        return;
                    }
                    count++;
                }
            }
        }
        // for (auto vl : temp2)
        //     cout << vl << " ";
        cout << endl;
        temp.clear();
        temp = temp2;
        temp2.clear();
    }
    for (auto vl : ans)
        cout << vl << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}