#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 100000;
const int M_MAX = 100000;

int N, M;
int p[N_MAX];
int x[M_MAX];
int y[M_MAX];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d%d", &N, &M);
  REP(i, N) scanf("%d", p + i);
  REP(i, M) scanf("%d%d", x + i, y + i);
}

int main() {
  input();
  solve();
  return 0;
}
