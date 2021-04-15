#include<bits/stdc++.h>
using namespace std;

int subsets(int A[], int curr, int r) {
  if (curr == r) {
    return;
  }

  
}

int main() {
  int n;
  cin >> n;
  int A[n];

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int curr = 0;
  int r = (sizeof(A)/sizeof(A[0])) - 1;

  subsets(A, curr, r);
}
