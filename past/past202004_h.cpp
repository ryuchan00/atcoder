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

// N*Nの隣接行列を使用する方法

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<string>> A(N, vector<string>(M, ""));
  rep(i, N) {
    string a;
    cin >> a;
    rep(j, M) {
      A[i][j] = a[j];
    }
  }

  // 番号ごとに座標を分類，スタートは0，ゴールは10
  vector<vector<pair<ll, ll>>> group(11);
  rep(i, N) {
    int n;
    rep(j, M) {
      if (A[i][j] == "S") {
        n = 0;
      } else if (A[i][j] == "G") {
        n = 10;
      } else {
        // cout << "j: " << j << endl;
        // cout << stoi(A[i][j]) << endl;
        n = stoi(A[i][j]);
      }
      group[n].push_back(make_pair(i, j));
    }
  }

  // cost[i][j]: 数字を正しく通ってマス(i,j)にたどり着く最小移動回数
  // 非常に大きい値で初期化しておく
  ll inf = 2e18;
  // ll inf = pow(10, 100);
  vector<vector<ll>> cost(N, vector<ll>(M, inf));
  // rep(i,cost.size()) {
  //   rep(j,cost[i].size()) {
  //     cout << cost[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // 初期条件．スタート地点の座標はgroup[0][0]
  ll si = group[0][0].first;
  ll sj = group[0][0].second;
  cost[si][sj] = 0;

  // nが小さい方から順番に求めていく
  for (int n = 1; n < 11; ++n) {
    // 更新したいマスそれぞれについてループ
    for (const auto& g : group[n]) {
      ll i = g.first;
      ll j = g.second;
      // 数字がn-1であるマス全てを試す
      for (const auto& g2 : group[n - 1]) {
        // for (int g=0;g < group.size();++g) {
        ll i2 = g2.first;
        ll j2 = g2.second;
        // ll i2 = group[n][g].first;
        // ll j2 = group[n][g].second;
        cost[i][j] = min(cost[i][j], cost[i2][j2] + abs(i - i2) + abs(j - j2));
      }
    }
  }
  // rep(i,group.size()){
  //   cout << group[i].first << " " << group[i].second << endl;
  // }
  // rep(i, cost.size()) {
  //   rep(j, cost[i].size()) {
  //     cout << cost[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  ll gi = group[10][0].first;
  ll gj = group[10][0].second;
  ll ans = cost[gi][gj];
  if (ans == inf) {
    ans = -1;
  }
  cout << ans << endl;
}