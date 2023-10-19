#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))
using ll = long long;
using ii = pair<ll, ll>;

// 愚直な処理なのでタイムオーバーになる

int main() {
  long long N;
  cin >> N;

  vector<long long> C(N);
  rep(i, N) {
    cin >> C[i];
  }

  long long Q;
  cin >> Q;

  // 合計販売枚数を記録する変数
  long sell = 0;

  // 全種類販売の場合
  long long z = 0;

  // セット販売で販売した1種類あたりの枚数
  long long s = 0;

  // セット販売対象のCの最小値を記録する変数
  long long min_s_C = 1000000000;

  // セット販売対象でないCの最小値を記録する変数
  long long min_z_C = 1000000000;

  rep(i, N) {
    if (i % 2 == 0) {
      min_s_C = min(C[i], min_s_C);
    } else {
      min_z_C = min(C[i], min_z_C);
    }
  }

  rep(_, Q) {
    int query, x, a;
    cin >> query;

    if (query == 1) {
      // 単品販売
      cin >> x >> a;
      x--;

      long long card_x = 0;
      if (x % 2 == 0) {
        // セット販売対象のカードの場合
        card_x = C[x] - z - s;
      } else {
        // セット販売対象のカードでない場合
        card_x = C[x] - z;
      }

      // カードxがa枚以上残っていればa枚売る
      if (card_x >= a) {
        C[x] -= a;
        sell += a;

        if (x % 2 == 0) {
          min_s_C = min(C[x], min_s_C);
        } else {
          min_z_C = min(C[x], min_z_C);
        }
      }
    }
    if (query == 2) {
      // セット販売
      cin >> a;

      // 販売可能かどうか記録する変数
      // bool ok = true;

      // i%2==0となる全てのiについて，カードiがa枚以上あるか調べる
      // (インデックスは入力からマイナス1してるから)
      // a枚未満のカードがある場合，販売不可能とする
      // rep(i, N) {
      //   if (i % 2 == 0 && C[i] < a) {
      //     ok = false;
      //   }
      // }
      if ((min_s_C - s - z) >= a) {
        s += a;
      }
      // if (ok) {
      //   // 販売可能だった場合，a枚ずつ売る
      //   rep(i, N) {
      //     if (i % 2 == 0) {
      //       C[i] -= a;
      //       sell += a;
      //     }
      //   }
      // }
    }
    if (query == 3) {
      // 全種類販売の場合
      cin >> a;

      // 販売可能かどうかを記録する変数
      // bool ok = true;

      // 全てのiについて，カードiがa枚以上であるかどうか調べる
      // a枚未満のカードがある場合，販売不可能とする
      // rep(i, N) {
      //   if (C[i] < a) {
      //     ok = false;
      //   }
      // }
      // // 販売可能だった場合，a枚ずつ売る
      // if (ok) {
      //   rep(i, N) {
      //     C[i] -= a;
      //     sell += a;
      //   }
      // }
      if (min(min_s_C - s - z, min_z_C - z) >= a) {
        z += a;
      }
    }
  }
  // セット販売した商品を合算する
  rep(i, N) {
    if (i % 2 == 0) {
      sell += s;
    }
  }
  // cout << sell + s * ((N + 1) / 2) + z * N << endl;
  sell += z * N;
  cout << sell << endl;
}