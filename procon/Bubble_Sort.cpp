#include <algorithm>
#include <iostream>
using namespace std;

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

void insertionSort(int A[], int N) {
  int j, i, v;
  for (i = 1; i < N; i++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    trace(A, N);
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

int main() {
  int N, i, j;
  int A[100];

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  int count = bubbleSort(A, N);
  trace(A, N);
  cout << count << endl;

  return 0;
}