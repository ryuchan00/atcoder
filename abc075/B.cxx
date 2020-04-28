// https://atcoder.jp/contests/abc075/tasks/abc075_b

#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int H_MAX = 50;
const int W_MAX = 50;

int H, W;
char S[H_MAX][S_MAX + 1];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d%d", &H, &W);
  REP(i, H) scanf("%s", S[i]);
}

int main() {
  input();
  solve();
  return 0;
}
