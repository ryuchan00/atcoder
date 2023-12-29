#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi = pair<int, int>;

int N;
int h[200010];
// int a[200010];

// BIT(1-indexed)
ll bit[200010];

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    int a = 1;
    N = 10;
    for (; a <= N;) {
        cout << "a:" << a << endl;
        bitset<8> bs(a);
        cout << " " << bs << endl;

        cout << "-a:" << -a << endl;
        bs = bitset<8>(-a);
        cout << " " << bs << endl;

        cout << "(a & -a):" << (a & -a) << endl;
        cout << "a + (a & -a)" << a + (a & -a) << endl;
        a = a + (a & -a);
    }

    a = 1;
    for (; a <= N;) {
        cout << "a:" << a << endl;

        a = a * 2;
    }
    return 0;
}