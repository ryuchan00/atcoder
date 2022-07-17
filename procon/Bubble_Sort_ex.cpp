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
  int sw = 0;
  bool flag = 1;
  for (int i = 0; flag; i++) {
    flag = 0;
    for (int j = N - 1; j >= i; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        flag = 1;
        sw++;
      }
    }
  }
  return sw;
}

int main() {
  int A[100], N, sw;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sw = bubbleSort(A, N);

  for (int i = 0; i < N; i++) {
    if (i) {
      cout << " ";
    }
    cout << A[i];
  }

  cout << endl;
  cout << sw << endl;
  return 0;
}