#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 100000;
const int M_MAX = 200000;
const int D_I_MAX = 10000;

int N, M;
int L[M_MAX];
int R[M_MAX];
int D[M_MAX];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d%d", &N, &M);
  REP(i, M) scanf("%d%d%d", L + i, R + i, D + i);
}

int main() {
  input();
  solve();
  return 0;
}
