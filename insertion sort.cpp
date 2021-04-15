#include<bits/stdc++.h>
using namespace std;

int main() {
  int a[6] = {31, 41, 59, 26, 41, 58};
  int i, j, temp, swap;

  for (i = 0; i < 6-1; i++) {
    temp = i;
    for (j = i+1; a[j] > a[i]; j--) {
      swap = a[j];
      a[j] = a[i];
      a[i] = swap;
       i--;
    }
    i = temp;
  }

  for (i = 0; i < 6; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
