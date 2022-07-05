#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A.at(i);
  }

  bool end_flag = false;
  int cnt = 0;
  while (!end_flag) {
    for (int i = 0; i < n; i++) {
      if ((A.at(i) % 2 != 0) || (A.at(i) == 0)) {
        end_flag = true;
        break;
      }
      A.at(i) = A.at(i) / 2;
    }
    if (!end_flag) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}