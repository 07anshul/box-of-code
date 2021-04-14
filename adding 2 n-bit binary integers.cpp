#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, i;
  cin >> n;
  int a[n], b[n], c[n+1] = {0};
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
  }
  int carry = 0;
  for (i = n-1; i >= 0; i--) {
    if (a[i] == 1 && b[i] == 1) {
      if (carry == 1) {
        c[i+1] = 1;
      }
      else {
        c[i+1] = 0;
      }
      carry = 1;
    }
    else if (a[i] == 1 || b[i] == 1) {
      if (carry == 1) {
        c[i+1] = 0;
      }
      else {
        c[i+1] = 1;
      }
    }
    else {
      c[i+1] = carry;
      carry = 0;
    }
    if (i == 0 && carry == 1) {
      c[i] = 1;
    }
  }

  for (i = 0; i <= n; i++) {
    cout << c[i] << " ";
  }
  cout << "\n";
}
