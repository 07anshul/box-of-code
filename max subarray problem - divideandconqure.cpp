#include<bits/stdc++.h>
using namespace std;

int a[5];

int max_crossedarray(int A[], int l, int mid, int h) {
  int sum;
  int l_sum = INT_MIN;
  sum = 0;
  for (int i = mid; i>=l; i--) {
    sum += A[i];
    if (sum > l_sum) {
      l_sum = sum;
      a[0] = i;
    }
  }
  int r_sum = INT_MIN;
  sum = 0;
  for (int j = (mid+1); j <= h; j++) {
    sum += A[j];
    if (sum > r_sum) {
      r_sum = sum;
      a[1] = j;
    }
  }
  int c_sum = l_sum + r_sum;
return c_sum;
}

int max_subarray_divideandconqure(int A[], int l, int h) {

  if (l == h) {
    return A[l];
  }
  int mid = (l+h)/2;
  int l_sum = max_subarray_divideandconqure(A, l, mid);
  int r_sum = max_subarray_divideandconqure(A, mid+1, h);
  int c_sum = max_crossedarray(A, l, mid, h);

  if (l_sum >= r_sum && l_sum >= c_sum) {
    a[0] = l;
    a[1] = mid;
    return l_sum;
  }
  else if (r_sum >= l_sum && r_sum >= c_sum) {
    a[0] = mid+1;
    a[1] = h;
    return r_sum;
  }
  else {

    return c_sum;
  }
}

int main() {

  int A[] = {-2, -1, 6, -2, 8, -4};
  int n = sizeof(A)/sizeof(A[0]);
  int l = 0;
  int h = n-1;

int max_sum =  max_subarray_divideandconqure(A, l, h);
cout << a[0] << " - " << a[1] << " " << max_sum << "\n";
}
