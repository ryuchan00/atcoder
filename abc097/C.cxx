#include <cstdio>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int S_MAX = 5000;
const int K_MAX = 5;

char s[S_MAX + 1];
int K;

void solve() {
  int ans = 0;
  printf("%d\n", ans);
}

void input() {
  scanf("%s", s);
  scanf("%d", &K);
}

int main() {
  input();
  solve();
  return 0;
}
