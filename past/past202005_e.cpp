#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))

// N*Nの隣接行列を使用する方法

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;

  // False のN*Nの2次元配列を作る
  vector<vector<bool>> graph(N, vector<bool>(N, false));

  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    graph[u][v] = true;
    graph[v][u] = true;
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
      rep(j, N) {
        if (graph[x][j]) {
          C[j] = C[x];
        }
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