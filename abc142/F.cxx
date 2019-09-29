#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 1000;
const int M_MAX = 2000;

int N, M;
int A[M_MAX];
int B[M_MAX];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d%d", &N, &M);
  REP(i, M) scanf("%d%d", A + i, B + i);
}

int main() {
  input();
  solve();
  return 0;
}
