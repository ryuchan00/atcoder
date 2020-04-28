// https://atcoder.jp/contests/abc092/tasks/abc092_b

#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 100;
const int D_MAX = 100;
const int X_MAX = 100;
const int A_I_MAX = 100;

int N;
int D, X;
int A[N_MAX];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d", &N);
  scanf("%d%d", &D, &X);
  REP(i, N) scanf("%d", A + i);
}

int main() {
  input();
  solve();
  return 0;
}
