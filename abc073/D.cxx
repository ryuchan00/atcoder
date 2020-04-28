// https://atcoder.jp/contests/abc073/tasks/abc073_d

#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 200;
const int C_I_MAX = 100000;

int N, M, R;
int r[R_MAX];
int A[M_MAX];
int B[M_MAX];
int C[M_MAX];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d%d%d", &N, &M, &R);
  REP(i, R) scanf("%d", r + i);
  REP(i, M) scanf("%d%d%d", A + i, B + i, C + i);
}

int main() {
  input();
  solve();
  return 0;
}
