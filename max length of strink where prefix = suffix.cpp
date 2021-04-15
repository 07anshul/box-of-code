#include<bits/stdc++.h>
using namespace std;

int max_length(string s, int mid) {
int j = 0;
  for (int i = mid+1; s[i] != '\0'; i++) {
    if (s[j] == s[i]) {
      j++;
    }
    else if (s[j-1] == s[i]) {
      continue;
    }
    else {
      j = 0;
    }
  }
  return j;
}

int main() {
  string s;
  cin >> s;

  int l = s.length();
  int mid = (l-1)/2;

  int max = max_length(s, mid);

  cout << " >> Maximum length of the string which is prefix and suffix itself = " << max << "\n";
}
