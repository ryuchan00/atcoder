#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

long long cnt;
int l;
int A[1000000];
int n;
vector<int> G;

void trace(int A[], int N) {
  int i;
  for (i = 0; i < N; i++) {
    if (i > 0) {
      printf(" ");
    }
    printf("%d", A[i]);
  }
  printf("\n");
}

void insertionSort(int A[], int N, int g) {
  int j, i, v, cng;
  for (i = g; i < N; i++) {
    v = A[i];
    j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j + g] = v;
  }
}

int bubbleSort(int A[], int N) {
  bool flag = true;
  int count = 0;
  while (flag) {
    flag = false;
    for (int j = (N - 1); 0 < j; j--) {
      if (A[j] < A[j - 1]) {
        int tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
        flag = true;
        count++;
      }
    }
  }
  return count;
}

int shellSort(int A[], int N) {
  //vector<int> G = {1, 4, 13, 40, 121, 364, 1093};を生成
  for (int h = 1;;) {
    if (h > n) break;
    G.push_back(h);
    h = 3 * h + 1;
  }

  for (int i = G.size() - 1; i >= 0; i--) {
    insertionSort(A, n, G[i]);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);
  cnt = 0;

  shellSort(A, n);

  cout << G.size() << endl;
  for (int i = G.size() - 1; i >= 0; i--) {
    printf("%d", G[i]);
    if (i) printf(" ");
  }
  printf("\n");
  printf("%d\n", cnt);
  for (int i = 0; i < n; i++) printf("%d\n", A[i]);
  
  return 0;
}