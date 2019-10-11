#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 100;
const int J_MAX = 100;
const int I_MAX = 2;

int N;
int A[2][N_MAX];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d", &N);
  REP(i, 2) REP(j, N) scanf("%d", &A[i][j]);
}

int main() {
  input();
  solve();
  return 0;
}
