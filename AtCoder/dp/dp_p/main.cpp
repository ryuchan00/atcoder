// https://kyopro-friends.hatenablog.com/entry/2019/01/12/231035
// https://scrapbox.io/ganariya-competitive/AtCoderDP%E3%81%BE%E3%81%A8%E3%82%81%E3%82%B3%E3%83%B3%E3%83%86%E3%82%B9%E3%83%88_P%E5%95%8F%E9%A1%8C_%E3%80%8CIndependent_Set%E3%80%8D
// https://qiita.com/Series_205/items/6bad5c32a1fce8dc2914

#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#include "atcoder/modint.hpp"
using mint = atcoder::modint1000000007;

constexpr int64_t MOD = 1000000007;
vector<vector<ll>> a;

mint dp[100010][2] = {0};

void f(int i, int p) {
    dp[i][0] = 1;
    dp[i][1] = 1;
    for (ll j : a[i]) {
        // 親に返る辺は無視
        if (j == p) {
            continue;
        }
        f(j, i);
        dp[i][0] = dp[i][0] * (dp[j][0] + dp[j][1]);
        dp[i][1] = dp[i][1] * dp[j][0];
    }
}

int64_t solve(int N) {
    f(0, -1);
    return (dp[0][0].val() + dp[0][1].val()) % MOD;
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    a.resize(N);
    // std::vector<ll> x(N - 1), y(N - 1);
    ll x, y;
    REP(i, N - 1) {
        std::cin >> x >> y;
        --x;
        --y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    auto ans = solve(N);
    REP(i, N) {
        // sort(a[i].begin(), a[i].end());
        // REP(j,a[i].size()){
        //     cout << a[i][j] << " ";
        // }
        // cout << endl;
    }
    std::cout << ans << '\n';
    return 0;
}
