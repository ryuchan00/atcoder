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

// https://atcoder.jp/contests/past202005-open/tasks/past202005_g
// 幅優先探索の練習
// https://qiita.com/u2dayo/items/819afa2f307aa2f07598

int main() {
  ll N, X, Y;
  cin >> N >> X >> Y;

  ll base = 201;
  ll size = base * 2;
  size += 1;
  // ll size = 5;

  ll sy = base;
  ll sx = base;
  ll gy = Y + base;
  ll gx = X + base;
  // cin >> R >> C;
  // cin >> sy >> sx;
  // cin >> gy >> gx;

  vector<vector<ll>> S(size, vector<ll>(size, 0));

  rep(i, N) {
    ll x, y;
    cin >> x >> y;
    x += base;
    y += base;
    // 1が障害物
    S[y][x] = 1;
  }

#ifdef DEBUG
  rep(i, size) {
    rep(j, size) {
      cout << S[i][j];
    }
    cout << endl;
  }
#endif

  // 1始まりの入力を0に戻す
  // gy--;
  // gx--;

  // 始点からの最短距離を保持する2次元配列
  // -1であれば未訪問
  vector<vector<ll>> dist(size, vector<ll>(size, -1));

  // キューを用意して，始点を入れる
  queue<pair<ll, ll>> Q;
  pair<ll, ll> start = make_pair(sy, sx);
  Q.push(start);
  dist[sy][sx] = 0;
  bool goal = false;
  while (Q.size() > 0) {
    ll i = Q.front().first;
    ll j = Q.front().second;
    Q.pop();
    // // 6つの隣接マスを確認する
    // プログラムはxy逆なので注意
    vector<ii> neighborhood = {make_pair(i + 1, j + 1), make_pair(i + 1, j), make_pair(i + 1, j - 1), make_pair(i, j + 1), make_pair(i, j - 1), make_pair(i - 1, j)};
    rep(n, neighborhood.size()) {
      ll i2 = neighborhood[n].first;
      ll j2 = neighborhood[n].second;
      // もし盤面の範囲でなければ無視する
      if (i2 < 0 || i2 >= S.size() || j2 < 0 || j2 >= S.size()) {
        continue;
      }
      // もし壁マスであれば無視する
      if (S[i2][j2] == 1) {
        continue;
      }
      // もし未訪問(dist[i2][j2] == -1)であれば，距離を更新してキューに入れる
      if (dist[i2][j2] == -1) {
        dist[i2][j2] = dist[i][j] + 1;
        Q.push(make_pair(i2, j2));
      }
      // ゴールについてたらwhileを終わらせる
      if (i2 == gy && j2 == gx) {
        goal = true;
        break;
      }
    }
  }
  // 始点から終点までの最小移動回数を出力
  if (goal) {
    cout << dist[gy][gx] << endl;
  } else {
    cout << -1 << endl;
  }
}
