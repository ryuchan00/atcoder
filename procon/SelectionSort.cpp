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

int selectionSort(int A[], int N) {
  int sw = 0, minj;
  for (int i = 0; i < N ; i++) {
    minj = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    if (i != minj) {
      swap(A[i], A[minj]);
      sw++;
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
  sw = selectionSort(A, N);

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