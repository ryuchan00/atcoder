#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))

// 愚直な処理なのでタイムオーバーになる

int main() {
  int N;
  cin >> N;

  vector<int> C(N);
  rep(i, N) {
    cin >> C[i];
  }

  int Q;
  cin >> Q;

  // 合計販売枚数を記録する変数
  int sell = 0;

  rep(_, Q) {
    int query, x, a;
    cin >> query;

    if (query == 1) {
      // 単品販売
      cin >> x >> a;
      x--;

      // カードxがa枚以上残っていればa枚売る
      if (C[x] >= a) {
        C[x] -= a;
        sell += a;
      }
    }
    if (query == 2) {
      // セット販売
      cin >> a;

      // 販売可能かどうか記録する変数
      bool ok = true;

      // i%2==0となる全てのiについて，カードiがa枚以上あるか調べる
      // (インデックスは入力からマイナス1してるから)
      // a枚未満のカードがある場合，販売不可能とする
      rep(i, N) {
        if (i % 2 == 0 && C[i] < a) {
          ok = false;
        }
      }
      if (ok) {
        // 販売可能だった場合，a枚ずつ売る
        rep(i, N) {
          if (i % 2 == 0) {
            C[i] -= a;
            sell += a;
          }
        }
      }
    }
    if (query == 3) {
      // 全種類販売の場合
      cin >> a;

      // 販売可能かどうかを記録する変数
      bool ok = true;

      // 全てのiについて，カードiがa枚以上であるかどうか調べる
      // a枚未満のカードがある場合，販売不可能とする
      rep(i, N) {
        if (C[i] < a) {
          ok = false;
        }
      }
      // 販売可能だった場合，a枚ずつ売る
      if (ok) {
        rep(i, N) {
          C[i] -= a;
          sell += a;
        }
      }
    }
  }
  cout << sell << endl;
}