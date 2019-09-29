#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 12;
const int M_MAX = 1000;
const int A_I_MAX = 100000;

int N, M;
int a[1];
int b[1];
int aM, bM;

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d%d", &N, &M);
  REP(i, 1) scanf("%d%d", a + i, b + i);
  scanf("%d%d", &aM, &bM);
}

int main() {
  input();
  solve();
  return 0;
}
