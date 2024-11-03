#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    map<char, char> L, R;

    L['q'] = 'w';
    L['e'] = 'r';
    L['t'] = 'y';
    L['u'] = 'i';
    L['o'] = 'p';
    L['a'] = 's';
    L['d'] = 'f';
    L['g'] = 'h';
    L['j'] = 'k';
    L['l'] = ';';
    L['z'] = 'x';
    L['c'] = 'v';
    L['b'] = 'n';
    L['m'] = ',';
    L['.'] = '/';
    L['w'] = 'e';
    L['r'] = 't';
    L['y'] = 'u';
    L['i'] = 'o';
    L['p'] = 'a';
    L['s'] = 'd';
    L['f'] = 'g';
    L['h'] = 'j';
    L['k'] = 'l';
    L[';'] = 'z';
    L['x'] = 'c';
    L['v'] = 'b';
    L['n'] = 'm';
    L[','] = '.';

    R['w'] = 'q';
    R['r'] = 'e';
    R['y'] = 't';
    R['i'] = 'u';
    R['p'] = 'o';
    R['s'] = 'a';
    R['f'] = 'd';
    R['h'] = 'g';
    R['k'] = 'j';
    R[';'] = 'l';
    R['x'] = 'z';
    R['v'] = 'c';
    R['n'] = 'b';
    R[','] = 'm';
    R['/'] = '.';

    R['e'] = 'w';
    R['t'] = 'r';
    R['u'] = 'y';
    R['o'] = 'i';
    R['a'] = 'p';
    R['d'] = 's';
    R['g'] = 'f';
    R['j'] = 'h';
    R['l'] = 'k';
    R['z'] = ';';
    R['c'] = 'x';
    R['b'] = 'v';
    R['m'] = 'n';
    R['.'] = ',';

    char c;
    cin >> c;
    string s;
    cin >> s;
    if (c == 'L')
    {
        for (int i = 0; i < s.size(); i++)
            cout << L[s[i]];
    }
    else
        for (int i = 0; i < s.size(); i++)
            cout << R[s[i]];
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}