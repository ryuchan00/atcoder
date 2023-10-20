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

// https://atcoder.jp/contests/abc007/tasks/abc007_3

int main() {
  ll R, C;
  ll sy, sx;
  ll gy, gx;
  cin >> R >> C;
  cin >> sy >> sx;
  cin >> gy >> gx;

  vector<vector<ll>> S(R, vector<ll>(C));

  rep(i, R) {
    rep(j, C) {
      char c;
      cin >> c;
      S[i][j] = c;
    }
  }

  // 1始まりの入力を0に戻す
  sy--;
  sx--;
  gy--;
  gx--;


  // 始点からの最短距離を保持する2次元配列
  // -1であれば未訪問
  vector<vector<int>> dist(R, vector<int>(C, -1));

  // キューを用意して，始点を入れる
  queue<pair<ll, ll>> Q;
  pair<ll, ll> start = make_pair(sy, sx);
  Q.push(start);
  dist[sy][sx] = 0;
  while (Q.size() > 0) {
    int i = Q.front().first;
    int j = Q.front().second;
    Q.pop();
    // // 4つの隣接マスを確認する
    vector<ii> neighborhood = {make_pair(i - 1, j), make_pair(i + 1, j), make_pair(i, j - 1), make_pair(i, j + 1)};
    rep(n, neighborhood.size()) {
      int i2 = neighborhood[n].first;
      int j2 = neighborhood[n].second;
      // もし盤面の範囲でなければ無視する
      if (i2 < 0 || i2 >= R || j2 < 0 || j2 >= C) {
        continue;
      }
      // もし壁マスであれば無視する
      if (S[i2][j2] == '#') {
        continue;
      }
      // もし未訪問(dist[i2][j2] == -1)であれば，距離を更新してキューに入れる
      if (dist[i2][j2] == -1) {
        dist[i2][j2] = dist[i][j] + 1;
        Q.push(make_pair(i2, j2));
      }
    }
  }
  // 始点から終点までの最小移動回数を出力
  cout << dist[gy][gx] << endl;
}
