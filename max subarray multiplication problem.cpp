#include<bits/stdc++.h>
using namespace std;

int max_subarray_mul(int A[], int n) {
  int max_sum = 0;
  int flag = 0;

  int max_ending = 1;
  int min_ending = 1;

  for (int i = 0; i < n; i++) {

    if (A[i] > 0) {
      max_ending *= A[i];
      min_ending = min(min_ending * A[i], 1);
      flag = 1;
    }

    if (A[i] == 0) {
      max_sum = 0;
      max_ending = 1;
      min_ending = 1;
    }

    if (A[i] < 0) {
      int temp = max_ending;
      max_ending = max(min_ending * A[i], 1);
      min_ending = temp * A[i];
    }

    if (max_ending > max_sum) {
      max_sum = max_ending;
    }
  }
  if (max_sum == 0 && flag == 0) {
    return 0;
  }
  return max_sum;
}

int main() {
  int A[] = {1, 2, -12, 1, 6, -2, 8, -34};
  int n = sizeof(A)/sizeof(A[0]);

  int max = max_subarray_mul(A, n);
  cout << max << "\n";
}
