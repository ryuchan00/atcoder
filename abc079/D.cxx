#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int HW_MAX = 200;
const int C_IJ_MAX = 1000;
const int A_IJ_MAX = 9;

int H, W;
int c[9][9];
int A[H_MAX][W_MAX];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d%d", &H, &W);
  REP(i, 9) REP(j, 9) scanf("%d", &c[i][j]);
  REP(i, H) REP(j, W) scanf("%d", &A[i][j]);
}

int main() {
  input();
  solve();
  return 0;
}
