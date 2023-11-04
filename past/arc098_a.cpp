#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))
void dump(vector<ll> a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
}
void dump2(vector<vector<ll>> a) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

bool has_bit(int n, int i) {
  return (n & (1 << i)) > 0;
}

// 累積和の練習

int main() {
  ll N;
  string S;

  cin >> N;
  cin >> S;
  // 向きを変える必要がある人数の最小値を保持する変数
  // 答えになりえない大きい値で初期化しておく
  ll min_turn = 300000;

  vector<ll> sum_W = {0};
  rep(i, N) {
    if (S[i] == 'W') {
      sum_W.push_back(sum_W[i] + 1);
    } else {
      sum_W.push_back(sum_W[i]);
    }
  }

  rep(i, N) {
    // リーダーiより西側にいて西を向いている人の数
    ll w = sum_W[i];

    // リーダーiより東側にいて東を向いている人の数
    ll e = (N - 1 - i) - (sum_W[N] - sum_W[i + 1]);

    // 人iをリーダーとしたときの
    // 向きを変える必要がある人数
    ll turn = w + e;

    // リーダーiの場合について数え終わったら
    // 向きを変える必要がある人数の最小値を更新する
    min_turn = min(turn, min_turn);
  }
  cout << min_turn << endl;
}
