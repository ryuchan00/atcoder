#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi = pair<int, int>;

double dp[310][310][310];
int N;

double rec(int i, int j, int k) {
    if (dp[i][j][k] >= 0) return dp[i][j][k];
    if (i == 0 && j == 0 && k == 0) return 0.0;

    double res = 0.0;
    if (i > 0) res += rec(i - 1, j, k) * i;
    if (j > 0) res += rec(i + 1, j - 1, k) * j;
    if (k > 0) res += rec(i, j + 1, k - 1) * k;
    res += N;
    res *= 1.0 / (i + j + k);

    return dp[i][j][k] = res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;
    // std::vector<int64_t> a(N);
    int one = 0, two = 0, three = 0;
    int a;

    REP(i, N) {
        std::cin >> a;
        if (a == 1)
            ++one;
        else if (a == 2)
            ++two;
        else
            ++three;
    }
    // 初期化
    memset(dp, -1, sizeof(dp));

    cout << fixed << setprecision(10) << rec(one, two, three) << endl;

    return 0;
}
