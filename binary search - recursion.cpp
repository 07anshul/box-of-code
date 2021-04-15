#include<bits/stdc++.h>
using namespace std;

void  binary_search(int a[], int l, int r, int s) {

  int mid = ((r+1)/2) + ((l+1)/2);
  if (a[mid] == s) {
    cout << " >> Is located at index " << mid << "\n";
    return;
  }
  else if (mid == r) {
      cout << " >> Searched element is not present in the list\n";
      return;
  }
  else if (s < a[mid]) {
    binary_search(a, l, mid-1, s);
  }
  else  if (s > a[mid]) {
    binary_search(a, mid, r, s);
  }




}

int main() {
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int l = 0;
  int r = n-1;

  sort(a, a+(n));

  int s;
  cin >> s;

  binary_search(a, l, r, s);
}
