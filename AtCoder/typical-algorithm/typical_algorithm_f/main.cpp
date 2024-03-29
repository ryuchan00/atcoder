#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

int64_t solve(ll N, int M, const std::vector<int64_t> &u, const std::vector<int64_t> &v, const std::vector<int64_t> &c) {
    vector<vector<pi>> G(N);
    REP(i, M) {
        G[u[i]].push_back(make_pair(v[i], c[i]));
        // 無向グラフになるので反対向きにも保存しておく
        G[v[i]].push_back(make_pair(u[i], c[i]));
    }

    /*
    プリム法で最小全域木問題を解く
    */

    vector<bool> marked(N, false);

    ll marked_count = 0;  // N=marked_countのとき終了

    marked[0] = true;
    marked_count++;

    priority_queue<pi, vector<pi>, greater<pi>> Q;
    // 頂点0を調べる
    for (const auto &g : G[0]) {
        ll j = g.first;
        ll c = g.second;
        Q.push(make_pair(c, j));
    }

    ll sum = 0;
    pi top;

    while (marked_count < N) {
        top = Q.top();
        ll c = top.first;
        ll i = top.second;
        // cout << c << " " << i << endl;
        Q.pop();

        if (marked[i]) {
            continue;
        }

        // 頂点iをマークする
        marked[i] = true;
        marked_count++;

        // 使った辺は最小全域木となるので重みを保存しておく
        sum += c;

        for (const auto &g : G[i]) {
            ll j = g.first;
            ll c2 = g.second;

            if (marked[j]) {
                continue;
            }
            Q.push(make_pair(c2, j));
        }
    }

    return sum;
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll N;
    int M;
    std::cin >> N >> M;
    std::vector<int64_t> u(M), v(M), c(M);
    REP(i, M) {
        std::cin >> u[i] >> v[i] >> c[i];
    }
    auto ans = solve(N, M, u, v, c);
    std::cout << ans << '\n';
    return 0;
}