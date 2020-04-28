// https://atcoder.jp/contests/abc073/tasks/abc073_b

#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 1000;
const int R_I_MAX = 100000;

int N;
int l[N_MAX];
int r[N_MAX];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d", &N);
  REP(i, N) scanf("%d%d", l + i, r + i);
}

int main() {
  input();
  solve();
  return 0;
}
