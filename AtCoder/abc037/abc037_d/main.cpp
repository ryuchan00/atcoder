#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi = pair<int, int>;

template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int H, W;
std::vector<std::vector<ll>> a(1010, vector<ll>(1010));
// vector<vector<int>> G;  // グラフ
// メモ化再帰
ll dp[1010][1010] = {0};

const ll MOD = 1000000007;

ll rec(ll x, ll y) {
    if (dp[x][y] != 0) return dp[x][y];  // 更新が終わっている

    vector<vector<ll>> travel = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    ll res = 0;
    for (auto t : travel) {
        if (x + t[0] < 0 || x + t[0] >= H || y + t[1] < 0 || y + t[1] >= W) {
            continue;
        }
        if (a[x + t[0]][y + t[1]] > a[x][y]) {
            res = res +  rec(x + t[0], y + t[1]);
            res % MOD;
        }
    }
    // rec(x + t[0], y + t[1]);
    dp[x][y] = res + (ll)1;
    dp[x][y] %= MOD;
    return res + (ll)1;  // メモしながらreturn
}

// int res = 0;
// for (auto nv : G[v]) {
//     chmax(res, rec(nv) + 1);
// }

// return dp[v] = res;  // メモしながらreturn

long long solve() {
    ll ans = 0;

    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            ans += rec(i, j);
            ans %= MOD;
        }
    }

    // ll ans = 0;
    // for (int i = 0; i < H; ++i) {
    //     for (int j = 0; j < W; ++j) {
    //         ans += dp[i][j];
    //     }
    // }
    return ans;
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> H >> W;

    REP(i, H) {
        REP(j, W) {
            std::cin >> a[i][j];
        }
    }
    ll r = solve();
    std::cout << r << '\n';
    return 0;
}