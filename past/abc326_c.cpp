#include <bits/stdc++.h>
using namespace std;
int n, m, a[300005], maxn;
queue<int> q;
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    q.push(a[i]);
    // お尻のほうを基準にする
    while (a[i] - m >= q.front()) {
      q.pop();
    }
    maxn = max(maxn, (int)q.size());
  }
  cout << maxn << endl;
  return 0;
}