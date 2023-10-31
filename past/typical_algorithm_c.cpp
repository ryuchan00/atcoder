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

// https://atcoder.jp/contests/past201912-open/tasks/past201912_g

int main() {
  ll N;
  cin >> N;

  vector<vector<ll>> A(N);
  rep(i, N) {
    rep(j, N) {
      ll a;
      cin >> a;
      A[i].push_back(a);
    }
  }

  ll ALL = 1 << N;

  // const[n][i]:訪れた都市の集合がnで，最後に訪れた都市がiであるときのコスト最小値
  vector<vector<ll>> cost(ALL, vector<ll>(N, 1e18));

  // 初期条件
  cost[0][0] = 0;

  rep(n, ALL) {
    rep(i, N) {
      // iからjに移動する遷移を試す
      // i->jへの都市の移動
      rep(j, N) {
        // すでに訪問済みか，同じ都市は無視する(=0のため)
        if (has_bit(n, j) || i == j) {
          continue;
        }
        cost[(n | 1 << j)][j] = min(cost[(n | 1 << j)][j], cost[n][i] + A[i][j]);
      }
    }
  }

  // 全都市を訪問して始点に戻っていくる最小コストが答え
  cout << cost[ALL - 1][0] << endl;
}
