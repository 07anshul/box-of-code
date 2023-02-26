#include<bits/stdc++.h>
using namespace std;

int arr[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};


int func(int *arr, int n) {
  if (n == 0) {
    return arr[0];
  }

  int q = INT_MIN;

  for (int i = 1; i <= n; i++) {
    q = max(q, arr[i] + arr[n-i]);
  }

  return q;
}


int main() {
  // int arr[11] = {0, 1, 5, 10, 9, 10, 17, 17, 20, 24, 30};

  int n = 4;

  cout << func(arr, n);
}
