// https://atcoder.jp/contests/abc075/tasks/abc075_d

#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 50;
const int X_I_MAX = 1e9;
const int Y_I_MAX = 1e9;

int N, K;
int x[N_MAX];
int y[N_MAX];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d%d", &N, &K);
  REP(i, N) scanf("%d%d", x + i, y + i);
}

int main() {
  input();
  solve();
  return 0;
}
