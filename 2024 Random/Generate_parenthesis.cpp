#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// vector<string> answer;
// void generate_p(string &s, int open, int close)
// {
//     if (open == 0, close == 0)
//     {
//         answer.push_back(s);
//         return;
//     }
//     if (open > 0)
//     {
//         s.push_back('(');
//         generate_p(s, open - 1, close);
//         s.pop_back();
//     }
//     if (close > 0)
//     {
//         if (open < close)
//         {
//             s.push_back(')');
//             generate_p(s, open, close - 1);
//             s.pop_back();
//         }
//     }
// }
// void marwan()
// {
//     int n;
//     cin >> n;
//     string s = "";
//     generate_p(s, n, n);
//     for (auto ans : answer)
//         cout << ans << endl;
//     cout << endl;
//     answer.clear
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         marwan();
//     }
//     return 0;
// }
/*Doing the Same thing for second time*/
vector<string> ans;
void generate_parenthesis(string &s, int open, int close)
{
    if (!open && !close)
    {
        ans.push_back(s);
        return;
    }
    if (open > 0)
    {
        s.push_back('(');
        generate_parenthesis(s, open - 1, close);
        s.pop_back();
    }
    if (close > 0 && open < close)
    {
        s.push_back(')');
        generate_parenthesis(s, open, close - 1);
        s.pop_back();
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    string s = "";
    generate_parenthesis(s, n, n);
    for (auto vl : ans)
        cout << vl << endl;
    ans.clear();
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}