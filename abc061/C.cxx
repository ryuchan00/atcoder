// https://atcoder.jp/contests/abc061/tasks/abc061_c

#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 1e5;
const int A_I_MAX = 1e5;
const int B_I_MAX = 1e5;

int N, K;
int a[N_MAX];
int b[N_MAX];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d%d", &N, &K);
  REP(i, N) scanf("%d%d", a + i, b + i);
}

int main() {
  input();
  solve();
  return 0;
}
