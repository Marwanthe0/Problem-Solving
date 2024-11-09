#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        long long N;
        int P;
        cin >> N >> P;

        string winner;
        if (N % 2 == 0) {  // N is even
            winner = "Oddius";
        } else {  // N is odd
            winner = (P == 1) ? "Oddius" : "Evenius";
        }

        cout << "Case " << case_num << ": " << winner << endl;
    }
    return 0;
}
