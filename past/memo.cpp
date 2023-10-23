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
// メモ化再帰の練習
// dp_a.cppと同じ問題をメモ化再帰で解く
vector<ll> H;
// cost[i]:足場iにたどり着くまでの最小コスト
vector<ll> cost;
// 完了フラグ
vector<bool> done;

ll rec(ll i) {
  // 計算済みか？
  if (done[i]) {
    return cost[i];
  }
  // そうでなければ値を計算
  if (i == 0) {
    cost[i] = 0;
  } else if (i == 1) {
    cost[i] = rec(0) + abs(H[0] - H[1]);
  } else {
    cost[i] = min(rec(i - 1) + abs(H[i - 1] - H[i]), rec(i - 2) + abs(H[i - 2] - H[i]));
  }
  // 計算済みフラつをたて，値を返す
  done[i] = true;
  return cost[i];
}

int main() {
  // ll N, X, Y;
  // cin >> N >> X >> Y;
  ll N;
  cin >> N;

  rep(i, N) {
    ll h;
    cin >> h;
    H.push_back(h);

    cost.push_back(0);
    done.push_back(false);
  }

  cout << rec(N - 1) << endl;
}
