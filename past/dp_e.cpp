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

#define rep(i, n) for (ll i = 0; (i) < (n); ++(i))
const int L = 1e5 + 1;
// #define DEBUG;

// https://atcoder.jp/contests/dp/tasks/dp_e
// 参考
// https://atcoder.jp/contests/dp/submissions/46922701
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N;
  ll W;
  cin >> N >> W;
  vector<int> ws(N + 1), vs(N + 1);
  // 1始まりにするために先頭にダミーを入れる
  ws[0] = 0;
  vs[0] = 0;
  for (int i = 1; i < N + 1; ++i) {
    cin >> ws[i] >> vs[i];
  }
  // cout << 1e5 + 5 << endl;

  // value[i][w]:品物iまで見て重さ合計wであるときの価値の総和の最大値
  // vector<vector<ll>> value(N + 1, vector<ll>(N + 1, -2 * pow(10, 9)));
  // vector<vector<int>> value(N + 1, vector<int>(N + 1, -2 * pow(10, 9)));
  // vector<vector<int>> value(N + 1, vector<int>(L, 0));
  vector<vector<ll>> value(N + 1, vector<ll>(L, 2 * pow(10, 9)));

  // 初期条件
  value[0][0] = 0;

  // // iが小さい順に求めていく
  // ll ww = W;
  // if (W > 100 * 10000) {
  //   ww = 100 * 10000;
  // }
  // for (int i = 1; i < N + 1; ++i) {
  //   for (int w = 0; w < ww; ++w) {
  //     // 品物iを使わない場合
  //     value[i][w] = value[i - 1][w];
  //     // 品物iを使う場合
  //     if (w - ws[i] >= 0) {
  //       value[i][w] = max(value[i][w], value[i - 1][w - ws[i]] + vs[i]);
  //     }
  //   }
  // }
  // auto it = max_element(value[N].begin(), value[N].end());
  // cout << *it << endl;
  // ll ans = 0;
  // for (int i = 1; i < N + 1; ++i) {
  //   if (value[N][i] <= W) {
  //     ans = max(ans, value[N][i]);
  //   }
  // }
  // cout << ans << endl;

  // iが小さい順に求めていく
  // for (ll i = 1; i < N + 1; ++i) {
  //   for (int w = 0; w < W; ++w) {
  //     // 品物iを使わない場合
  //     value[i][w] = max(value[i][w], value[i - 1][w]);
  //     // 品物iを使う場合
  //     // if (i - vs[i] >= 0) {
  //     if (w - ws[i] >= 0) {
  //       value[i][w] = max(value[i][w], value[i - 1][w - ws[i]] + vs[i]);
  //     }
  //   }
  // }
  for (int i = 1; i < N + 1; ++i) {
    for (int v = 0; v < L; ++v) {
      // 品物iを使わない場合
      // value[i][v] = min(value[i][v], value[i - 1][v]);
      value[i][v] = value[i - 1][v];
      // 品物iを使う場合
      // if (w - ws[i] >= 0) {
      if (v - vs[i] >= 0) {
        value[i][v] = min(value[i][v], value[i - 1][v - vs[i]] + ws[i]);
      }
    }
  }
  // auto it = max_element(value[N].begin(), value[N].end());
  // cout << *it << endl;
  ll ans = 0;
  for (ll i = 1; i < L; ++i) {
    if (value[N][i] <= W) {
      ans = max(ans, i);
    }
  }
  cout << ans << endl;
}