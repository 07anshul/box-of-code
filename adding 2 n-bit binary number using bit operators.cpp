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

    if (carry == 1) {
      c[i+1] = (a[i]^b[i])^carry;
      carry = ((a[i]|b[i])&carry);
    }
    else {
      c[i+1] = a[i]^b[i];
      carry = a[i]&b[i];
    }
  }
  c[0] = carry;

  for (i = 0; i <= n; i++) {
    cout << c[i] << " ";
  }
  cout << "\n";
}
