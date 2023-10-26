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
// #define DEBUG;

// https://atcoder.jp/contests/dp/tasks/dp_d
int main() {
  ll N, W;
  cin >> N >> W;
  vector<ll> ws;
  vector<ll> vs;
  // 1始まりにするために先頭にダミーを入れる
  ws.push_back(0);
  vs.push_back(0);
  rep(_, N) {
    ll w, v;
    cin >> w >> v;
    ws.push_back(w);
    vs.push_back(v);
  }

  // value[i][w]:品物iまで見て重さ合計wであるときの価値の総和の最大値
  vector<vector<ll>> value(N + 1, vector<ll>(W + 1, 0));

  // 初期条件
  value[0][0] = 0;

  // iが小さい順に求めていく
  for (ll i = 1; i < N + 1; ++i) {
    rep(w, W + 1) {
      // 品物iを使わない場合
      value[i][w] = max(value[i][w], value[i - 1][w]);
      // 品物iを使う場合
      if (w - ws[i] >= 0) {
        value[i][w] = max(value[i][w], value[i - 1][w - ws[i]] + vs[i]);
      }
    }
  }
  auto it = max_element(value[N].begin(), value[N].end());
  cout << *it << endl;
}