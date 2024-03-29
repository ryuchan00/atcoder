#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi = pair<int, int>;

constexpr long long MOD = 1000000007;
const string T = "atcoder";

// aにbを足してMODをとる関数
ll add(ll a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

long long solve(long long N, std::string S) {
    vector<vector<ll>> dp(N + 1, vector<ll>(T.size() + 1, 0));
    dp[0][0] = 1;

    // dp[i+1][j]の値を順に求めていく
    REP(i, N) {
        REP(j, T.size() + 1) {
            // S[i]を選ばない場合
            dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);

            // S[i]を選ぶ場合
            if (j > 0 && S[i] == T[j - 1]) {
                dp[i + 1][j] = add(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[N][T.size()];
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long N;
    std::string S;
    std::cin >> N >> S;
    auto ans = solve(N, S);
    std::cout << ans << '\n';
    return 0;
}
