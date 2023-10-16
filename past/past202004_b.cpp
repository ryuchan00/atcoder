#include <bits/stdc++.h>

#include <algorithm>
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
  if (c_a > c_b && c_a > c_c) {
    cout << "a" << endl;
  } else if (c_b > c_a && c_b > c_c) {
    cout << "b" << endl;
  } else if (c_c > c_a && c_c > c_b) {
    cout << "c" << endl;
  }
  // 値が 1 の要素がいくつあるかを数える
  // std::cout << a.begin() << '\n';
  // [0, 10)を回す
  // rep(i, 10) {
  //   cout << i << '\n';
  // }
}