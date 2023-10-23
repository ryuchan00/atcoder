#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))
using ll = long long;
using ii = pair<ll, ll>;
// #define DEBUG;

// https://atcoder.jp/contests/dp/tasks/dp_a
// 動的計画法の練習

int main() {
  // ll N, X, Y;
  // cin >> N >> X >> Y;
  ll N;
  cin >> N;

  vector<ll> H(N);
  rep(i, N) {
    ll h;
    cin >> h;
    H[i] = h;
  }

  // cost[i]:足場iにたどり着くまでの最小コスト
  vector<ll> cost(N, 0);

  // 初期条件
  cost[0] = 0;
  // 2つめの足場はジャンプ元が1通り
  cost[1] = abs(H[0] - H[1]);
  // それ以降の足場はコストが低い方を採用する
  for (int i = 2; i < N; i++) {
    cost[i] = min(cost[i - 1] + abs(H[i - 1] - H[i]), cost[i - 2] + abs(H[i - 2] - H[i]));
  }

  cout << cost[N - 1] << endl;
}
