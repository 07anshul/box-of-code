#include<bits/stdc++.h>
using namespace std;

int a[2];

int linear_fun(int A[], int n) {
  int sum = INT_MIN;
  int end_sum = 0;

  for (int i = 0; i < n; i++) {
    end_sum += A[i];
    if (end_sum > sum) {
      sum = end_sum;
      a[1] = i;
    }
    if (end_sum < 0) {
      end_sum = 0;
      a[0] = i+1;
    }
  }

  return sum;
}

int main() {
  int A[] = {-2, -3, 4, -1, -23, 1, 5, -3};
  int n = sizeof(A)/sizeof(A[0]);

  int max_sub = linear_fun(A, n);

  cout << a[0] << " - " << a[1] << " " << max_sub << "\n";
}
