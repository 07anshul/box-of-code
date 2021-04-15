#include<bits/stdc++.h>
using namespace std;

int  partition(int A[], int l, int r) {
  int piviot = A[r];
  int swap_i = l;

  for (int i = l; i < r; i++) {
    if (A[i] <= piviot) {
      // Swap
      int temp = A[i];
      A[i] = A[swap_i];
      A[swap_i] = temp;
      swap_i++;
    }
  }
  int temp = A[r];
  A[r] = A[swap_i];
  A[swap_i] = temp;

  return swap_i;
}

void quick_sort(int A[], int l, int r) {
  if (l >= r) {
    return;
  }
  int swap_i = partition(A, l, r);
  quick_sort(A, l, swap_i-1);
  quick_sort(A, swap_i+1, r);

}

int main() {
  int n;
  cin >> n;

  int A[n];

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int l = 0;
  int r = n-1;

  quick_sort(A, l, r);

  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << "\n";
}
