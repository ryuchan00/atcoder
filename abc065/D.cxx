// https://atcoder.jp/contests/abc065/tasks/arc076_b

#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 1e5;
const int X_I_MAX = 1e9;
const int Y_I_MAX = 1e9;

int N;
int x[N_MAX];
int y[N_MAX];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d", &N);
  REP(i, N) scanf("%d%d", x + i, y + i);
}

int main() {
  input();
  solve();
  return 0;
}
