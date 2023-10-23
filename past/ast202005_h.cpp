#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))
// #define DEBUG;

// https://atcoder.jp/contests/past202005-open/tasks/past202005_h
int main() {
  ll N, L;
  cin >> N >> L;
  vector<ll> X(N);
  rep(i, N) {
    ll x;
    cin >> x;
    X[i] = x;
  }
  ll T1, T2, T3;
  cin >> T1 >> T2 >> T3;

  // ハードルがある座標においてTrue
  vector<bool> H(L + 1, false);
  rep(i, X.size()) {
    H[X[i]] = true;
  }

  vector<ll> cost(L + 1, 1000 * 100000);

  // 初期条件
  cost[0] = 0;

  for (int i = 1; i < L + 1; i++) {
    // 行動1
    cost[i] = min(cost[i], cost[i - 1] + T1);
    // 行動2
    if (i >= 2) {
      cost[i] = min(cost[i], cost[i - 2] + T1 + T2);
    }
    // 行動3
    if (i >= 4) {
      cost[i] = min(cost[i], cost[i - 4] + T1 + 3 * T2);
    }
    // もしハードルがあれば加算
    if (H[i]) {
      cost[i] += T3;
    }
  }
  // ピッタリとまれないときに調整
  ll ans = cost[L];
  rep(i, 3) {
    for (int i = 3; i > 0; i--) {
      // 残り距離1,2,3のとき
      // cout << cost[L - i + 1] + T1 / 2 + T2 * (2 * (L - (L - i + 1)) - 1) / 2 << endl;
      ll l = L - i;
      ans = min(ans, cost[l] + T1 / 2 + T2 * (2 * (L - l) - 1) / 2);
    }
  }
  cout << ans << endl;
}