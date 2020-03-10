// https://atcoder.jp/contests/abc071/tasks/arc081_b

#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 52;
const int MOD = 1000000007;

int N;
char S[2][S_MAX + 1];

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%d", &N);
  REP(i, 2) scanf("%s", S[i]);
}

int main() {
  input();
  solve();
  return 0;
}
