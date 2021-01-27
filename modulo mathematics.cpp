#include<bits/stdc++.h>
using namespace std;

int print_power(int &a, int &b, int &m) {

int result = 1;
  while (b > 0) {
    if ((b&1) != 0) {
      result = (result*a%m)%m;
    }
    a = (a%m * a%m)%m;
    b = b>>1;
  }
  return result;
}

int main() {

int a, b, m;

cin >> a >> b >> m;

  cout << print_power(a, b, m) << "\n";
}
