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
  int X, Y;
  cin >> X >> Y;

  if (X < Y && abs(X - Y) > 2) {
    cout << "No" << endl;
  } else if (X > Y && abs(X - Y) > 3) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}