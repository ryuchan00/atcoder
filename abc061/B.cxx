// https://atcoder.jp/contests/abc061/tasks/abc061_b

#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 50;
const int M_MAX = 50;

int N, M;
int a[M_MAX];
int b[M_MAX];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d%d", &N, &M);
  REP(i, M) scanf("%d%d", a + i, b + i);
}

int main() {
  input();
  solve();
  return 0;
}
