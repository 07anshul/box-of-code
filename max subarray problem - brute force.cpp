#include<bits/stdc++.h>
using namespace std;

void max_subarray_bruteforce(int A[], int n) {

  int sum, l, h, max_subarray_sum = 0;

  for (int i = 0; i < n-1; i++) {
    sum = A[i];
    for (int j = i+1; j < n; j++) {
      sum += A[j];

      if (sum > max_subarray_sum) {
        max_subarray_sum = sum;
        l = i;
        h = j;
      }
    }
  }

  cout << max_subarray_sum << " " << l << " " << h << "\n";
}

int main() {

  int A[] = {0, 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
  int n = sizeof(A)/sizeof(A[0]);

  max_subarray_bruteforce(A, n);
}
