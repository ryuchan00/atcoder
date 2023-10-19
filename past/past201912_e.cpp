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
  int N, Q;
  cin >> N >> Q;

  vector<vector<bool>> graph(N, vector<bool>(N, false));

  // Q個のクエリを受け取って実行する
  rep(i, Q) {
    int query, a, b;
    cin >> query >> a;
    a--;

    // フォロー操作
    if (query == 1) {
      cin >> b;
      b--;
      graph[a][b] = true;
    }
    // フロー全返し
    if (query == 2) {
      rep(v, N) {
        // 頂点vから頂点aへと辺があるとき
        if (v != a && graph[v][a]) {
          // 頂点aから頂点vへと辺を張る
          graph[a][v] = true;
        }
      }
    }
    // フォローフォロー
    if (query == 3) {
      // 頂点aから辺を張る予定の頂点のリスト
      vector<int> to_follow;
      // 全ての頂点を順番に見る，見ている頂点をvとする
      rep(v, N) {
        if (graph[a][v]) {
          // さらにすべての頂点を順番に見る，見ている頂点をwとする
          rep(w, N) {
            if (graph[v][w] && w != a && v != a) {
              to_follow.push_back(w);
            }
          }
        }
      }
      // 最後に頂点aから張る
      rep(j, to_follow.size()) { graph[a][to_follow[j]] = true; }
    }
  }
  // 隣接行列を出力する
  rep(i, N) {
    rep(j, N) {
      if (graph[i][j]) {
        cout << "Y";
      } else {
        cout << "N";
      }
    }
    cout << endl;
  }
}