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

vector<vector<int>> edges;
vector<bool> done;
vector<int> length;

// メモ化再帰の実装
int rec(int i) {
  // 計算済みであれば，即座に値を返す
  if (done[i]) {
    return length[i];
  }
  // そうでなければ値を計算する
  length[i] = 0;
  for (const auto& j : edges[i]) {
    length[i] = max(length[i], rec(j) + 1);
  }
  done[i] = true;
  return length[i];
}

int main() {
  int N, M;
  cin >> N >> M;

  // edges[i]: 頂点iから辺が伸びている頂点たち
  edges = vector<vector<int>>(N);

  // 入次数，始点の判定に使う
  int indeg[N];
  rep(i, N) {
    indeg[i] = 0;
  }

  // 辺の入力を受け取り，隣接リストを作る
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    edges[x - 1].push_back(y - 1);
    indeg[y - 1]++;
  }

  // length[i]: 頂点iから始まるパスの最大長
  length = vector<int>(N);
  // done[i]:cost[i]がすでに計算済みであることを表すフラグ
  done = vector<bool>(N);

  // 始点すべてについてrecを呼び出す
  rep(i, N) {
    if (indeg[i] == 0) {
      rec(i);
    }
  }

  // lengthの最大値が答え
  cout << *max_element(length.begin(), length.end()) << endl;
}