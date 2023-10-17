#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))

int main() {
  string a;

  cin >> a;
  int c_a = std::count(a.begin(), a.end(), 'a');
  int c_b = std::count(a.begin(), a.end(), 'b');
  int c_c = std::count(a.begin(), a.end(), 'c');
  // maxはめっちゃおそいな
  int mx = max({c_a, c_b, c_c});
  if (mx == c_a) {
    cout << "a" << endl;
  } else if (mx == c_b) {
    cout << "b" << endl;
  } else if (mx == c_c) {
    cout << "c" << endl;
  }
  // 値が 1 の要素がいくつあるかを数える
  // std::cout << a.begin() << '\n';
  // [0, 10)を回す
  // rep(i, 10) {
  //   cout << i << '\n';
  // }
}