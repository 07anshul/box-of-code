#include<bits/stdc++.h>
using namespace std;

void bruteforce(int A[], int n) {
int sum, l, h, max_profit = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {

      sum = A[j] - A[i];
      if (sum > max_profit) {
        max_profit = sum;
        l = i;
        h = j;
      }
    }
  }

  cout << max_profit << " " << l << " " << h;
}

int main() {
  int A[] = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
  int n = sizeof(A)/sizeof(A[0]);

  bruteforce(A, n);

}
