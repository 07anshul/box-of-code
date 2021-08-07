#include<bits/stdc++.h>
using namespace std;

string check(vector<string> &str, int x) {
  string output = "", result = "";

  output = str[0];

  for (int i = 1; i < int(str.size()); i++) {
    if (output[0] != str[i][0]) {
      output = "";
      break;
    }
    result = "";
    for (int j = 0; j < max(int(output.length()), int(str[i].size())); j++) {
      if (output[j] == str[i][j]) {
        result += str[i][j];
      }
      else {
        break;
      }
    }
    output = result;
  }

  return output;
}

int main() {
  vector<string> str;
  string input;
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> input;
    str.push_back(input);
  }

  cout << check(str, x) << "\n";
}
