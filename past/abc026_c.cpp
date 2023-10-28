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

vector<vector<int>> child;

// 再起関数を定義する
// dfs(i): 頂点iの子の給料を全て求め，自信の給料を計算して返す
int dfs(int i) {
  // 子がいなければ給料は1
  if (child[i].size() == 0) {
    return 1;
  } else {
    vector<int> values;
    for (const auto &j : child[i]) {
      // 頂点iの子の給料を求める
      values.push_back(dfs(j));
    }
    auto max = max_element(values.begin(), values.end());
    auto min = min_element(values.begin(), values.end());
    return *max + *min + 1;
  }
}

int main() {
  int N;
  cin >> N;
  rep(i, N) { child.push_back(vector<int>()); }

  // child[i]:頂点iの子(部下)となる頂点たち
  for (int i = 1; i < N; i++) {
    int b;
    cin >> b;
    b--;
    child[b].push_back(i);
  }
  cout << dfs(0) << endl;
}