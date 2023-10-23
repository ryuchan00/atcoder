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

// https://atcoder.jp/contests/atc001/tasks/dfs_a
// 深さ優先探索の練習

void dfs(ll i, ll j, vector<vector<string>>& S, vector<vector<bool>>& visited) {
  visited[i][j] = true;
  // 4つの隣接マスを確認する
  vector<vector<ll>> neighborhood = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  rep(n, neighborhood.size()) {
    ll i2 = i + neighborhood[n][0];
    ll j2 = j + neighborhood[n][1];
    // 範囲外ならスキップ
    if (i2 < 0 || i2 >= S.size() || j2 < 0 || j2 >= S[0].size()) {
      continue;
    }
    // 壁ならスキップ
    if (S[i2][j2] == "#") {
      continue;
    }
    // 未訪問であれば再帰的に呼び出す
    if (visited[i2][j2] == false) {
      dfs(i2, j2, S, visited);
    }
  }
}

int main() {
  // ll N, X, Y;
  // cin >> N >> X >> Y;
  ll H, W;
  cin >> H >> W;

  vector<vector<string>> S;

  rep(i, H) {
    string s;
    cin >> s;
    vector<string> ss;
    rep(j, s.size()) {
      ss.push_back(s.substr(j, 1));
    }
    S.push_back(ss);
  }

  //

#ifdef DEBUG
  rep(i, size) {
    rep(j, size) {
      cout << S[i][j];
    }
    cout << endl;
  }
#endif

  // 始点と終点の座標を探し，それぞれ(si,sj)と(gi,gj)とする
  ll sj, si, gj, gi;
  rep(i, H) {
    rep(j, W) {
      if (S[i][j] == "s") {
        si = i;
        sj = j;
      }
      if (S[i][j] == "g") {
        gi = i;
        gj = j;
      }
    }
  }

  // 訪問済みかどうか管理する2次元配列
  vector<vector<bool>> visited(H, vector<bool>(W, false));

  // 再起関数dfsを定義する
  dfs(si, sj, S, visited);

  // 終点が訪問済みかどうかを判定する
  if (visited[gi][gj]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
