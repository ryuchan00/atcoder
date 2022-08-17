#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node {
  int p, l, r;
};

Node T[MAX];
int n, D[MAX];

void print(int u) {
  int i, c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p << ": ";
  cout << "depth " << D[u] << ", ";

  if(T[u].p == NIL) cout << ""
}