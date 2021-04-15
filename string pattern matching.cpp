#include<bits/stdc++.h>
using namespace std;

void compare(string str, string pat) {
  int pat_len = pat.length();
  for (int i = 0; str[i] != '\0'; i++) {
    int temp = i;
      for (int j = 0; pat[j] != '\0'; j++) {
        if (str[i] == pat[j]) {
          i++;
          if (j == pat_len-1) {
            cout << "Pattern at index " << temp << "\n";
            i = temp;
            break;
          }
        }
        else {
          i = temp;
          break;
        }
      }
  }
}

int main() {
  string str, pat;
  getline(cin, str); 
  cin >> pat;

  compare(str, pat);

}
