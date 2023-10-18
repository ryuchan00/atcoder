#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))

// 隣接リストを使用する方法

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;

  // False のN*Nの2次元配列を作る
  vector<vector<int>> graph(N);

  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // 頂点の色リストを受け取る
  vector<int> C(N);
  rep(i, N) { cin >> C[i]; }

  // Q個のクエリを受け取って実行する
  rep(i, Q) {
    int query, x, y;
    cin >> query;
    // スプリンクラーを起動するクエリ
    if (query == 1) {
      cin >> x;
      x--;
      cout << C[x] << endl;
      rep(j, graph[x].size()) {
        C[graph[x][j]] = C[x];
      }
    } else {
      // スプリンクラーを起動しないクエリ
      cin >> x >> y;
      x--;
      cout << C[x] << endl;
      C[x] = y;
    }
  }
}