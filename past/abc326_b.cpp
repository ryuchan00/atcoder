#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))

int main() {
  int N;
  cin >> N;

  // cout << stoi(N.substr(0, 1)) << endl;
  int i = N;
  while (true) {
    std::string s = std::to_string(i);
    int s1 = stoi(s.substr(0, 1));
    int s2 = stoi(s.substr(1, 1));
    int s3 = stoi(s.substr(2, 1));
    if (s1 * s2 == s3) {
      cout << i << endl;
      return 0;
    }
    i++;
  }
}