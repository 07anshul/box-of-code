#include<bits/stdc++.h>
using namespace std;

void merge(int S[], int L[], int R[], int n1, int n2) { // merging

  int i = 0;
  int j = 0;

  for (int k = 0; k < (n1+n2); k++) {
    if (i == n1) {
      while (j < n2) {
        S[k] = R[j];
        j++;
        k++;
      }
      break;
    }
    else if (j == n2) {
      while (i < n1) {
        S[k] = L[i];
        i++;
        k++;
      }
      break;
    }
    if (L[i] <= R[j]) {
      S[k] = L[i];
       i++;
    }
    else {
      S[k] = R[j];
      j++;
    }
  }

  for (int i = 0; i < (n1+n2); i++) {
    cout << S[i] << " ";
  }
  cout << "\n";
}

void merge_sort(int S[], int n) { // divide
  if (n < 2) {
    return;
  }
  int mid = n/2;
  int n1 = mid;
  int  n2 = n-mid;
  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = S[i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = S[mid];
    mid++;
  }

  merge_sort(L, n1);
  merge_sort(R, n2);
  merge(S, L, R, n1, n2);
}


int main() {
  int n;
  int S[] = {3, 41, 52, 26, 38, 57, 9, 49};

  n = sizeof(S)/sizeof(S[0]);

  merge_sort(S, n);


}
