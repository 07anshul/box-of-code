#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a[10] = {2, 45, 3, 65, 23, 65, 12, 44, 11, 98};
  int min, i, j, temp;

  for (i = 0; i < 10-1; i++) {
    min = i;
    for (j = i+1; j < 10; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    temp = a[i];
    a[i] = a[min];
    a[min] = temp;
  }

  for (i = 0; i < 10; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
