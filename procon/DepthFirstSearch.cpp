#include <iostream>
#include <stack>
using namespace std;
static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[N][N];
int color[N], d[N], f[N], tt;
int nt[N];

// u に隣接する v を番号順に取得
int next(int u) {
  for (int v = nt[u]; v < n; v++) {
    nt[u] = v + 1;
    if (M[u][v]) return v;
  }
  return -1;
}

// スタックを用いた深さ優先探索
void dfs_visit(int r) {
  for (int i = 0; i < n; i++) nt[i] = 0;

  stack<int> S;
  S.push(r);
  color[r] = GRAY;
  d[r] = ++tt;

  while (!S.empty()) {
    int u = S.top();
    int v = next(u);
    if (v != -1) {
      if (color[v] == WHITE) {
        color[v] = GRAY;
        d[v] = ++tt;
        S.push(v);
      }
    } else {
      S.pop();
      color[u] = BLACK;
      f[u] = ++tt;
    }
  }
}

void dfs() {
  // 初期化
  for (int i = 0; i < n; i++) {
    color[i] = WHITE;
    nt[i] = 0;
  }
  tt = 0;

  // 未訪問の u を始点として深さ優先探索
  for (int u = 0; u < n; u++) {
    if (color[u] == WHITE) dfs_visit(u);
  }
  for (int i = 0; i < n; i++) {
    cout << i + 1 << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  int u, k, v;

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) M[i][j] = 0;
  }

  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    u--;
    for (int j = 0; j < k; j++) {
      cin >> v;
      v--;
      M[u][v] = 1;
    }
  }

  dfs();

  return 0;
}