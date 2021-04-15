#include<bits/stdc++.h>
using namespace std;

void str_reduce(string A, int l) {
  string n;
  int j = 1;
  (A[0] != A[1] ? n[0] = A[0] : false);

  for (int i = 1; i < l-1; i++) {
    if (A[i] == A[i-1] || A[i] == A[i+1]) {
      continue;
    }
    else {
      n[j] = A[i];
      j++;
    }
  }

  (A[l-1] != A[l-2] ? n[j] = A[l-1] : false);

  for (int i = 0; n[i] != '\0'; i++) {
    cout << n[i] << " ";
  }
  cout << "\n";
}

int main() {
  string A;
  cin >> A;

  int l = A.length();

  str_reduce(A, l);
}
